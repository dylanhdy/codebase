#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
#define mid (l+r)/2
#define ls (rt<<1)
#define rs (rt<<1|1)
using namespace std;

int n, q, a[MAXN], b[MAXN];

struct Tree {
    int len, llen, rlen;
    LL val;
} t[MAXN*4];

Tree up(Tree l, Tree r)
{
    Tree tmp;
    tmp.len=l.len+r.len;
    tmp.val=l.val+r.val+1LL*l.rlen*r.llen;
    if(r.rlen==r.len) tmp.rlen=r.rlen+l.rlen;
    else tmp.rlen=r.rlen;
    if(l.llen==l.len) tmp.llen=l.llen+r.llen;
    else tmp.llen=l.llen;
    return tmp;
}

void build(int rt, int l, int r)
{
    if(l==r) {
        t[rt]={1, b[l], b[l], b[l]};
        return;
    }
    build(ls, l, mid);
    build(rs, mid+1, r);
    t[rt]=up(t[ls], t[rs]);
}

void update(int rt, int l, int r, int x, int k)
{
    if(l==r) {
        t[rt]={1, k, k, k};
        return;
    }
    if(x<=mid) update(ls, l, mid, x, k);
    else update(rs, mid+1, r, x, k);
    t[rt]=up(t[ls], t[rs]);
}

Tree query(int rt, int l, int r, int x, int y)
{
    if(l>=x && r<=y) return t[rt];
    if(y<=mid) return query(ls, l, mid, x, y);
    if(x>=mid+1) return query(rs, mid+1, r, x, y);
    return up(query(ls, l, mid, x, y), query(rs, mid+1, r, x, y));
}

int main()
{
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    if(n==1) {
        int op, x, y;
        for(int i=1; i<=q; ++i) {
            scanf("%d%d%d", &op, &x, &y);
            if(op==2) printf("1\n");
        }
        return 0;
    }
    n--;
    for(int i=1; i<=n; ++i) b[i]=(a[i]<=a[i+1]);
    build(1, 1, n);
    for(int i=1; i<=q; ++i) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if(op==1) {
            if(x>1 && b[x-1]!=(a[x-1]<=y)) {
                b[x-1]=(a[x-1]<=y);
                update(1, 1, n, x-1, b[x-1]);
            }
            if(x<=n && b[x]!=(y<=a[x+1])) {
                b[x]=(y<=a[x+1]);
                update(1, 1, n, x, b[x]);
            }
            a[x]=y;
        } else {
            if(x==y) printf("1\n");
            else printf("%lld\n", query(1, 1, n, x, y-1).val+y-x+1);
        }
    }
    return 0;
}