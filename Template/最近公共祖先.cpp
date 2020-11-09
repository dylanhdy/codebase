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

int n, m, s, dep[MAXN], f[MAXN][20];

vector<int> g[MAXN];

void dfs(int x, int fa)
{
    f[x][0]=fa, dep[x]=dep[fa]+1;
    for(int i=0; i<g[x].size(); ++i)
    {
        int to=g[x][i];
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
    scanf("%d%d", &n, &m);
    for(int i=1; i<n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    for(int i=1; i<=19; ++i)
        for(int j=1; j<=n; ++j) f[j][i]=f[f[j][i-1]][i-1];
//lca(x,y) 为 x,y 的最近公共祖先
    return 0;
}