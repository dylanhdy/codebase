#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM 100005
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, m, ans, f[MAXN];

struct Edge {int x, y, dis;} edge[MAXM];

bool CMP(Edge x, Edge y)
{
    return x.dis<y.dis;
}

int find(int x)
{
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}

void kruskal()
{
    for(int i=1; i<=n; ++i) f[i]=i;
    sort(edge+1, edge+m+1, CMP);
    for(int i=1; i<=m; ++i)
    {
        int fx=find(edge[i].x), fy=find(edge[i].y);
        if(fx!=fy)
        {
            ans+=edge[i].dis;
            f[fx]=fy;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m); //n 个点 m 条边
    for(int i=1; i<=m; ++i)
        scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].dis);
    kruskal();
    //ans 为最小生成树边权之和
    return 0;
}