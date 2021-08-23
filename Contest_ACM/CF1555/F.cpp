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
#define MAXN 300005
#define MAXM 500005
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, q, x[MAXM], y[MAXM], z[MAXM], fa[MAXN], val[MAXN], t[MAXN];
int id, in[MAXN], out[MAXN], dep[MAXN], f[MAXN][20];

vector<int> g[MAXN], w[MAXN];

void dfs(int x, int fa)
{
    f[x][0]=fa, in[x]=++id;
    for(int i=0; i<g[x].size(); ++i) {
        int to=g[x][i];
        if(to==fa) continue;
        dep[to]=dep[x]+1;
        val[to]=val[x]^w[x][i];
        dfs(to, x);
    }
    out[x]=id;
}

int find(int x)
{
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}

int lca(int x, int y)
{
    if(dep[x]<dep[y]) swap(x, y);
    for(int i=18; i>=0; --i)
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return x;
    for(int i=18; i>=0; --i)
        if(f[x][i]!=f[y][i]) x=f[x][i], y=f[y][i];
    return f[x][0];
}

void add(int x, int y)
{
    for(; x<=n; x+=(x&-x)) t[x]+=y;
}

int ask(int x)
{
    int num=0;
    for(; x; x-=(x&-x)) num+=t[x];
    return num;
}

int main()
{
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i) fa[i]=i;
    for(int  i=1; i<=q; ++i) {
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
        int fx=find(x[i]), fy=find(y[i]);
        if(fx!=fy) {
            fa[fx]=fy;
            g[x[i]].PB(y[i]), g[y[i]].PB(x[i]);
            w[x[i]].PB(z[i]), w[y[i]].PB(z[i]);
        }
    }
    for(int i=1; i<=n; ++i)
        if(!in[i]) {
            dep[i]=1;
            dfs(i, 0);
        }
    for(int i=1; i<=n; ++i) fa[i]=i;
    for(int j=1; j<=18; ++j)
        for(int i=1; i<=n; ++i) f[i][j]=f[f[i][j-1]][j-1];
    for(int i=1; i<=q; ++i) {
        int fx=find(x[i]), fy=find(y[i]);
        if(fx!=fy) {
            printf("YES\n");
            fa[fx]=fy;
            continue;
        }
        if(val[x[i]]^val[y[i]]^z[i]!=1) {
            printf("NO\n");
            continue;
        }
        int k=lca(x[i], y[i]);
        if(ask(in[x[i]])+ask(in[y[i]])-2*ask(in[k])) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        while(x[i]!=k) {
            add(in[x[i]], 1), add(out[x[i]]+1, -1);
            x[i]=f[x[i]][0];
        }
        while(y[i]!=k) {
            add(in[y[i]], 1), add(out[y[i]]+1, -1);
            y[i]=f[y[i]][0];
        }
    }
    return 0;
}