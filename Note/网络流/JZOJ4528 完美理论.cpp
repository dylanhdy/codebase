#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 105
#define P 998244353
#define G 3
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define fuck printf("FUCK!!\n");
using namespace std;

int t, n, sum , cut, S, T, a[MAXN];

struct Graph
{
    int cnt, head[MAXN], cur[MAXN], dis[MAXN];

    struct Edge {int next, to, flow;} edge[MAXN*8];

    queue<int> q;

    void addedge(int from, int to, int flow)
    {
        edge[++cnt].next=head[from];
        edge[cnt].to=to;
        edge[cnt].flow=flow;
        head[from]=cnt;
    }

    void init()
    {
        cnt=1;
        memset(head, 0, sizeof(head));
        for(rint i=1; i<=n; ++i)
        {
            if(a[i]>0)
            {
                addedge(S, i, a[i]);
                addedge(i, S, 0);
            }
            if(a[i]<0)
            {
                addedge(i, T, -a[i]);
                addedge(T, i, 0);
            }
        }
    }

    bool bfs()
    {
        memset(dis, 0, sizeof(dis));
        q.push(S), dis[S]=1;
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
        return dis[T]>0;;
    }

    int dfs(int x, int flow)
    {
        if(x==T) return flow;
        int add=0;
        for(rint &i=cur[x]; i; i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis[to]!=dis[x]+1 || edge[i].flow<=0) continue;
            int temp=dfs(to, min(edge[i].flow, flow-add));
            edge[i].flow-=temp, edge[i^1].flow+=temp;
            add+=temp;
            if(add==flow) break;
        }
        return add;
    }

    int dinic()
    {
        int maxflow=0;
        while(bfs())
        {
            memcpy(cur, head, sizeof(head));
            maxflow+=dfs(S, INF);
        }
        return maxflow;
    }
} g;

struct Tree
{
    int cnt, head[MAXN];
    
    struct Edge {int next, to;} edge[MAXN*2];

    void addedge(int from, int to)
    {
        edge[++cnt].next=head[from];
        edge[cnt].to=to;
        head[from]=cnt;
    }

    void dfs(int x, int fa)
    {
        for(rint i=head[x]; i; i=edge[i].next)
            if(edge[i].to!=fa) dfs(edge[i].to, x);
        if(!fa) return;
        g.addedge(x, fa, INF);
        g.addedge(fa, x, 0);
    }

    void init()
    {
        cnt=0;
        memset(head, 0, sizeof(head));
        for(rint i=1, x, y; i<n; ++i)
        {
            scanf("%d%d", &x, &y);
            addedge(x, y);
            addedge(y, x);
        }
    }
} t1, t2;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        sum=0, cut=INF;
        scanf("%d", &n);
        S=n+1, T=S+1;
        for(rint i=1; i<=n; ++i)
        {
            scanf("%d", &a[i]);
            if(a[i]>0) sum+=a[i];
        }
        t1.init(), t2.init();
        for(rint i=1; i<=n; ++i)
        {
            g.init();
            t1.dfs(i, 0), t2.dfs(i, 0);
            cut=min(cut, g.dinic());
        }
        printf("%d\n", sum-cut);
    }
    return 0;
}