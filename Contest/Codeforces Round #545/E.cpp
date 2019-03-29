#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 5000005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, d, cnt, ans, head[MAXN], deg[MAXN], x[100005], y[100005], f[MAXN];
int Id, tot, top, vis[MAXN], dfn[MAXN], low[MAXN], sta[MAXN], scc[MAXN], siz[MAXN];

struct Edge {int next, to;} edge[MAXN];
queue<int> q;

void addedge(int from, int to)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    deg[to]++;
    head[from]=cnt;
}

inline int id(int x, int y) {return x+(y-1)*n;}

void tarjan(int x)
{
    low[x]=dfn[x]=++Id;
    sta[++top]=x, vis[x]=1;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(!dfn[to]) tarjan(to), low[x]=min(low[x], low[to]);
        else if(vis[to]) low[x]=min(low[x], dfn[to]);
    }
    if(low[x]==dfn[x])
    {
        tot++;
        while(sta[top]!=x)
        {
            int y=sta[top--];
            vis[y]=0, scc[y]=tot;
        }
        top--, vis[x]=0;
        scc[x]=tot;
    }
}

void topsort()
{
    for(rint i=1; i<=tot; ++i)
        if(!deg[i]) q.push(i);
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        f[x]+=siz[x], ans=max(ans, f[x]);
        for(rint i=head[x]; i; i=edge[i].next)
        {
            int to=edge[i].to;
            f[to]=max(f[x], f[to]);
            if(!(--deg[to])) q.push(to);
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &d);
    for(rint i=1; i<=m; ++i)
    {
        scanf("%d%d", &x[i], &y[i]);
        for(rint j=1; j<=d; ++j) addedge(id(x[i], j), id(y[i], j%d+1));
    }
    tarjan(1);
    for(rint i=1; i<=n; ++i)
    {
        for(rint j=1, temp; j<=d; ++j)
        {
            scanf("%1d", &temp);
            if(temp && !vis[scc[id(i, j)]])
            {
                vis[scc[id(i, j)]]=1;
                siz[scc[id(i, j)]]++;
            }
        }
        for(rint j=1; j<=d; ++j) vis[scc[id(i, j)]]=0;
    }
    cnt=0;
    memset(head, 0, sizeof(head));
    memset(deg, 0, sizeof(deg));
    for(rint i=1; i<=m; ++i)
        for(rint j=1; j<=d; ++j)
        {
            int x1=scc[id(x[i], j)], y1=scc[id(y[i], j%d+1)];
            if(x1 && y1 && x1!=y1) addedge(x1, y1);
        }
    
    topsort();
    printf("%d\n", ans);
    return 0;
}