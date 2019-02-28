#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 50005
#define MAXM 100005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, cnt, head[MAXN], bel[MAXN], val[MAXN];
int id, tot, top, vis[MAXN], sta[MAXN], low[MAXN], dfn[MAXN];
LL ans;

struct Edge {int next, to, dis;} edge[MAXM];

void addedge(int from, int to, int dis)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].dis=dis;
    head[from]=cnt;
}

void tarjan(int x)
{
    low[x]=dfn[x]=++id;
    vis[x]=1, sta[++top]=x;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(!dfn[to])
        {
            tarjan(to);
            low[x]=min(low[x], low[to]);
        }
        else if(vis[to]) low[x]=min(low[x], dfn[to]);
    }
    if(low[x]==dfn[x])
    {
        int y; tot++;
        do
        {
            y=sta[top--], vis[y]=0;
            bel[y]=tot;
        } while(x!=y);
    }
}

void dfs(int x)
{
    vis[x]=1;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(bel[x]!=bel[to]) val[bel[to]]=min(val[bel[to]], edge[i].dis);
        if(vis[to]) continue;
        dfs(to);
    }
}

int main()
{
    while(scanf("%d%d", &n, &m) && n && m)
    {
        ans=cnt=tot=0;
        for(rint i=1; i<=n; ++i) head[i]=dfn[i]=low[i]=bel[i]=vis[i]=0;
        for(rint i=1, x, y, z; i<=m; ++i)
        {
            scanf("%d%d%d", &x, &y, &z);
            x++, y++;
            addedge(x, y, z);
        }
        tarjan(1);
        memset(vis, 0, sizeof(vis));
        memset(val, 0x3f, sizeof(val));
        val[bel[1]]=0;
        dfs(1);
        for(rint i=1; i<=tot; ++i) ans+=val[i];
        printf("%lld\n", ans);
    }
    return 0;
}