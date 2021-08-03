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
#define MAXN 2505
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, k, d;
LL ans, ifac[MAXN], fac[MAXN][55], f[MAXN][MAXN], cmb[55][55];

LL qpow(LL x, LL y)
{
    LL num=1;
    while(y) {
        if(y&1) num=num*x%P;
        x=x*x%P, y>>=1;
    }
    return num;
}

LL comb(LL x, LL y)
{
    return fac[x][y]*ifac[y]%P;
}

void init()
{
    cmb[0][0]=ifac[0]=ifac[1]=1;
    for(int i=2; i<=k; ++i) ifac[i]=ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=k; ++i) ifac[i]=ifac[i-1]*ifac[i]%P;
    for(int i=0; i<=n*k; ++i) {
        fac[i][0]=1;
        for(int j=1; j<=k; ++j)
            fac[i][j]=fac[i][j-1]*(d+n*k-i-j+1)%P;
    }
    for(int i=1; i<=n; ++i) {
        cmb[i][0]=1;
        for(int j=1; j<=i; ++j) cmb[i][j]=(cmb[i-1][j-1]+cmb[i-1][j])%P;
    }
}

int main()
{
    scanf("%d%d%d", &n, &k, &d);
    init();
    f[0][0]=1;
    for(int i=1; i<=n; ++i) {
        for(int x=0; x<=n*k; ++x)
            for(int j=0; j<=min(x, k-1); ++j)
                f[i][x]=(f[i][x]+f[i-1][x-j]*comb(x-j, j))%P;
    }
    // for(int i=0; i<=n; ++i)
    //     for(int j=0; j<=n*k; ++j) dbg("%d %d %d??\n", i, j, f[i][j]);
    for(int i=0; i<=n; ++i) {
        LL tmp=0;
        for(int j=0; j<=n*k; ++j)
            tmp=(tmp+f[i][j]*qpow(n-i, d+n*k-j))%P;
        if(i&1) ans=(ans-tmp*cmb[n][i]%P+P)%P;
        else ans=(ans+tmp*cmb[n][i])%P;
    }
    for(int i=d+1; i<=d+n*k; ++i) ans=ans*qpow(i, P-2)%P;
    printf("%lld\n", ans);
    return 0;
}