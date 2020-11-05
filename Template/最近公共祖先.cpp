#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 500005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, m, s, cnt, head[MAXN], dep[MAXN], f[MAXN][20];

struct Edge {int to, nxt;} edge[MAXN*2];

void addedge(int from, int to)
{
    edge[++cnt].nxt=head[from];
    edge[cnt].to=to;
    head[from]=cnt;
}

void dfs(int x, int fa)
{
    f[x][0]=fa, dep[x]=dep[fa]+1;
    for(int i=head[x]; i; i=edge[i].nxt)
    {
        int to=edge[i].to;
        if(to==fa) continue;
        dep[to]=dep[x]+1;
        dfs(to, x);
    }
}

int lca(int x, int y)
{
    if(dep[x]>dep[y]) swap(x, y);
    for(int i=19; i>=0; --i)
        if(dep[f[y][i]]>=dep[x]) y=f[y][i];
    if(x==y) return x;
    for(int i=19; i>=0; --i)
        if(f[x][i]!=f[y][i]) x=f[x][i], y=f[y][i];
    return f[x][0];
}

int main()
{
    scanf("%d%d%d", &n, &m);
    for(int i=1; i<n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        addedge(x, y);
        addedge(y, x);
    }
    dfs(1, 0);
    for(int i=1; i<=19; ++i)
        for(int j=1; j<=n; ++j) f[j][i]=f[f[j][i-1]][i-1];
    for(int i=1; i<=m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", lca(x, y));
    }
    return 0;
}