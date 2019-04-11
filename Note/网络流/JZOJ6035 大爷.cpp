#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 1005
#define P 998244353
#define G 3
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define fuck printf("FUCK!!\n");
using namespace std;

int n, S, T, cnt=1, maxflow, maxcost, w[MAXN], head[MAXN], dis[MAXN], vis[MAXN];

struct Edge {int next, to, flow, cost;} edge[MAXN*8];
struct Pre {int id, from;} pre[MAXN*4];

void addedge(int from, int to, int flow, int cost)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].flow=flow;
    edge[cnt].cost=cost;
    head[from]=cnt;
}

queue<int> q;

struct Tree
{
    int root, cnt, q, head[MAXN], f[MAXN], bel[MAXN], a[MAXN], b[MAXN], c[MAXN];
    
    struct Edge {int next, to;} edge[MAXN*2];
    
    void addedge(int from, int to)
    {
        edge[++cnt].next=head[from];
        edge[cnt].to=to;
        head[from]=cnt;
    }

    void dfs(int x, int fa)
    {
        f[x]=fa;
        for(rint i=head[x]; i; i=edge[i].next)
            if(edge[i].to!=fa) dfs(edge[i].to, x);
    }

    void build()
    {
        for(rint i=1, x, y; i<n; ++i)
        {
            scanf("%d%d", &x, &y);
            addedge(x, y);
            addedge(y, x);
        }
        dfs(root, 0);
    }

    void dfs1(int x, int id)
    {
        bel[x]=id;
        for(rint i=head[x]; i; i=edge[i].next)
        {
            int to=edge[i].to;
            if(to==f[x]) continue;
            if(a[to]!=-1) {b[id]-=a[to]; continue;}
            dfs1(to, id);
        }
    }

    void init()
    {
        memset(a, -1, sizeof(a));
        scanf("%d", &q);
        for(rint i=1, y; i<=q; ++i)
        {
            scanf("%d%d", &c[i], &y);
            a[c[i]]=b[i]=y;
        }
        for(rint i=1; i<=q; ++i)
        {
            dfs1(c[i], i);
            if(b[i]<0) {printf("-1\n"); exit(0);}
        }
    }
} t1, t2;

bool spfa()
{
    memset(dis, -0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    vis[S]=1, dis[S]=0;
    q.push(S);
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        vis[x]=0;
        for(rint i=head[x]; i; i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis[to]<dis[x]+edge[i].cost && edge[i].flow)
            {
                dis[to]=dis[x]+edge[i].cost;
                pre[to].from=x, pre[to].id=i;
                if(!vis[to]) q.push(to), vis[to]=1;
            }
        }
    }
    return dis[T]>dis[0];
}

int main()
{
    freopen("w.in", "r", stdin);
    freopen("w.out", "w", stdout);
    scanf("%d%d%d", &n, &t1.root, &t2.root);
    for(rint i=1; i<=n; ++i) scanf("%d", &w[i]);
    t1.build(), t2.build();
    t1.init(), t2.init();
    S=t1.q+t2.q+1, T=S+1;
    for(rint i=1; i<=t1.q; ++i)
    {
        addedge(S, i, t1.b[i], 0);
        addedge(i, S, 0, 0);
    }
    for(rint i=1; i<=t2.q; ++i)
    {
        addedge(i+t1.q, T, t2.b[i], 0);
        addedge(T, t1.q+i, 0, 0);
    }
    for(rint i=1; i<=n; ++i)
    {
        addedge(t1.bel[i], t2.bel[i]+t1.q, 1, w[i]);
        addedge(t2.bel[i]+t1.q, t1.bel[i], 0, -w[i]);
    }
    while(spfa())
    {
        int flow=INF;
        for(rint i=T; i!=S; i=pre[i].from) flow=min(flow, edge[pre[i].id].flow);
        for(rint i=T; i!=S; i=pre[i].from)
        {
            edge[pre[i].id].flow-=flow;
            edge[pre[i].id^1].flow+=flow;
        }
        maxflow+=flow;
        maxcost+=dis[T]*flow;
    }
    if(maxflow==t1.a[t1.root]) printf("%d\n", maxcost);
    else printf("-1\n");
    return 0;
}