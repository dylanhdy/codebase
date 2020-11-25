#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 300005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int t, n, m, ans, sum1, sum2, vis[MAXN];
vector<int> vec[MAXN];

void dfs(int x)
{
    sum1++; sum2+=vec[x].size();
    vis[x]=1;
    for(int i=0; i<vec[x].size(); ++i)
        if(!vis[vec[x][i]]) dfs(vec[x][i]);
}

int main()
{
    scanf("%d", &t);
    for(int qwq=1; qwq<=t; ++qwq)
    {
        ans=0;
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; ++i)
        {
            vis[i]=0;
            vec[i].clear();
        }
        for(int i=1; i<=m; ++i)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        for(int i=1; i<=n; ++i)
            if(!vis[i])
            {
                sum1=sum2=0;
                dfs(i);
                ans+=max(0, sum2/2-sum1);
            }
        printf("Case #%d: %d\n", qwq, ans);
    }
    return 0;
}