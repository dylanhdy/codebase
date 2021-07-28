#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;

int n, q;
LL tag[MAXN<<2][3];

void down(int rt, int l, int r)
{
    LL len=mid-l+1;
    tag[ls][0]+=tag[rt][0];
    tag[rs][0]+=tag[rt][0]+len*tag[rt][1]+len*len*tag[rt][2];
    tag[ls][1]+=tag[rt][1];
    tag[rs][1]+=tag[rt][1]+len*2*tag[rt][2];
    tag[ls][2]+=tag[rt][2];
    tag[rs][2]+=tag[rt][2];
    tag[rt][0]=tag[rt][1]=tag[rt][2]=0;
}

void update(int rt, int l, int r, int x, int y, LL k)
{
    if(l>=x && r<=y) {
        tag[rt][0]+=k*k;
        tag[rt][1]+=2*k;
        tag[rt][2]++;
        return;
    }
    down(rt, l, r);
    if(y<=mid) update(ls, l, mid, x , y, k);
    else if(x>mid) update(rs, mid+1, r, x, y, k);
    else {
        update(ls, l, mid, x, y, k);
        update(rs, mid+1, r, x, y, k+mid-x+1);
    }
}

LL query(int rt, int l, int r, int x)
{
    if(l==r) return tag[rt][0]+tag[rt][1]+tag[rt][2];
    down(rt, l, r);
    if(x<=mid) return query(ls, l, mid, x);
    else return query(rs, mid+1, r, x);
}

int id, siz[MAXN], f[MAXN], in[MAXN], son[MAXN], dep[MAXN], top[MAXN];

vector<int> g[MAXN];

void dfs1(int x, int fa)
{
    siz[x]=1, f[x]=fa;
    for(int to: g[x]) {
        if(to==fa) continue;
        dep[to]=dep[x]+1;
        dfs1(to, x);
        siz[x]+=siz[to];
        if(siz[to]>siz[son[x]]) son[x]=to;
    }
}

void dfs2(int x, int fa)
{
    in[x]=++id;
    if(!son[x]) return;
    top[son[x]]=top[x];
    dfs2(son[x], x);
    for(int to: g[x]) {
        if(to==fa || to==son[x]) continue;
        top[to]=to;
        dfs2(to, x);
    }
}

int lca(int x, int y)
{
    while(top[x]!=top[y]) {
        if(dep[top[x]]>dep[top[y]]) x=f[top[x]];
        else y=f[top[y]];
    }
    if(dep[x]<dep[y]) return x;
    else return y;
}

void solve(int x, int y)
{
    int l=1, r=dep[x]+dep[y]-2*dep[lca(x, y)]+1;
    while(top[x]!=top[y]) {
        if(dep[top[x]]>dep[top[y]]) {
            int tmp=l-dep[top[x]]+dep[x];
            update(1, 1, n, in[top[x]], in[x], -tmp-1);
            l=tmp+1;
            x=f[top[x]];
        } else {
            int tmp=r+dep[top[y]]-dep[y];
            update(1, 1, n, in[top[y]], in[y], tmp-1);
            r=tmp-1;
            y=f[top[y]];
            
        }
    }
    if(dep[x]>dep[y]) update(1, 1, n, in[y], in[x], -r-1);
    else update(1, 1, n, in[x], in[y], l-1);
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for(int i=1; i<n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].PB(y), g[y].PB(x);
    }
    dfs1(1, 0);
    top[1]=1;
    dfs2(1, 0);
    scanf("%d", &q);
    while(q--) {
        int op, x, y;
        scanf("%d", &op);
        if(op==1) {
            scanf("%d%d", &x, &y);
            solve(x, y);
        } else {
            scanf("%d", &x);
            printf("%lld\n", query(1, 1, n, in[x]));
        }
    }
    return 0;
}
/*2
10
1 2
1 3
2 4
2 5
3 6
3 7
4 8    
4 9
5 10
5
1 8 6
*/