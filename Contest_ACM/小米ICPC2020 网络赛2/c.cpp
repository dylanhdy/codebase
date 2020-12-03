#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM 
#define P
#define INF 1e18;
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define ls (root<<1)
#define rs (root<<1|1)
using namespace std;

int n, m;
LL a[MAXN], b[MAXN], c[MAXN], d[MAXN];

struct Segtree
{
    LL t[MAXN<<2], tag[MAXN<<2];

    void up(int root)
    {
        t[root]=max(t[ls], t[rs]);
    }

    void down(int root, int l, int r)
    {
        t[ls]+=tag[root];
        t[rs]+=tag[root];
        tag[ls]+=tag[root];
        tag[rs]+=tag[root];
        tag[root]=0;
    }

    void build(int root, int l, int r, LL val[])
    {
        tag[root]=0;
        if(l==r)
        {
            t[root]=val[l];
            return;
        }
        build(ls, l, mid, val);
        build(rs, mid+1, r, val);
        up(root);
    }

    void update(int root, int l, int r, int x, int y, LL k)
    {
        if(l>y || r<x) return;
        if(l>=x && r<=y)
        {
            tag[root]+=k;
            t[root]+=k;
            return;
        }
        down(root, l, r);
        update(ls, l, mid, x, y, k);
        update(rs, mid+1, r, x, y, k);
        up(root);
    }

    LL query(int root, int l, int r, int x, int y)
    {
        if(l>y || r<x) return -INF;
        if(l>=x && r<=y) return t[root];
        down(root, l, r);
        return max(query(ls, l, mid, x, y), query(rs, mid+1, r, x, y));
    }
} f, g;

int main()
{
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        for(int i=1; i<=n; ++i) scanf("%lld", &a[i]);
        for(int i=1; i<=n; ++i)
        {
            scanf("%lld", &b[i]);
            c[i]=b[i]+c[i-1];
            d[i]=a[i]-c[i];
        }
        f.build(1, 1, n, c);
        g.build(1, 1, n, d);
        for(int i=1; i<=m; ++i)
        {
            int op, x, y;
            scanf("%d", &op);
            if(op==1)
            {
                scanf("%d%d", &x, &y);
                g.update(1, 1, n, x, x, y-a[x]);
                a[x]=y;
            }
            if(op==2)
            {
                scanf("%d%d", &x, &y);
                f.update(1, 1, n, x, n, y-b[x]);
                g.update(1, 1, n, x, n, b[x]-y);
                b[x]=y;
            }
            if(op==3)
            {
                scanf("%d", &x);
                LL temp=max((LL)0, g.query(1, 1, n, 1, x));
                printf("%lld\n", temp+f.query(1, 1, n, x, x));
            }
        }
    }
}