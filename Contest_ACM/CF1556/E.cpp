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
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
#define pii pair<LL,LL>
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;

int n, q, a[MAXN], b[MAXN];
LL c[MAXN], t1[MAXN*4], t2[MAXN*4];

void build(int rt, int l, int r)
{
    if(l==r) {
        t1[rt]=t2[rt]=c[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid+1, r);
    t1[rt]=min(t1[ls], t1[rs]);
    t2[rt]=max(t2[ls], t2[rs]);
}

pii query(int rt, int l, int r, int x, int y)
{
    if(l>=x && r<=y) return MP(t1[rt], t2[rt]);
    if(y<=mid) return query(ls, l, mid, x, y);
    if(x>=mid+1) return query(rs, mid+1, r, x, y);
    pii tmp1=query(ls, l, mid, x, y), tmp2=query(rs, mid+1, r, x, y);
    return MP(min(tmp1.first, tmp2.first), max(tmp1.second, tmp2.second));
}

int main()
{
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1; i<=n; ++i) scanf("%d", &b[i]);
    for(int i=1; i<=n; ++i) { 
        c[i]=c[i-1]+b[i]-a[i];
    }
    build(1, 1, n);
    for(int i=1; i<=q; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        pii tmp=query(1, 1, n, l, r);
        if(tmp.first<c[l-1] || c[r]-c[l-1]!=0) printf("-1\n");
        else printf("%lld\n", tmp.second-c[l-1]);
    }
    return 0;
}