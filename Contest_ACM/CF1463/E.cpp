#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 300005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, k, root, p[MAXN], to[MAXN], from[MAXN], f[MAXN], dep[MAXN], deg[MAXN];

queue<int> q;
vector<int> ans, vec[MAXN], g[MAXN];

void dfs(int x, int fa)
{
    f[x]=fa;
    vec[fa].PB(x);
    if(to[x])
    {
        dep[to[x]]=dep[x]+1;
        dfs(to[x], fa);
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i) scanf("%d", &p[i]);
    for(int i=1; i<=k; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        to[x]=y, from[y]=x;
    }
    for(int i=1; i<=n; ++i)
        if(!from[i]) dfs(i, i);
    for(int i=1; i<=n; ++i)
        if(!f[i])
        {
            printf("0");
            return 0;
        }
    for(int i=1; i<=n; ++i)
    {
        if(!p[i]) root=i;
        else if(f[p[i]]!=f[i])
        {
            g[f[p[i]]].PB(f[i]);
            deg[f[i]]++;
        }
        else if(dep[p[i]]>dep[i])
        {
            printf("0");
            return 0;
        }
    }
    for(int i=1; i<=n; ++i)
        if(f[i]==i && !deg[f[i]]) q.push(f[i]);
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        for(int i=0; i<vec[x].size(); ++i) ans.PB(vec[x][i]);
        for(int i=0; i<g[x].size(); ++i)
        {
            int to=g[x][i];
            deg[to]--;
            if(!deg[to]) q.push(to);
        }
    }
    if(ans.size()==n)
        for(int i=0; i<ans.size(); ++i) printf("%d ", ans[i]);
    else printf("0");
    return 0;
}