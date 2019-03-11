#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 20005
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;
 
int n, up, down, cnt, head[MAXN], num[3];
int root, siz, son[MAXN], f[MAXN], vis[MAXN];
 
struct Edge {int next, to, dis;} edge[MAXN*2];
 
void addedge(int from, int to, int dis)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].dis=dis;
    head[from]=cnt;
}
 
int gcd(int x, int y)
{
    return y==0?x:gcd(y, x%y);
}
 
void find(int x, int fa)
{
    son[x]=1, f[x]=0;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa || vis[to]) continue;
        find(to, x);
        son[x]+=son[to];
        f[x]=max(f[x], son[to]);
    }
    f[x]=max(f[x], siz-son[x]);
    if(root<0 || f[x]<f[root]) root=x;
}
 
void dfs(int x, int fa, int dis)
{
    num[dis]++;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa || vis[to]) continue;
        dfs(to, x, (dis+edge[i].dis)%3);
    }
}
 
int solve(int x, int dis)
{
    num[0]=num[1]=num[2]=0;
    dfs(x, 0, dis);
    return num[0]*num[0]+num[1]*num[2]*2;
}
 
void divide(int x)
{
    vis[x]=1;
    up+=solve(x, 0);
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(vis[to]) continue;
        up-=solve(to, edge[i].dis%3);
        siz=son[to], root=-1;
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
    root=-1, siz=n;
    find(1, 0);
    divide(root);
    down=n*n;
    int d=gcd(up, down);
    printf("%d/%d\n", up/d, down/d);
}