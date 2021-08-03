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
#define MAXN 50005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, k, siz[MAXN];
LL f[MAXN][105][2], g[MAXN][105][2];

vector<int> t[MAXN];

int qpow(int x, int y)
{
    int num=1;
    while(y) {
        if(y&1) num=1LL*num*x%P;
        x=1LL*x*x%P, y>>=1;
    }
    return num;
}

void dfs(int x, int fa)
{
    siz[x]=1;
    f[x][0][0]=f[x][0][1]=1;
    for(int to: t[x]) {
        if(to==fa) continue;
        dfs(to, x);
        for(int i=min(siz[x], k); i>=0; --i)
            for(int j=0; j<=min(siz[to], k-i); ++j) {
                g[x][i+j][0]=(g[x][i+j][0]+f[x][i][0]*f[to][j][0])%P;
                g[x][i+j][1]=(g[x][i+j][1]+f[x][i][1]*f[to][j][0]+f[x][i][0]*f[to][j][1])%P;
                g[x][i+j+1][0]=(g[x][i+j+1][0]+f[x][i][0]*f[to][j][1])%P;
                g[x][i+j+1][1]=(g[x][i+j+1][1]+f[x][i][1]*f[to][j][1])%P;
            }
        siz[x]+=siz[to];
        for(int i=0; i<=min(siz[x], k); ++i) {
            f[x][i][0]=g[x][i][0], f[x][i][1]=g[x][i][1];
            g[x][i][0]=g[x][i][1]=0;
        }
    }
    //for(int i=0; i<=k; ++i) printf("%d %d %lld %lld\n", x, i, f[x][i][0], f[x][i][1]);
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i=1; i<n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        t[x].PB(y), t[y].PB(x);
    }
    dfs(1, 0);
    printf("%lld\n", f[1][k][1]*qpow(n, k-1)%P);
    return 0;
}