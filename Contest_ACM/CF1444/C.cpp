#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

void dfs1(int x, int col, int node0, int node1)
{
    vis[x]=1;
    if(col && !node1) node1=++cnt;
    if(col) id[x]=node1;
    else id[x]=node0;
    for(int i=0; i<g1[x].size(); ++i)
    {
        int to=g1[x][i];
        if(c[to]==c[x]) dfs1(to, col^1, node0, node1);
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; ++i) scanf("%d", &c[i]);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d", &x[i], &y[i]);
        g1[x].PB(y), g1[y].PB(x);
    }
    for(int i=1; i<=n; ++i)
        if(!vis[i]) dfs1(i, 0, ++cnt, 0);
    for(int i=1; i<=m; ++i)
    {
        g2[id[x]].insert(id[y]);
        g2[id[y]].insert(id[x]);
    }
    
    printf("%lld\n", 1LL*k*(k-1)/2-ans);
    return 0;
}