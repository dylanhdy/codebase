#include <bits/stdc++.h>
#define MAXN 2005
#define INF 0x3f3f3f3f
using namespace std;

int n, k, s, t, cnt=1, maxflow, head[MAXN], dis[MAXN];

struct Edge {int next, to, flow;} edge[MAXN*MAXN*2];

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
    for(int i=1; i<=t; ++i) dis[i]=0;
    dis[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        for(int i=head[x]; i; i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis[to] || !edge[i].flow) continue;
            dis[to]=dis[x]+1;
            q.push(to);
        }
    }
    return dis[t]>0;
}

int dfs(int x, int flow)
{
    if(x==t) return flow;
    int add=0;
    for(int i=head[x]; i && flow; i=edge[i].next)
    {
        int to=edge[i].to;
        if(dis[to]!=dis[x]+1 || !edge[i].flow) continue;
        int f=dfs(to, min(edge[i].flow, flow));
        edge[i].flow-=f, edge[i^1].flow+=f;
        add+=f; flow-=f;
    }
    if(!add) dis[x]=0;
    return add;
}

int main() {
    scanf("%d", &n);
    s=2*n+1; t=2*n+2;
    for(int i=1; i<=n; ++i) {
        scanf("%d", &k);
        for(int j=1; j<=k; ++j) {
            int temp;
            scanf("%d", &temp);
            addedge(i, temp+1+n, 1);
            addedge(temp+1+n, i, 0);
        }
    }
    for(int i=1; i<=n; ++i) {
        addedge(s, i, 1);
        addedge(i, s, 0);
    }
    for(int i=1; i<=n; ++i) {
        addedge(i+n, t, 1);
        addedge(t, i+n, 0);
    }
    while(bfs()) maxflow+=dfs(s, INF);
    printf("%d\n", n-maxflow);
}