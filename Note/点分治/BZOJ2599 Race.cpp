#include <cstdio>
#include <algorithm>
#include <cstring>
#include <algorithm>
#define MAXN 200005
#define MAXK 1000006
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;
 
int n, k, cnt, tot, root, ans, head[MAXN], size[MAXN], val[MAXK], f[MAXN];
bool vis[MAXN];
 
struct Edge {int next, to, dis;} edge[MAXN*2];
 
void addedge(int from, int to, int dis)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].dis=dis;
    head[from]=cnt;
}
 
void getroot(int x, int fa)
{
    size[x]=1; f[x]=0; 
    for(int i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa || vis[to]) continue;
        getroot(to, x);
        size[x]+=size[to];
        f[x]=max(f[x], size[to]);
    }
    f[x]=max(f[x], tot-size[x]);
    if(f[x]<f[root]) root=x;
}
 
void getdis(int x, int fa, int dep, int num, int op)
{
    if(op==0) val[dep]=min(val[dep], num);
    else val[dep]=INF;
    for(int i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa || vis[to]) continue;
        if(dep+edge[i].dis<=k) getdis(to, x, dep+edge[i].dis, num+1, op); 
    }
}
 
void update(int x, int fa, int dep, int num)
{
    ans=min(ans, val[k-dep]+num);
    for(int i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa || vis[to]) continue;
        if(dep+edge[i].dis<=k) update(to, x, dep+edge[i].dis, num+1); 
    }
}
 
void divide(int x)
{
    vis[x]=1; val[0]=0;
    for(int i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(vis[to]) continue;
        if(edge[i].dis<=k) update(to, x, edge[i].dis, 1);
        if(edge[i].dis<=k) getdis(to, x, edge[i].dis, 1, 0);
    }
    for(int i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(vis[to]) continue;
        if(edge[i].dis<=k) getdis(to, x, edge[i].dis, 1, 1);
    }
    for(int i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(vis[to]) continue;
        tot=size[to]; root=0;
        getroot(to, x);
        divide(root);
    }   
}
 
int main()
{
    f[0]=INF; ans=INF;
    memset(val, 0x3f, sizeof(val));
     
    scanf("%d%d", &n, &k);
    for(int i=1; i<n; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        x++; y++;
        addedge(x, y, z);
        addedge(y, x, z);
    }
    tot=n; root=0;
    getroot(1, 0);
    divide(root);
    if(ans==INF) printf("-1\n");
    else printf("%d\n", ans);
 }