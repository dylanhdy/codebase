#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 205
#define MAXM 5005
#define P
#define INF 2147483647
using namespace std;

int n, m, S, T, cnt=1, maxflow, head[MAXN], cur[MAXN], dis[MAXN];

struct Edge {int next, to, flow;} edge[MAXM*2];

queue<int> q;

inline void addedge(int from, int to, int flow)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].flow=flow;
    head[from]=cnt;
}

bool bfs()
{
    for(int i=1; i<=n; ++i) cur[i]=head[i], dis[i]=0;
    dis[S]=1;
    q.push(S);
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        for(int i=head[x]; i; i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis[to] || edge[i].flow<=0) continue;
            dis[to]=dis[x]+1;
            q.push(to);
        }
    }
    return dis[T]>0;
}

int dfs(int x, int flow)
{
    if(x==T) return flow;
    int add=0;
    for(int &i=cur[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(dis[to]!=dis[x]+1 || edge[i].flow<=0) continue;
        int f=dfs(to, min(edge[i].flow, flow-add));
        edge[i].flow-=f, edge[i^1].flow+=f;
        add+=f;
    }
    return add;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &S, &T);
    for(int i=1; i<=m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
        addedge(v, u, 0);
    }
    while(bfs()) maxflow+=dfs(S, INF);
    printf("%lld\n", maxflow);
}