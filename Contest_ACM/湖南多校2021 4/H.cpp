#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
#define mid ((l+r)>>1)
using namespace std;

int n, m, q, rt, cnt, a[MAXN], t[MAXN*60], ls[MAXN*60], rs[MAXN*60];

void update(int &rt, int l, int r, int x)
{
    if(!rt) rt=++cnt;
    if(l==r) {
        t[rt]^=1;
        return;    
    }
    if(x<=mid) update(ls[rt], l, mid, x);
    else update(rs[rt], mid+1, r, x);
    t[rt]=t[ls[rt]]+t[rs[rt]];
}

int query(int rt, int l, int r, int x, int y)
{
    if(!rt || l>y || r<x) return 0;
    if(l>=x && r<=y) return t[rt];
    return query(ls[rt], l, mid, x, y)+query(rs[rt], mid+1, r, x, y);
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for(int i=1; i<=m; ++i) {
        scanf("%d", &a[i]);
        update(rt, 1, n, a[i]);
        if(a[i]<n) update(rt, 1, n, a[i]+1);
    }
    while(q--) {
        int op, x, y;
        scanf("%d", &op);
        if(op==1) {
            scanf("%d", &x);
            update(rt, 1, n, x);
            if(x<n) update(rt, 1, n, x+1);
        } else {
            scanf("%d%d", &x, &y);
            if(query(rt, 1, n, x+1, y)==y-x) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
/*
2 0 7
2 1 2
1 1
2 1 2
1 2
2 1 2
1 1
2 1 2
*/