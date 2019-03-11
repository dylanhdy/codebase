#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 500005
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define p 998244353
#define inv2 499122177
using namespace std;

int n, ans, cnt=1, head[MAXN], f[MAXN][2], g[MAXN][2];

struct Edge {int next, to, val;} edge[MAXN*2];

void addedge(int from, int to, int val)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].val=val;
    head[from]=cnt;
}

int ksm(int x, int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=1LL*x*ans%p;
        x=1LL*x*x%p; y>>=1;
    }
    return ans;
}

const int down=ksm(1000000, p-2);

void dfs(int x, int fa)
{
    int sum=0;
    g[x][0]=g[x][1]=1;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa) continue;
        dfs(to, x);
        g[to][0]=2LL*edge[i^1].val*g[to][0]%p;
        g[to][1]=2LL*edge[i].val*g[to][1]%p;
        f[to][0]=(2LL*edge[i^1].val*f[to][0]+g[to][0])%p;
        f[to][1]=(2LL*edge[i].val*f[to][1]+g[to][1])%p;
        sum=(sum+1LL*f[x][0]*g[to][1]+1LL*f[x][1]*g[to][0]+1LL*g[x][0]*f[to][1]+1LL*g[x][1]*f[to][0])%p;
        f[x][0]=(f[x][0]+f[to][0])%p;
        f[x][1]=(f[x][1]+f[to][1])%p;
        g[x][0]=(g[x][0]+g[to][0])%p;
        g[x][1]=(g[x][1]+g[to][1])%p;
    }
    ans=(1LL*sum*inv2+ans)%p;
}

int main()
{
    scanf("%d", &n);
    for(rint i=1; i<n; ++i)
    {
        int x, y; double z;
        scanf("%d%d%lf", &x, &y, &z);
        int t1=(LL)(z*1000000+0.5)*down%p;
	int t2=(LL)((1-z)*1000000+0.5)*down%p;
        //printf("%d %d %d!!!\n", t1, t2, down);
        addedge(x, y, t1);
        addedge(y, x, t2);
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}