#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 1005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;
 
int n, m, ans, tag[MAXN][MAXN], vis[MAXN][MAXN];
char mp[MAXN][MAXN];
 
int dfs(int x, int y)
{
    if(x==0 || y==0 || x==n+1 || y==m+1) return 1;
    if(vis[x][y]) return tag[x][y];
    vis[x][y]=1;
    if(mp[x][y]=='A')
        if(dfs(x, y-1))
        {
            ans++;
            tag[x][y]=1;
            return 1;
        }
    if(mp[x][y]=='W')
        if(dfs(x-1, y))
        {
            ans++;
            tag[x][y]=1;
            return 1;
        }
    if(mp[x][y]=='S')
        if(dfs(x+1, y))
        {
            ans++;
            tag[x][y]=1;
            return 1;
        }
    if(mp[x][y]=='D')
        if(dfs(x, y+1))
        {
            ans++;
            tag[x][y]=1;
            return 1;
        }
    return 0;
}
 
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%s", mp[i]+1);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(!vis[i][j]) dfs(i, j);
    printf("%d\n", ans);
    return 0;
}