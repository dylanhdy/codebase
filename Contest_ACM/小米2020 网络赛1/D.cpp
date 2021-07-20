#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 300005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, m, cnt, ans, dfn[MAXN], low[MAXN], val[MAXN];
vector<int> g[MAXN];

void tarjan(int x)
{
    dfn[x]=low[x]=++cnt;
    for(int i=0; i<g[x].size(); ++i)
    {
        int to=g[x][i];
        if(!dfn[to])
        {
            tarjan(to);
            low[x]=min(low[x], low[to]);
            if(low[to]>=dfn[x]) val[x]++;
        }
        else low[x]=min(low[x], dfn[to]);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }   
    for(int i=1; i<=n; ++i)
        if(!dfn[i])
        {
            ans++;
            tarjan(i);
            val[i]--;
        }
    for(int i=1; i<=n; ++i) printf("%d ", ans+val[i]);
    return 0;
}