#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 505
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int s, cnt, head[MAXN];

struct Edge {int next, to;} edge[MAXN*2];

void addedge(int from, int to)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    head[from]=cnt;
}

void solve(int n, int m, int k)
{
    for(rint i=3; i<=n+2; ++i)
    {
        addedge(1, i);
        addedge(i, 1);
    }
    for(rint i=n+3; i<=n+m+2; ++i)
    {
        addedge(2, i);
        addedge(i, 2);
    }
    int last=3;
    for(rint i=n+m+3; i<=k+n+m+2; ++i)
    {
        addedge(last, i);
        addedge(i, last);
        last=i;
    }
}

void dfs(int x, int fa)
{
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa) continue;
        dfs(to, x);
        printf("%d %d\n", x, to);
    }
}

int main()
{
    freopen("first.in", "r", stdin);
    freopen("first.out", "w", stdout);
    scanf("%d", &s);
    if(s==0) {printf("0 0\n"); return 0;}
    addedge(1, 2);
    addedge(2, 1);
    for(rint k=1; k<=200; ++k)
        for(rint i=1; i<=500; ++i)
            if((s-k+1)%i==0)
            {
                int j=(s-k+1)/i-1;
                if(i+j+k+2<=500)
                {
                    solve(i, j, k);
                    dfs(1, 0);
                    printf("0 0\n");
                    return 0;
                }
            }
    return 0;
}