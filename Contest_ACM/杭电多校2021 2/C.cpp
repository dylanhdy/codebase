#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define LD long double
#define MAXN 1005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, m, x, y, z, f[MAXN][MAXN][2], dis[MAXN];

vector<int> g[MAXN];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    dis[s]=0;
    while(!q.empty()) {
        int x=q.front(); q.pop();
        for(int to: g[x])
            if(dis[to]==INF) {
                dis[to]=dis[x]+1;
                q.push(to);
            }
    }
}

int dfs(int x, int y, int op)
{
    if(f[x][y][op]!=-1) return f[x][y][op];
    int tmp;
    if(op==0) {
        if(y==z) tmp=3;
        else {
            tmp=3;
            for(int to: g[x])
                if(to!=y && dis[to]+1==dis[x])
                    tmp=min(tmp, dfs(to, y, 1));
        }
    } else {
        if(x==z) tmp=1+(dis[y]==1);
        else {
            tmp=1;
            for(int to: g[y])
                if(to!=x && dis[to]+1==dis[y])
                    tmp=max(tmp, dfs(x, to, 0));
        }
    }
    //printf("%d %d %d %d??\n", x, y, op, tmp);
    f[x][y][op]=tmp;
    return tmp;
}

int main()
{
    scanf("%d", &T);
    for(int qwq=1; qwq<=T; ++qwq) {
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; ++i) {
            dis[i]=INF;
            g[i].clear();
            for(int j=1; j<=n; ++j)
                f[i][j][0]=f[i][j][1]=-1;
        }
        scanf("%d%d%d", &x, &y, &z);
        for(int i=1; i<=m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].PB(v), g[v].PB(u);
        }
        bfs(z);
        if(dis[x]<dis[y]) printf("1\n");
        else if(dis[x]>dis[y]) printf("3\n");
        else if(dis[x]==INF) printf("2\n");
        else printf("%d\n", dfs(x, y, 0));
    }
    return 0;
}
/*
1
10 12
8 1 10
1 2
1 3
2 4
2 5
3 5
8 9
9 4
9 5
4 6
6 10
5 7
7 10
8 9
*/