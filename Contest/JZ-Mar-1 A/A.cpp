#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 5005
#define MAXM 100005
#define P 998244353
#define INF 1e18
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, q, tot, cnt, head[MAXN], fa[MAXN], dep[MAXN], f[MAXN][15], g[MAXN][15];
LL maxn[MAXN][15];

struct Edge {int next, to, bel; LL dis;} edge[MAXN*2];
struct E {int x, y; LL z;} e[MAXM], d[MAXN];

void addedge(int from, int to, LL dis, int bel)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].bel=bel;
    edge[cnt].dis=dis;
    head[from]=cnt;
}

bool CMP(E x, E y) {return x.z<y.z;}

int find(int x)
{
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}

void dfs(int x, int fa)
{
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa) continue;
        dep[to]=dep[x]+1;
        dfs(to, x);
        f[to][0]=x, g[to][0]=i;
        maxn[to][0]=edge[i].dis;
        //printf("%d %d %lld!!!\n", x, to, edge[i].dis);
    }
}

void init()
{
    for(rint i=1; i<=14; ++i)
        for(rint j=1; j<=n; ++j)
        {
            f[j][i]=f[f[j][i-1]][i-1];
            maxn[j][i]=max(maxn[f[j][i-1]][i-1], maxn[j][i-1]);
            if(maxn[f[j][i-1]][i-1]>maxn[j][i-1]) g[j][i]=g[f[j][i-1]][i-1];
            else g[j][i]=g[j][i-1];
        }
}

void build()
{
    cnt=0;
    for(rint i=1; i<=n; ++i) dep[i]=head[i]=0;
    for(rint i=1; i<n; ++i)
    {
        addedge(d[i].x, d[i].y, d[i].z, i);
        addedge(d[i].y, d[i].x, d[i].z, i);
    }
    dfs(1, 0);
    init();
}

void update(int x, int y, LL k)
{
    LL tmax=0, pos=0, tx=x, ty=y;
    if(dep[x]<dep[y]) swap(x, y);
    for(rint i=14; i>=0; --i)
        if(dep[f[x][i]]>=dep[y])
        {
            if(maxn[x][i]>tmax) tmax=maxn[x][i], pos=g[x][i];
            x=f[x][i];
        }
    if(x!=y)
    {
        for(rint i=14; i>=0; --i)
            if(f[x][i]!=f[y][i])
            {
                if(maxn[x][i]>tmax) tmax=maxn[x][i], pos=g[x][i];
                if(maxn[y][i]>tmax) tmax=maxn[y][i], pos=g[y][i];
                x=f[x][i], y=f[y][i];
            }
        if(maxn[x][0]>tmax) tmax=maxn[x][0], pos=g[x][0];
        if(maxn[y][0]>tmax) tmax=maxn[y][0], pos=g[y][0];
    }
    if(tmax>k)
    {
        d[edge[pos].bel].x=tx;
        d[edge[pos].bel].y=ty;
        d[edge[pos].bel].z=k;
    }
}

LL query(int x, int y)
{
    LL tmax=0;
    if(dep[x]<dep[y]) swap(x, y);
    for(rint i=14; i>=0; --i)
        if(dep[f[x][i]]>=dep[y]) tmax=max(tmax, maxn[x][i]), x=f[x][i];
    if(x==y) return tmax;
    for(rint i=14; i>=0; --i)
        if(f[x][i]!=f[y][i])
        {
            tmax=max(tmax, maxn[x][i]);
            tmax=max(tmax, maxn[y][i]);
            x=f[x][i], y=f[y][i];
        }
    tmax=max(tmax, max(maxn[x][0], maxn[y][0]));
    return tmax;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(rint i=1; i<=m; ++i)
    {
        int x, y; LL z;
        scanf("%d%d%lld", &x, &y, &z);
        e[i].x=x, e[i].y=y, e[i].z=z;
    }
    sort(e+1, e+m+1, CMP);
    for(rint i=1; i<=n; ++i) fa[i]=i;
    for(rint i=1; i<=m; ++i)
    {
        int fx=find(e[i].x), fy=find(e[i].y);
        if(fx!=fy)
        {
            fa[fx]=fy;
            d[++tot]=e[i];
        }
    }
    build();
    scanf("%d", &q);
    while(q--)
    {
        char op[10]; int u, v, m1, m2, b1, b2; LL k;
        scanf("%s", op);
        if(op[0]=='a')
        {
            scanf("%d%d%lld", &u, &v, &k);
            update(u, v, k);
            build();
        }
        if(op[0]=='g')
        {
            scanf("%d%d%d%d", &m1, &m2, &b1, &b2);
            LL m=query(m1, m2), b=query(b1, b2);
            //printf("%lld %lld!!!!!!!!!!!\n", m, b);
            if(m==b) printf("Baozika\n");
            else printf("madoka\n");
        }
    }
    return 0;
}