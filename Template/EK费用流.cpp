#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 5005
#define MAXM 50005
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, m, S, T, cnt=1, head[MAXN];
int maxflow, mincost, vis[MAXN], dis[MAXN];

struct Edge {int next, to, flow, cost;} edge[MAXM*2];
struct Pre {int id, from;} pre[MAXN];

queue<int> q;

void addedge (int from, int to, int flow, int cost)
{
    edge[++cnt].next=head[from];
    edge[cnt].cost=cost;
    edge[cnt].flow=flow;
    edge[cnt].to=to;
    head[from]=cnt;
}

bool spfa()
{
    for(int i=0; i<=n; ++i) vis[i]=0, dis[i]=INF;
    vis[S]=1; dis[S]=0;
    q.push(S); 
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        vis[x]=0; 
        for(int i=head[x]; i; i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis[to]>dis[x]+edge[i].cost && edge[i].flow)
            {
                dis[to]=dis[x]+edge[i].cost;
                pre[to].from=x, pre[to].id=i;
                if(!vis[to])
                {
                    q.push(to);
                    vis[to]=1;
                }
            }
        }
    }
    return dis[T]<dis[0];
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &S, &T);
    for(int i=1; i<=m; i++)
    {
        int u, v, w, f;
        scanf("%d%d%d%d", &u, &v, &w, &f);
        addedge(u, v, w, f);
        addedge(v, u, 0, -f);
    }
    maxflow=0, mincost=0;
    while(spfa())
    {
        int flow=INF;
        for(int i=T; i!=S; i=pre[i].from) flow=min(flow, edge[pre[i].id].flow);
        for(int i=T; i!=S; i=pre[i].from)
        {
            edge[pre[i].id].flow-=flow;
            edge[pre[i].id^1].flow+=flow;
        }
        maxflow+=flow;
        mincost+=dis[T]*flow; 
    }
    printf("%d %d\n", maxflow, mincost);
    return 0;
}