#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 205
#define P 998244353
#define G 3
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define fuck printf("FUCK!!\n");
using namespace std;

inline bool read(int &x)
{
    x=0; char ch=getchar();
    while(ch<'0' || ch>'9') ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0', ch=getchar();
    return (ch!='\n' && ch!='\r');
}

int n, m, S, T, cnt=1, head[MAXN], cur[MAXN], dis[MAXN];
LL sum, maxflow;

struct Edge {int next, to, flow;} edge[MAXN*50];

vector<int> ans1, ans2;
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
    for(rint i=1; i<=T; ++i) cur[i]=head[i], dis[i]=0;
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
    for(rint &i=cur[x]; i; i=edge[i].next)
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
    //freopen("a.in", "r", stdin);
    scanf("%d%d", &m, &n);
    S=n+m+1, T=S+1;
    for(rint i=1, x, y; i<=m; ++i)
    {
        scanf("%d", &x);
        addedge(S, i, x), addedge(i, S, 0);
        sum+=x;
        while(read(y)) addedge(i, y+m, INF), addedge(y+m, i, 0);
        addedge(i, y+m, INF), addedge(y+m, i, 0);
    }
    for(rint i=1, x; i<=n; ++i)
    {
        scanf("%d", &x);
        addedge(i+m, T, x), addedge(T, i+m, 0);
    }
    while(bfs()) maxflow+=dfs(S, INF);
    for(rint i=1; i<=n+m; ++i)
    {
        if(!dis[i]) continue;
        if(i<=m) ans1.push_back(i);
        else ans2.push_back(i-m);
    }
    for(rint i=0; i<ans1.size(); ++i)
    {
        printf("%d", ans1[i]);
        if(i!=ans1.size()-1) printf(" ");
    }
    printf("\n");
        for(rint i=0; i<ans2.size(); ++i)
    {
        printf("%d", ans2[i]);
        if(i!=ans2.size()-1) printf(" ");
    }
    printf("\n");
    printf("%lld\n", sum-maxflow);
    return 0;
}