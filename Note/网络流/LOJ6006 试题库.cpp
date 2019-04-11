#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 2005
#define P 998244353
#define G 3
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define fuck printf("FUCK!!\n");
using namespace std;

int S, T, k, n, m, cnt=1, head[MAXN], dis[MAXN];

struct Edge {int next, to, flow;} edge[MAXN*40];

vector<int> vec[MAXN];
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
    scanf("%d%d", &k, &n);
    S=n+k+1, T=S+1;
    for(rint i=1, x; i<=k; ++i)
    {
        scanf("%d", &x);
        addedge(i+n, T, x);
        addedge(T, i+n, 0);
        m+=x;
    }
    for(rint i=1, p; i<=n; ++i)
    {
        scanf("%d", &p);
        addedge(S, i, 1);
        addedge(i, S, 0);
        for(rint j=1, x; j<=p; ++j)
        {
            scanf("%d", &x);
            addedge(i, x+n, 1);
            addedge(x+n, i, 0);
        }
    }
    int maxflow=0;
    while(bfs()) maxflow+=dfs(S, INF);
    if(maxflow!=m) {printf("No Solution!\n"); return 0;}
    for(rint x=1; x<=n; ++x)
        for(rint i=head[x]; i; i=edge[i].next)
            if(edge[i].flow==0) vec[edge[i].to-n].push_back(x);
    for(rint i=1; i<=k; ++i)
    {
        printf("%d: ", i);
        for(rint j=0; j<vec[i].size(); ++j) printf("%d ", vec[i][j]);
        printf("\n");
    }
    return 0;
}