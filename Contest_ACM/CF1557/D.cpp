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
#define MAXN 600005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
#define pii pair<int,int>
using namespace std;

int n, m, cnt, ans, x[MAXN], l[MAXN], r[MAXN], sub[MAXN], f[MAXN], pre[MAXN], vis[MAXN];
int t[MAXN*4], tag[MAXN*4], pos[MAXN*4];

vector<pair<int, int> > vec[MAXN];

void down(int rt)
{
    if(!tag[rt]) return;
    t[ls]=tag[rt];
    t[rs]=tag[rt];
    pos[ls]=pos[rt];
    pos[rs]=pos[rt];
    tag[ls]=tag[rt];
    tag[rs]=tag[rt];
    tag[rt]=0;
}

void update(int rt, int l, int r, int x, int y, int k, int p)
{
    if(l>y || r<x) return;
    if(l>=x && r<=y) {
        tag[rt]=k;
        pos[rt]=p;
        t[rt]=k;
        return;
    }
    down(rt);
    update(ls, l, mid, x, y, k, p);
    update(rs, mid+1, r, x, y, k, p);
    if(t[ls]>=t[rs]) pos[rt]=pos[ls], t[rt]=t[ls];
    else pos[rt]=pos[rs], t[rt]=t[rs];
}

pii query(int rt, int l, int r, int x, int y)
{
    if(l>y || r<x) return MP(0, 0);
    if(l>=x && r<=y) return MP(t[rt], pos[rt]);
    down(rt);
    pii tls=query(ls, l, mid, x, y);
    pii trs=query(rs, mid+1, r, x, y);
    if(tls.fi>=trs.fi) return tls;
    else return trs;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i) {
        scanf("%d%d%d", &x[i], &l[i], &r[i]);
        sub[i*2-1]=l[i], sub[2*i]=r[i];
    }
    sort(sub+1, sub+2*m+1);
    cnt=unique(sub+1, sub+2*m+1)-sub-1;
    for(int i=1; i<=m; ++i) {
        l[i]=lower_bound(sub+1, sub+cnt+1, l[i])-sub;
        r[i]=lower_bound(sub+1, sub+cnt+1, r[i])-sub;
        vec[x[i]].PB(MP(l[i], r[i]));
    }
    for(int i=1; i<=n; ++i) {
        for(int j=0; j<vec[i].size(); ++j) {
            pair<int, int> tmp=query(1, 1, cnt, vec[i][j].fi, vec[i][j].se);
            if(tmp.fi+1>f[i]) f[i]=tmp.fi+1, pre[i]=tmp.se;
        }
        //printf("%d %d %d!!\n", i, f[i], pre[i]);
        for(int j=0; j<vec[i].size(); ++j)
            update(1, 1, cnt, vec[i][j].fi, vec[i][j].se, f[i], i);
    }
    for(int i=1; i<=n; ++i)
        if(f[i]>f[ans]) ans=i;
    printf("%d\n", n-f[ans]);
    while(ans) vis[ans]=1, ans=pre[ans];
    for(int i=1; i<=n; ++i)
        if(!vis[i]) printf("%d ", i);
    return 0;
}