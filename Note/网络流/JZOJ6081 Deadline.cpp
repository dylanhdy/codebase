#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 6006
#define P 998244353
#define G 3
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define fuck printf("FUCK!!\n");
using namespace std;

int S, T, n, m, k, ans, cnt=1, t[MAXN], head[MAXN], dis[MAXN];

struct Edge {int next, to, flow;} edge[MAXN*6];

queue<int> q;

void addedge(int from, int to, int flow)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].flow=flow;
    head[from]=cnt;
}

bool bfs()
{
    for(rint i=1; i<=T; ++i) dis[i]=0;
    dis[S]=1, q.push(S);
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        for(rint i=head[x]; i; i=edge[i].next)
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
    for(rint i=head[x]; i; i=edge[i].next)
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
    freopen("deadline.in", "r", stdin);
    freopen("deadline.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    S=2*m+n+1, T=S+1;
    for(rint i=1; i<=n; ++i)
    {
        scanf("%d", &t[i]);
        if(t[i]) addedge(2*m+i, T, 1), addedge(T, 2*m+i, 0);
        else addedge(S, 2*m+i, 1), addedge(2*m+i, S, 0);
    }
    for(rint i=1; i<=m; ++i) addedge(i, i+m, 1), addedge(m+i, i, 0);
    for(rint i=1, u, v; i<=k; ++i)
    {
        scanf("%d%d", &u, &v);
        if(t[u]==0) addedge(2*m+u, v, 1), addedge(v, 2*m+u, 0);
        else addedge(v+m, 2*m+u, 1), addedge(2*m+u, v+m, 0);
    }
    while(bfs()) ans+=dfs(S, INF);
    printf("%d\n", ans);
    return 0;
}