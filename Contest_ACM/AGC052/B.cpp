#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, flag, val, dis1[MAXN], dis2[MAXN];

vector<int> g1[MAXN], g2[MAXN], g3[MAXN];

void dfs(int x, int fa) {
    for(int i=0; i<g1[x].size(); ++i) {
        int to=g1[x][i];
        if(to==fa) continue;
        dis1[to]=dis1[x]^g2[x][i];
        dis2[to]=dis2[x]^g3[x][i];
        dfs(to, x);
    }
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<n; ++i) {
        int x, y, w1, w2;
        scanf("%d%d%d%d", &x, &y, &w1, &w2);
        g1[x].PB(y); g2[x].PB(w1); g3[x].PB(w2);
        g1[y].PB(x); g2[y].PB(w1); g3[y].PB(w2);
    }
    dfs(1, 0);
    for(int i=1; i<=n; ++i) val^=(dis1[i]^dis2[i]);
    for(int i=1; i<=n; ++i)
        if(val==dis1[i]) flag=1;
    if(!flag) {
        printf("NO\n");
        return 0;
    }
    for(int i=1; i<=n; ++i) dis2[i]^=val;
    sort(dis1+1, dis1+n+1);
    sort(dis2+1, dis2+n+1);
    for(int i=1; i<=n; ++i)
        if(dis1[i]!=dis2[i]) {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
}