#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, m, S, dis[MAXN], vis[MAXN];

struct Node
{
    int id, dis;
    bool friend operator < (Node x, Node y)
    {
        return x.dis>y.dis;
    }
} node;

vector<int> g1[MAXN], g2[MAXN];
priority_queue<Node> q;

void dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    dis[S]=0;
    q.push(node={S, 0});
    while(!q.empty())
    {
        int x=q.top().id; q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=0; i<g1[x].size(); ++i)
        {
            int to=g1[x][i];
            if(dis[to]>dis[x]+g2[x][i])
            {
                dis[to]=dis[x]+g2[x][i];
                if(!vis[to]) q.push(node={to, dis[to]});
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &S);
    for(int i=1; i<=m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g1[x].pb(y), g2[x].pb(z);
    }
    dijkstra();
    //dis[i] 为 s 到 i 的最短路距离
    return 0;
}