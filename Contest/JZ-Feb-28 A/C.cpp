#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 30005
#define P 998244353
#define INF 0x7fffffff
#define rint register int
#define LL long long
#define LD long double
#define ls (root<<1)
#define rs (root<<1|1)
#define mid ((l+r)>>1)
using namespace std;

int T, n, m, X1, X2, Y1, Y2, ans[MAXN], x[MAXN], y[MAXN], t[MAXN];

struct Act {int op, l, r, d;} a[MAXN];
struct Seg
{
    int pos[MAXN*4], t[MAXN*4], tag[MAXN*4];

    void up(int root)
    {
        if(t[ls]>t[rs]) t[root]=t[ls], pos[root]=pos[ls];
        else t[root]=t[rs], pos[root]=pos[rs];
    }

    void down(int root)
    {
        tag[ls]+=tag[root];
        tag[rs]+=tag[root];
        t[ls]+=tag[root];
        t[rs]+=tag[root];
        tag[root]=0;
    }

    void build(int root, int l, int r, int lx, int ly, int op)
    {
        tag[root]=t[root]=pos[root]=0;
        if(l==r)
        {
            pos[root]=l;
            if(x[l]<=lx && y[l]<=ly) t[root]=op?y[l]:x[l];
            else t[root]=-INF;
            return;
        }
        build(ls, l, mid, lx, ly, op);
        build(rs, mid+1, r, lx, ly, op);
        up(root);
    }

    void update(int root, int l, int r, int x, int y, int k)
    {
        if(l>y || r<x) return;
        if(l>=x && r<=y)
        {
            tag[root]+=k;
            t[root]+=k;
            return;
        }
        down(root);
        update(ls, l, mid, x, y, k);
        update(rs, mid+1, r, x, y, k);
        up(root);
    }

    void del(int root, int l, int r, int x)
    {
        if(l==r)
        {
            t[root]=-INF;
            return;
        }
        down(root);
        if(x<=mid) del(ls, l, mid, x);
        else del(rs, mid+1, r, x);
        up(root);
    }
} t1, t2;

void add(int x, int y)
{
    for(; x<=n; x+=(x&-x)) t[x]+=y;
}

int ask(int x)
{
    int sum=0;
    for(; x; x-=(x&-x)) sum+=t[x];
    return sum;
}

void solve(int lx, int ly, int op)
{
    memset(t, 0, sizeof(t));
    t1.build(1, 1, n, lx, ly, 0);
    t2.build(1, 1, n, lx, ly, 1);
    for(rint i=1; i<=n; ++i)
        if(x[i]<=lx && y[i]<=ly) add(i, 1);
    for(rint i=1; i<=m; ++i)
    {
        if(a[i].op==1)
        {
            t1.update(1, 1, n, a[i].l, a[i].r, a[i].d);
            while(t1.t[1]>lx)
            {
                //printf("%d!!!\n", t1.pos[1]);
                add(t1.pos[1], -1);
                t2.del(1, 1, n, t1.pos[1]);
                t1.del(1, 1, n, t1.pos[1]);
            }
        }
        if(a[i].op==2)
        {
            t2.update(1, 1, n, a[i].l, a[i].r, a[i].d);
            while(t2.t[1]>ly)
            {
                //printf("%d!!!\n", t2.pos[1]);
                add(t2.pos[1], -1);
                t1.del(1, 1, n, t2.pos[1]);
                t2.del(1, 1, n, t2.pos[1]);
            }
        }
        if(a[i].op==3) ans[i]+=op*(ask(a[i].r)-ask(a[i].l-1));
    }
}

int main()
{
    //freopen("fish0.in", "r", stdin);
    //freopen("fish.out", "w", stdout);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
        for(rint i=1; i<=n; ++i) scanf("%d%d", &x[i], &y[i]);
        scanf("%d", &m);
        for(rint i=1; i<=m; ++i)
        {
            ans[i]=0;
            scanf("%d%d%d", &a[i].op, &a[i].l, &a[i].r);
            if(a[i].op<=2) scanf("%d", &a[i].d);
        }
        solve(X2, Y2, 1);
        solve(X1-1, Y2, -1);
        solve(X2, Y1-1, -1);
        solve(X1-1, Y1-1, 1);
        for(rint i=1; i<=m; ++i)
            if(a[i].op==3) printf("%d\n", ans[i]);   
    }
    return 0;
}