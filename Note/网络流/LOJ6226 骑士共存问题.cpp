#include <bits/stdc++.h>
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;

const int dx[]={1, 2, 2, 1, -1, -2, -2, -1};
const int dy[]={-2, -1, 1, 2, 2, 1, -1, -2};

int n, m, s, t, ans, cnt=1, cur[MAXN], head[MAXN], dep[MAXN], mark[MAXN];
bool tag[205][205];

struct Edge {int next, to, flow;} edge[MAXN*4];

queue<int> q;

inline void addedge(int from, int to, int flow)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].flow=flow;
    head[from]=cnt;
}

void bfs()
{
    dep[t]=1; mark[1]=1; q.push(t);
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        for(int i=head[x]; i; i=edge[i].next)
        {
            int to=edge[i].to;
            if(dep[to] || !edge[i^1].flow) continue;
            dep[to]=dep[x]+1; mark[dep[to]]++;
            q.push(to);
        }
    }
}

int dfs(int x, int flow)
{
    int add=0;
    if(x==t) return flow;
    for(int &i=cur[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(dep[x]!=dep[to]+1) continue;
        int f=dfs(to, min(flow, edge[i].flow));
        add+=f; flow-=f;
        edge[i].flow-=f; edge[i^1].flow+=f;
        if(!flow) return add;
    }
    if(! (--mark[dep[x]])) dep[s]=n*n+1;
    mark[++dep[x]]++; cur[x]=head[x];
    return add;
}

inline int dinic()
{
    bfs();
    memcpy(cur, head, sizeof(head));
    int maxflow=dfs(s, INF);
    while(dep[s]<=n*n) maxflow+=dfs(s, INF);
    return maxflow;
}

int main()
{
    scanf("%d%d", &n, &m);
    ans=n*n-m; s=n*n+1; t=s+1;
    for(int i=1; i<=m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        tag[x][y]=true;
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++)
    {
        if(tag[i][j]) continue;
        if((i+j)%2)
        {
            addedge(s, (i-1)*n+j, 1);
            addedge((i-1)*n+j, s, 0);
            for(int k=0; k<8; k++)
            {
                int x=i+dx[k], y=j+dy[k];
                if((x<1 || y<1 || x>n || y>n || tag[x][y])) continue;
                addedge((i-1)*n+j, (x-1)*n+y, 1);
                addedge((x-1)*n+y, (i-1)*n+j, 0);
            }
        }
        else
        {
            addedge((i-1)*n+j, t, 1);
            addedge(t, (i-1)*n+j, 0);
        }
    }
    printf("%d\n", ans-dinic());
}
