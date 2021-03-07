#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, m, ans=INF, dis1[20][MAXN], vis[2][MAXN], dis2[2][MAXN], dis3[2][MAXN];

struct Node {
    int x, dis1, dis2;
    bool friend operator < (Node x, Node y) {
        if(x.dis1==y.dis1) return x.dis2>y.dis2;
        else return x.dis1>y.dis1;
    }
} node;

vector<int> g[2][MAXN];
queue<pair<int, int> > q1;
priority_queue<Node> q2;

void solve1() {
    memset(dis1, -1, sizeof(dis1));
    q1.push(MP(1, 0));
    dis1[0][1]=0;
    while(!q1.empty()) {
        int x=q1.front().first;
        int val1=q1.front().second;
        q1.pop();
        for(int i=0; i<2; ++i)
            for(int j=0; j<g[i][x].size(); ++j) {
                int to=g[i][x][j], val2=val1+(val1%2!=i);
                if(val2<20 && dis1[val2][to]==-1) {
                    dis1[val2][to]=dis1[val1][x]+1;
                    q1.push(MP(to, val2));
                }
            }
    }
    for(int i=0; i<20; ++i)
        if(dis1[i][n]!=-1) ans=min(ans, (1<<i)+dis1[i][n]-1);
}

void solve2() {
    memset(dis2, 0x3f, sizeof(dis2));
    memset(dis3, 0x3f, sizeof(dis3));
    q2.push(node={1, 0, 0});
    dis3[0][1]=dis2[0][1]=0;
    while(!q2.empty()) {
        int x=q2.top().x;
        int val1=q2.top().dis1;
        int val2=q2.top().dis2;
        q2.pop();
        if(vis[val1%2][x]) continue;
        vis[val1%2][x]=1;
        for(int i=0; i<2; ++i)
            for(int j=0; j<g[i][x].size(); ++j) {
                int to=g[i][x][j], val3=val1+(val1%2!=i);
                if(dis2[val3%2][to]==val3 && dis3[val3%2][to]>val2+1) {
                    dis3[val3%2][to]=val2+1;
                    q2.push(node={to, val3, val2+1});
                }
                if(dis2[val3%2][to]>val3) {
                    dis2[val3%2][to]=val3;
                    dis3[val3%2][to]=val2+1;
                    q2.push(node={to, val3, val2+1});
                }
            }
    }
    ans=1;
    for(int i=1; i<=min(dis2[0][n], dis2[1][n]); ++i) ans=ans*2%P;
    if(dis2[0][n]<dis2[1][n]) ans=(ans+dis3[0][n]-1)%P;
    else if(dis2[0][n]==dis2[1][n]) ans=(ans+min(dis3[0][n], dis3[1][n])-1)%P;
    else ans=(ans+dis3[1][n]-1)%P;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[0][x].PB(y);
        g[1][y].PB(x);
    }
    solve1();
    if(ans==INF) solve2();
    printf("%d\n", ans);
    return 0;
}