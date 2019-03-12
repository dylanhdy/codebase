// luogu-judger-enable-o2
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, cnt, top, mp[20][20], head[20], sta[20];
LL ans, f[20][20];

struct Edge {int next, to;} edge[800];

void addedge(int from, int to)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    head[from]=cnt;
}

void dfs(int x, int fa)
{
    for(rint i=1; i<=n; ++i) f[x][i]=1;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa) continue;
        dfs(to, x);
        for(rint j=1; j<=top; ++j)
        {
            int a=sta[j]; LL sum=0;
            for(rint k=1; k<=top; ++k)
            {
                int b=sta[k];
                sum+=f[to][b]*mp[a][b];
            }
            f[x][a]*=sum;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(rint i=1, x, y; i<=m; ++i)
    {
        scanf("%d%d", &x, &y);
        mp[x][y]=mp[y][x]=1;
    }
    for(rint i=1, x, y; i<n; ++i)
    {
        scanf("%d%d", &x, &y);
        addedge(x, y);
        addedge(y, x);
    }
    for(rint i=0; i<(1<<n); ++i)
    {
        top=0;
        for(rint j=0; j<n; ++j)
            if((i>>j)&1) sta[++top]=j+1;
        dfs(1, 0);
        for(rint j=1; j<=top; ++j)
        {
            if((n-top)&1) ans-=f[1][sta[j]];
            else ans+=f[1][sta[j]];
        }
    }
    printf("%lld\n", ans);
    return 0;
}