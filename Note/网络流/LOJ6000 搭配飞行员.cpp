#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 206
#define P 998244353
#define G 3
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define fuck printf("FUCK!!\n");
using namespace std;

int n, m, S, T, maxflow, cnt=1, dep[MAXN], head[MAXN];

struct Edge {int next, to, flow;} edge[MAXN*MAXN*2];
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
    for(rint i=1; i<=T; ++i) dep[i]=0;
    dep[S]=1, q.push(S);
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        for(rint i=head[x]; i; i=edge[i].next)
        {
            int to=edge[i].to;
            if(dep[to] || edge[i].flow<=0) continue;
            dep[to]=dep[x]+1;
            q.push(to);
        }
    }
    return dep[T]>0;
}

int dfs(int x, int flow)
{
    if(x==T) return flow;
    int add=0;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(dep[to]!=dep[x]+1 || edge[i].flow<=0) continue;
        int f=dfs(to, min(edge[i].flow, flow-add));
        edge[i].flow-=f, edge[i^1].flow+=f;
        add+=f;
    }
    return add;
}

int main()
{
    scanf("%d%d", &n, &m);
    S=n+1, T=n+2;
    for(rint i=1; i<=m; ++i) addedge(S, i, 1), addedge(i, S, 0);
    for(rint i=m+1; i<=n; ++i) addedge(i, T, 1), addedge(T, i, 0);
    while(233)
    {
        int x, y;
        if(scanf("%d%d", &x, &y)==EOF) break;
        addedge(x, y, 1);
        addedge(y, x, 0);
    }
    while(bfs()) maxflow+=dfs(S, INF);
    if(!maxflow) {printf("No Solution!\n"); return 0;}
    printf("%d\n", maxflow);
    return 0;
}