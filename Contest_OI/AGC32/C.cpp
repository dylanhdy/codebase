#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 100005
#define P 998244353
#define G 3
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define fuck printf("FUCK!!\n");
using namespace std;

int n, m, S, T, cnt, deg[MAXN], head[MAXN], vis[MAXN];

struct Edge {int next, to;} edge[MAXN*2];

queue<int> q;

void addedge(int from, int to)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    deg[to]++;
    head[from]=cnt;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(rint i=1, x, y; i<=m; ++i)
    {
        scanf("%d%d", &x, &y);
        addedge(x, y);
        addedge(y, x);
    }
    int num=0, flag=0;
    for(rint i=1; i<=n; ++i)
    {
        if(deg[i]&1) {printf("No\n"); return 0;}
        if(deg[i]>=6) flag=1;
        if(deg[i]==4) num++;
    }
    if(flag) {printf("Yes\n"); return 0;}
    if(num>=3) {printf("Yes\n"); return 0;}
    if(num<=1) {printf("No\n"); return 0;}
    num=0;
    for(rint i=1; i<=n; ++i)
        if(deg[i]==4)
        {
            if(S==0) S=i;
            T=i;
        }
    q.push(S);
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        vis[x]=1;
        if(x==T) {num++; continue;}
        for(rint i=head[x]; i; i=edge[i].next)
        {
            int to=edge[i].to;
            if(vis[to])
            {
                if(to==T) num++;
                continue;
            }
            q.push(to);
        }
    }
    if(num==4) printf("No\n");
    else printf("Yes\n");
    return 0;
}
