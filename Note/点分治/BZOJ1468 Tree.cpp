#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 40005
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;
 
int n, k, root, siz, ans, cnt, head[MAXN], son[MAXN], maxson[MAXN];
int tot, q[MAXN], vis[MAXN], dis[MAXN];
 
struct Edge {int next, to, dis;} edge[MAXN*2];
 
void addedge(int from, int to, int dis)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].dis=dis;
    head[from]=cnt;
}
 
void find(int x, int fa)
{
    son[x]=1; maxson[x]=0;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa || vis[to]) continue;
        find(to, x);
        son[x]+=son[to];
        maxson[x]=max(maxson[x], son[to]);
    }
    maxson[x]=max(maxson[x], siz-son[x]);
    if(maxson[x]<maxson[root]) root=x;
}
 
void dfs(int x, int fa)
{
    q[++tot]=dis[x];
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa || vis[to]) continue;
        dis[to]=dis[x]+edge[i].dis;
        dfs(to, x);
    }
}
 
int solve(int x)
{
    tot=0;
    dfs(x, 0);
    sort(q+1, q+tot+1);
    int l=1, r=tot, ans=0;
    while(l<r)
    {
        if(q[l]+q[r]<=k) ans+=r-l, l++;
        else r--;
    }
    return ans;
}
 
void divide(int x)
{
    vis[x]=1; dis[x]=0;
    ans+=solve(x);
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(vis[to]) continue;
        dis[to]=edge[i].dis;
        ans-=solve(to);
        siz=son[to], root=0;
        find(to, x);
        divide(root);
    }
}
 
int main()
{
    scanf("%d", &n);
    for(rint i=1, x, y, z; i<n; ++i)
    {
        scanf("%d%d%d", &x, &y, &z);
        addedge(x, y, z);
        addedge(y, x, z);
    }
    scanf("%d", &k);
    siz=n, root=0, maxson[0]=INF;
    find(1, 0);
    divide(root);
    printf("%d\n", ans);
    return 0;
}