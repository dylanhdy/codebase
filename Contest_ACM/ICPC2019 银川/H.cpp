#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#define LL long long
#define LD long double
#define MAXN 25005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, s, m1, m2, tot, cnt, low[MAXN], dfn[MAXN], id[MAXN], deg[MAXN], dis[MAXN], vis[MAXN];

struct Node {
    int id, dis;
    bool friend operator < (Node x, Node y) {
        return x.dis>y.dis;
    }
} node;

queue<int> q1;
priority_queue<Node> q2[MAXN];
stack<int> sta;
vector<int> g[MAXN], w[MAXN];

void tarjan(int x) {
    dfn[x]=low[x]=++cnt;
    sta.push(x);
    vis[x]=1;
    for(int i=0; i<g[x].size(); ++i) {
        int to=g[x][i];
        if(!dfn[to]) {
            tarjan(to);
            low[x]=min(low[to], low[x]);
        }
        else if(vis[to])
            low[x]=min(low[x], dfn[to]);
    }
    if(low[x]==dfn[x]) {
        tot++;
        while(!sta.empty() && dfn[sta.top()]>=dfn[x]) {
            int top=sta.top(); sta.pop();
            vis[top]=0;
            id[top]=tot;
        }
    }
}

void dfs(int x) {
    vis[x]=1;
    for(int i=0; i<g[x].size(); ++i) {
        int to=g[x][i];
        if(id[x]!=id[to]) deg[id[to]]++;
        if(!vis[to]) dfs(to);
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m1, &m2, &s);
    for(int i=1; i<=m1; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x].PB(y), w[x].PB(z);
        g[y].PB(x), w[y].PB(z);
    }
    for(int i=1; i<=m2; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x].PB(y), w[x].PB(z);
    }
    for(int i=1; i<=n; ++i)
        if(!dfn[i]) tarjan(i);
    dfs(s);
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    q1.push(id[s]);
    dis[s]=0;
    q2[id[s]].push(node={s, 0});
    while(!q1.empty()) {
        int now=q1.front(); q1.pop();
        while(!q2[now].empty()) {
            int x=q2[now].top().id; q2[now].pop();
            if(vis[x]) continue;
            vis[x]=1;
            for(int i=0; i<g[x].size(); ++i) {
                int to=g[x][i];
                if(dis[to]>dis[x]+w[x][i]) {
                    dis[to]=dis[x]+w[x][i];
                    if(!vis[to]) q2[id[to]].push(node={to, dis[to]});
                }
                if(now!=id[to]) {
                    deg[id[to]]--;
                    if(!deg[id[to]]) q1.push(id[to]);
                }
            }
        }
    }
    for(int i=1; i<=n; ++i) {
        if(dis[i]==INF) printf("NO PATH\n");
        else printf("%d\n", dis[i]);
    }
    return 0;
}