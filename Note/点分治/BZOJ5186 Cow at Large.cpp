#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 100005
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;
 
int n, cnt, head[MAXN], f[MAXN], son[MAXN], vis[MAXN], deg[MAXN];
int root, ans[MAXN], dis[MAXN], g[MAXN][2];
 
struct Edge {int next, to, dis;} edge[MAXN*2];
 
void addedge(int from, int to)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    deg[to]++;
    head[from]=cnt;
}
 
void find(int x, int fa, int siz)
{
    son[x]=1, f[x]=0;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(vis[to] || to==fa) continue;
        find(to, x, siz);
        son[x]+=son[to];
        f[x]=max(f[x], son[to]);
    }
    f[x]=max(f[x], siz-son[x]);
    if(root<0 || f[x]<f[root]) root=x;
}
 
void dfs1(int x, int fa)
{
    if(deg[x]==1) dis[x]=0;
    else dis[x]=INF;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa) continue;
        dfs1(to, x);
        dis[x]=min(dis[x], dis[to]+1);
    }
}
 
void dfs2(int x, int fa)
{
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa) continue;
        dis[to]=min(dis[to], dis[x]+1);
        dfs2(to, x);
    }
}
 
void dfs(int x, int fa, int dep, int op)
{
    int temp=dis[x]-dep;
    if(temp>0)
    {
        g[temp][op]+=2-deg[x];
        g[0][op]=max(g[0][op], temp);
    }
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa || vis[to]) continue;
        dfs(to, x, dep+1, op);
    }
}
 
void cal(int x, int fa, int dep)
{
    ans[x]+=g[dep+1][0]-g[dep+1][1];
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa || vis[to]) continue;
        cal(to, x, dep+1);
    }
}
 
void divide(int x, int siz)
{
    vis[x]=1, g[0][0]=0;
    dfs(x, 0, 0, 0);
    for(rint i=g[0][0]-1; i>=1; i--) g[i][0]+=g[i+1][0];
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(vis[to]) continue;
        g[0][1]=0;
        dfs(to, x, 1, 1);
        for(rint j=g[0][1]-1; j>=1; j--) g[j][1]+=g[j+1][1];
        cal(to, x, 1);
        for(rint j=g[0][1]; j>=1; j--) g[j][1]=0;
    }
    ans[x]+=g[1][0];
    for(rint i=g[0][0]; i>=0; i--) g[i][0]=0;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(vis[to]) continue;
        int temp=son[to]>son[x]?siz-son[x]:son[to];
        root=-1;
        find(to, x, temp);
        divide(root, temp);
    }
}
 
int main()
{
    scanf("%d", &n);
    for(rint i=1, x, y; i<n; ++i)
    {
        scanf("%d%d", &x, &y);
        addedge(x, y);
        addedge(y, x);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    root=-1;
    find(1, 0, n);
    divide(root, n);
    for(rint i=1; i<=n; ++i)
    {
        if(deg[i]==1) printf("1\n");
        else printf("%d\n", 2-ans[i]);
    }
    return 0;
}