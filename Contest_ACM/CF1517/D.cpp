#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, k, a[505][505], b[505][505];
LL f[20][505][505];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m-1; ++j) scanf("%d", &a[i][j]);
    for(int i=1; i<=n-1; ++i)
        for(int j=1; j<=m; ++j) scanf("%d", &b[i][j]);
    if(k&1) {
        for(int i=1; i<=n; ++i) {
            for(int i=1; i<=m; ++i) printf("-1 ");
            printf("\n");
        }
        return 0;
    }
    k/=2;
    for(int i=1; i<=k; ++i) {
        memset(f[i], 0x3f, sizeof(f[i]));
        for(int x=1; x<=n; ++x)
            for(int y=1; y<=m; ++y) {
                if(x>1) f[i][x][y]=min(f[i][x][y], f[i-1][x-1][y]+b[x-1][y]);
                if(y>1) f[i][x][y]=min(f[i][x][y], f[i-1][x][y-1]+a[x][y-1]);
                if(x<n) f[i][x][y]=min(f[i][x][y], f[i-1][x+1][y]+b[x][y]);
                if(y<m) f[i][x][y]=min(f[i][x][y], f[i-1][x][y+1]+a[x][y]);
            }
    }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) printf("%lld ", f[k][i][j]*2);
        printf("\n");
    }
    return 0;
}