#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, m, k, S, T, sx, sy, tx, ty, vis[MAXN];
double dis[MAXN];

struct Point {int x, y;} p[MAXN];
struct Node
{
    int id;
    double dis;
    bool friend operator < (Node x, Node y)
    {
        return x.dis>y.dis;
    }
} node;

priority_queue<Node> q;
vector<int> g1[MAXN];
vector<double> g2[MAXN];

inline double cross(int ax, int ay, int bx, int by)
{
    return ax*by-ay*bx;
}

inline double dist(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double dijkstra()
{
    for(int i=1; i<=T; ++i) dis[i]=INF;
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
    return dis[T];
}

bool check(Point a, Point b)
{
    for(int i=1; i<=k*2; i+=2)
    {
        double val1, val2;
        Point c=p[i], d=p[i+1];
        val1=cross(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y)*cross(b.x-a.x, b.y-a.y, d.x-a.x, d.y-a.y);
        val2=cross(d.x-c.x, d.y-c.y, a.x-c.x, a.y-c.y)*cross(d.x-c.x, d.y-c.y, b.x-c.x, b.y-c.y);
        if(val1<0 && val2<0) return false;
    }
    return true;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=k; ++i)
        scanf("%d%d%d%d", &p[i*2-1].x, &p[i*2-1].y, &p[i*2].x, &p[i*2].y);
    scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
    S=2*k+1, T=2*k+2;
    p[S].x=sx, p[S].y=sy;
    p[T].x=tx, p[T].y=ty;
    for(int i=1; i<=T; ++i)
        for(int j=i+1; j<=T; ++j)
            if(check(p[i], p[j]))
            {
                double temp=dist(p[i], p[j]);
                g1[i].push_back(j);
                g2[i].push_back(temp);
                g1[j].push_back(i);
                g2[j].push_back(temp);
            }
    printf("%.4lf\n", dijkstra());
    return 0;
}