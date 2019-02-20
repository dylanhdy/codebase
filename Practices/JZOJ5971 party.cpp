#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 205
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, cnt, tot, sumdis, ans=INF, a[MAXN], head[MAXN], siz[MAXN], sum[MAXN], f[MAXN][MAXN];

struct Edge {int next, to;} edge[MAXN*2];

void addedge(int from, int to)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    head[from]=cnt;
}

void dfs2(int x, int fa, int dis)
{
    if(a[x]==1) sumdis+=dis;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa) continue;
        dfs2(to, x, dis+1);
    }
}

void dfs1(int x, int fa)
{
    siz[x]=1, sum[x]=a[x];
    f[x][0]=0;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa) continue;
        dfs1(to, x);
        siz[x]+=siz[to], sum[x]+=sum[to];
        for(rint j=siz[x]-1; j>=0; --j)
        {
            f[x][j]=f[to][0]+sum[to]+f[x][j];
            for(rint k=1; k<=j; ++k)
                f[x][j]=min(f[x][j], f[to][k-1]+abs(sum[to]-k)+f[x][j-k]);
        }
    }
    sumdis=0;
    dfs2(fa, x, 1);
    ans=min(ans, sumdis+f[x][tot-1]);
}

int main()
{
    freopen("party.in", "r", stdin);
    freopen("party.out", "w", stdout);
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i)
    {
        scanf("%1d", &a[i]);
        tot+=a[i];
    }
    for(rint i=1, x, y; i<n; ++i)
    {
        scanf("%d%d", &x, &y);
        addedge(x, y);
        addedge(y, x);
    }
    memset(f, 0x3f, sizeof(f));
    dfs1(1, 0);
    printf("%d\n", ans);
    return 0;
}
