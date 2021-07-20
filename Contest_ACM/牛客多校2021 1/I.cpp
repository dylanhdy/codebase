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
#define MAXN 5005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, a[MAXN], pos[MAXN], h[MAXN][MAXN];
LL ans, inv[MAXN], f[MAXN][MAXN], g[MAXN][MAXN];

void init()
{
    inv[0]=inv[1]=1;
    for(int i=2; i<=n; ++i) inv[i]=inv[P%i]*(P-P/i)%P;
}

int main()
{
    scanf("%d", &n);
    init();
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        pos[a[i]]=i;
    }
    for(int i=n; i>=1; --i) {
        for(int j=n; j>i; --j) {
            f[i][j]=(g[j][pos[i]+1]*inv[h[j+1][pos[i]+1]]+1)%P;
            g[i][pos[j]]=f[i][j];
            ans=(ans+f[i][j]*inv[n]%P*inv[n-i])%P;
            //printf("%d %d %d %d?\n", i, j, f[i][j], inv[h[j+1][pos[i]+1]]);
        }
        for(int j=n; j>=1; --j) {
            g[i][j]=(g[i][j]+g[i][j+1])%P;
            h[i][j]=h[i+1][j]+(j<=pos[i]);
        }
    }
    printf("%lld\n", ans+1);
    return 0;
}