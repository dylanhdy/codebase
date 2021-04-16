#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 3000005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, k, vis[MAXN], pre[MAXN];
LL dis[MAXN];

struct Node {
    int id;
    LL dis;
    bool friend operator < (Node x, Node y) {
        return x.dis>y.dis;
    }
};

struct Edge {int to, dis, id;};

vector<int> ans;
vector<Edge> g[MAXN];
priority_queue<Node> q;

void dfs(int x, int fa)
{
    vis[x]=1;
    for(int i=0; i<g[x].size(); ++i) {
        int to=g[x][i].to;
        if(to==fa || !k) continue;
        if(pre[to]==g[x][i].id) {
            ans.PB(g[x][i].id);
            k--;
            dfs(to, x);
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=m; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x].PB(Edge{y, z, i});
        g[y].PB(Edge{x, z, i});
    }
    memset(dis, 0x3f, sizeof(dis));
    q.push(Node{1, 0});
    dis[1]=0;
    while(!q.empty()) {
        int x=q.top().id; q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=0; i<g[x].size(); ++i) {
            int to=g[x][i].to;
            if(dis[to]>dis[x]+g[x][i].dis) {
                dis[to]=dis[x]+g[x][i].dis;
                pre[to]=g[x][i].id;
                q.push(Node{to, dis[to]});
            }
        }
    }
    dfs(1, 0);
    printf("%d\n", ans.size());
    for(int i=0; i<ans.size(); ++i) printf("%d ", ans[i]);
    return 0;
}