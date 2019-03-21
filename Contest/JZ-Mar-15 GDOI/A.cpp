#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 100005
#define MAXM 1000005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define pii pair<int,int>
#define MP make_pair
#define PB push_back
using namespace std;

inline int add(int x, int y) {return x+y>=P?x+y-P:x+y;}
inline int sub(int x, int y) {return x>=y?x-y:x-y+P;}

int n, m, cnt, len, maxdis, ans, flag, num[MAXN], head[MAXN], vis[MAXN], deg[MAXN], tag[MAXN], dis[MAXN], f[MAXN], g[MAXN];

struct Edge {int next, to, dis;} edge[MAXM];
vector<int> now, nxt, vec[MAXN];
vector<pii> pre[MAXN];
queue<int> q;

void addedge(int from, int to, int dis)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    deg[to]++;
    edge[cnt].dis=dis;
    head[from]=cnt;
}

void dfs(int x)
{
    vis[x]=1, tag[x]=1;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(vis[to]) continue;
        if(edge[i].dis) {printf("inf\ninf\n"); exit(0);}
        dfs(to);
    }
}

void cal()
{
    for(rint i=1; i<=n; ++i)
    {
        if(!deg[i] && vis[i]) q.push(i);
        if(!dis[i]) f[i]=1;
    }
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        if(dis[x]>=len) ans=add(ans, f[x]);
        for(rint i=0; i<vec[x].size(); ++i)
        {
            int to=vec[x][i];
            f[to]=add(f[to], f[x]);
            if(!(--deg[to])) q.push(to);
        }
    }
}

void all()
{
    for(rint i=1; i<=n; ++i) ans=add(ans, g[i]);
}

int main()
{
    freopen("tried.in", "r", stdin);
    freopen("tried.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(rint i=1, x, y, z; i<=m; ++i)
    {
        scanf("%d%d%d", &x, &y, &z);
        addedge(x, y, z);
    }
    for(rint i=1; i<=n; ++i)
    {
        if(!deg[i]) q.push(i);
        g[i]=1;
    }
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        vis[x]=1;
        for(rint i=head[x]; i; i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis[x]+1>dis[to]) pre[to].clear(), dis[to]=dis[x]+1;
            if(dis[to]==dis[x]+1) pre[to].PB(MP(x, edge[i].dis));
            g[to]=add(g[to], g[x]);
            if(!(--deg[to])) q.push(to);
        }
    }
    for(rint i=1; i<=n; ++i)
        if(!vis[i]) dfs(i);
    for(rint i=1; i<=n; ++i)
    {
        maxdis=max(maxdis, dis[i]);
        vis[i]=deg[i]=0;
    }
    for(rint x=1; x<=n; ++x)
        if(dis[x]==maxdis)
        {
            now.PB(x);
            for(rint i=head[x]; i; i=edge[i].next)
                if(tag[edge[i].to]) flag=1;
        }
    for(rint i=maxdis; i; i--)
    {
        int maxdis=0;
        for(rint j=0; j<now.size(); ++j)
            for(int k=0; k<pre[now[j]].size(); k++)
                maxdis=max(maxdis, pre[now[j]][k].second);
        num[i]=maxdis;
        for(rint j=0; j<now.size(); ++j)
            for(int k=0; k<pre[now[j]].size(); k++)
                if(pre[now[j]][k].second==maxdis)
                {
                    int to=pre[now[j]][k].first;
                    vec[to].PB(now[j]), deg[now[j]]++;
                    //printf("%d %d!!!\n", to, now[j]);
                    if(vis[to]) continue;
                    nxt.PB(to), vis[to]=1;
                }
        now.clear(), now=nxt, nxt.clear();
    }
    len=0;
    for(rint i=maxdis; i; --i)
    {
        if(!len && num[i]) len=i;
        if(len) printf("%d", num[i]);
    }
    if(!len) printf("0");
    printf("\n");
    if(!len) all();
    else if(flag) printf("inf\n");
    else cal();
    if(!flag) printf("%d\n", ans);
    return 0;
}