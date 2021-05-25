#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 405
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m;
LL ans, ifac[MAXN], pw2[MAXN], fac[MAXN], f[MAXN][MAXN];

void init()
{
    fac[0]=fac[1]=ifac[0]=ifac[1]=pw2[0]=1;
    for(int i=1; i<=n; ++i) pw2[i]=pw2[i-1]*2%m;
    for(int i=2; i<=n; ++i) ifac[i]=ifac[m%i]*(m-m/i)%m;
    for(int i=2; i<=n; ++i) {
        ifac[i]=ifac[i-1]*ifac[i]%m;
        fac[i]=fac[i-1]*i%m;
    }
}

int comb(int x, int y)
{
    return fac[x]*ifac[y]%m*ifac[x-y]%m;
}

int main()
{
    scanf("%d%d", &n, &m);
    init();
    for(int i=1; i<=n; ++i) {
        f[i][i]=pw2[i-1];
        for(int j=1; j<=i; ++j) {
            for(int k=1; k<j; ++k)
                f[i][j]=(f[i][j]+f[i-k-1][j-k]*pw2[k-1]%m*comb(j, k))%m;
            //printf("%d %d %lld\n", i, j, f[i][j]);
        }
    }
    for(int i=1; i<=n; ++i) ans=(ans+f[n][i])%m;
    printf("%lld\n", ans);
    return 0;
}