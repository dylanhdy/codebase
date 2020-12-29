#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int t, n, m, ans, vis[MAXN], to[MAXN];

void dfs(int x, int root)
{
    vis[x]=1;
    if(x==root)
    {
        ans++;
        return;
    }
    if(to[x] && !vis[to[x]]) dfs(to[x], root);
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ans=0;
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; ++i) to[i]=vis[i]=0;
        for(int i=1; i<=m; ++i)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if(x==y) continue;
            to[x]=y;
            ans++;
        }
        for(int i=1; i<=n; ++i)
            if(!vis[i] && to[i]) dfs(to[i], i);
        printf("%d\n", ans);
    }
    return 0;
}