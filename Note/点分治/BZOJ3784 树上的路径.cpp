#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 50005
#define MAXM 900005
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, cnt, root, siz, head[MAXN], son[MAXN], maxson[MAXN], vis[MAXN];
int id, in[MAXN], out[MAXN], dis[MAXM], lg[MAXM], f[MAXM][20];

struct Edge {int next, to, dis;} edge[MAXN*2];
struct Node
{
    int r, x, y, pos;
    Node(int a=0, int b=0, int c=0)
    {
        r=a, x=b, y=c;
    }
    bool friend operator < (Node x, Node y)
    {
        return dis[x.pos]+dis[x.r]<dis[y.pos]+dis[y.r];
    }
} t[MAXM];

priority_queue<Node> q;

void addedge(int from, int to, int dis)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].dis=dis;
    head[from]=cnt;
}

void find(int x, int fa)
{
    son[x]=1, maxson[x]=0;
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

void dfs(int x, int fa, int dep)
{
    in[x]=++id, dis[id]=dep;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa || vis[to]) continue;
        dfs(to, x, dep+edge[i].dis);
    }
    out[x]=id;
}

void divide(int x)
{
    //printf("%d!!!!\n", x);
    vis[x]=1;
    dfs(x, 0, 0);
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(vis[to]) continue;
        for(rint j=in[to]; j<=out[to]; ++j)
            t[j]=Node(j, in[x], in[to]-1);
    }
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(vis[to]) continue;
        siz=son[to], root=0;
        find(to, x);
        divide(root);
    }
}

void init()
{
    for(rint i=1; i<=id; ++i)
    {
        f[i][0]=i;
        if(i>1) lg[i]=lg[i/2]+1;
    }
    for(rint i=1; (1<<i)<=id; ++i)
        for(rint j=1; j+(1<<i)-1<=id; ++j)
        {
            int x=f[j][i-1], y=f[j+(1<<(i-1))][i-1];
            f[j][i]=(dis[x]>dis[y])?x:y;
        }
}

int ask(int l, int r)
{
    int k=lg[r-l+1];
    int x=f[l][k], y=f[r-(1<<k)+1][k];
    return (dis[x]>dis[y])?x:y;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(rint i=1, x, y, z; i<n; ++i)
    {
        scanf("%d%d%d", &x, &y, &z);
        addedge(x, y, z);
        addedge(y, x, z);
    }
    siz=n, root=0, maxson[0]=INF;
    find(1, 0);
    divide(root);
    init();
    for(rint i=1; i<=id; ++i)
    {
        t[i].pos=ask(t[i].x, t[i].y);
        q.push(t[i]);
        //printf("%d %d!!\n", i, dis[i]);
    }
    while(m--)
    {
        Node top=q.top(); q.pop();
        printf("%d\n", dis[top.pos]+dis[top.r]);
        if(top.pos>top.x)
        {
            Node temp=Node(top.r, top.x, top.pos-1);
            temp.pos=ask(temp.x, temp.y);
            q.push(temp);
        }
        if(top.pos<top.y)
        {
            Node temp=Node(top.r, top.pos+1, top.y);
            temp.pos=ask(temp.x, temp.y);
            q.push(temp);
        }
    }
    return 0;
}
