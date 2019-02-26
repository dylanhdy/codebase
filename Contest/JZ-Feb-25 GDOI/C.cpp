#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 1000005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, sum, ans, cnt, siz, vis[MAXN], head[MAXN], deg[MAXN], sub[MAXN], a[MAXN], b[MAXN];

struct Edge {int next, to;} edge[MAXN*2];

void addedge(int from, int to)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    deg[to]++;
    head[from]=cnt;
}
void dfs(int x)
{
    vis[x]=1, sum+=deg[x], siz++;
    for(rint i=head[x]; i; i=edge[i].next)
        if(!vis[edge[i].to]) dfs(edge[i].to);
}

int main()
{
    freopen("banzhuan.in", "r", stdin);
    freopen("banzhuan.out", "w", stdout);
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i) scanf("%d", &a[i]), sub[i]=a[i];
    sort(sub+1, sub+n+1);
    m=unique(sub+1, sub+n+1)-sub-1;
    for(rint i=1; i<=n; ++i) b[i]=a[i]=lower_bound(sub+1, sub+m+1, a[i])-sub;
    sort(b+1, b+n+1);
    for(rint i=1; i<=n; ++i)
        if(a[i]!=b[i]) addedge(a[i], b[i]), addedge(b[i], a[i]);
    for(rint i=1; i<=m; ++i)
        if(!vis[i])
        {
            siz=sum=0;
            dfs(i);
            if(siz==1) continue;
            if(siz==2) ans+=sum/4;
            else ans+=sum/2-1;
            
        }
    printf("%d\n", ans);
    return 0;
}