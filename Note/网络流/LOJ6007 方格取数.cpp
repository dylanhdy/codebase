#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 10005
#define P 998244353
#define G 3
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define fuck printf("FUCK!!\n");
using namespace std;

const int dx[]={0, -1, 0, 1};
const int dy[]={1, 0, -1, 0};

int n, m, S, T, cnt=1, head[MAXN], dis[MAXN];
LL sum;

struct Edge {int next, to, flow;} edge[MAXN*8];

queue<int> q;

void addedge(int from, int to, int flow)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].flow=flow;
    head[from]=cnt;
}

inline int id(int x, int y) {return (x-1)*m+y;}

bool bfs()
{
    for(rint i=1; i<=T; ++i) dis[i]=0;
    dis[S]=1;
    q.push(S);
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        for(rint i=head[x]; i; i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis[to] || edge[i].flow<=0) continue;
            dis[to]=dis[x]+1;
            q.push(to);
        }
    }
    return dis[T]>0;
}

int dfs(int x, int flow)
{
    if(x==T) return flow;
    int add=0;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(dis[to]!=dis[x]+1 || edge[i].flow<=0) continue;
        int f=dfs(to, min(edge[i].flow, flow-add));
        edge[i].flow-=f, edge[i^1].flow+=f;
        add+=f;
    }
    return add;
}

int main()
{
    scanf("%d%d", &n, &m);
    S=n*m+1, T=S+1;
    for(rint i=1; i<=n; ++i)
        for(rint j=1, val; j<=m; ++j)
        {
            scanf("%d", &val);
            sum+=val;
            if((i+j)&1)
            {
                addedge(S, id(i, j), val);
                addedge(id(i, j), S, 0);
                for(rint k=0, val; k<4; ++k)
                {
                    int x=dx[k]+i, y=j+dy[k];
                    if(x>=1 && x<=n && y>=1 && y<=m)
                    {
                        addedge(id(i, j), id(x, y), INF);
                        addedge(id(x, y), id(i, j), 0);
                    }
                }
            }
            else
            {
                addedge(id(i, j), T, val);
                addedge(T, id(i, j), 0);
            }
        }
    //fuck
    LL maxflow=0;
    while(bfs()) maxflow+=dfs(S, INF);
    printf("%lld\n", sum-maxflow);
    return 0;
}