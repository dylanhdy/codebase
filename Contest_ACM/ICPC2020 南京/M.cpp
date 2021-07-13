#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 2005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 1e18
using namespace std;

int T, n, p[MAXN], siz[MAXN], hp[MAXN];
LL f[MAXN][MAXN][2];

vector<int> g[MAXN];

void dfs(int x) {
    siz[x]=1;
    f[x][1][1]=hp[x]; f[x][0][0]=0;
    for(int i=0; i<g[x].size(); ++i) f[x][1][1]+=hp[g[x][i]];
    for(int i=0; i<g[x].size(); ++i) {
        int to=g[x][i];
        dfs(to);
        for(int j=siz[x]; j>=0; --j)
            for(int k=0; k<=siz[to]; ++k)
                f[x][j+k][0]=max(f[x][j+k][0], f[x][j][0]+max(f[to][k][0], f[to][k][1]+hp[to]));
        for(int j=siz[x]; j>=0; --j)
            for(int k=0; k<=siz[to]; ++k)
                f[x][j+k][1]=max(f[x][j+k][1], f[x][j][1]+max(f[to][k][0], f[to][k][1]));
        siz[x]+=siz[to];
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            g[i].clear();
            for(int j=0; j<=n; ++j) f[i][j][0]=f[i][j][1]=-INF;
        }
        for(int i=2; i<=n; ++i) {
            scanf("%d", &p[i]);
            g[p[i]].PB(i);
        }
        for(int i=1; i<=n; ++i) scanf("%d", &hp[i]);
        dfs(1);
        LL temp=f[1][n][1];
        for(int i=0; i<=n; ++i) printf("%lld ", temp-max(f[1][i][0], f[1][i][1]));
        printf("\n");
    }
    return 0;
}
