#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, ans, f[MAXN][25], fac[MAXN], ifac[MAXN];

void init()
{
    fac[0]=fac[1]=ifac[0]=ifac[1]=1;
    for(int i=2; i<=n; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=n; ++i) {
        fac[i]=1LL*fac[i-1]*i%P;
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
    }
}

int comb(int x, int y)
{
    return 1LL*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

int main()
{
    scanf("%d%d", &n, &m);
    init();
    f[1][1]=1;
    ans=1;
    for(int i=2; i<=m; ++i) {
        f[i][1]=1;
        for(int j=2; j*j<=i; ++j)
            if(i%j==0) {
                for(int k=2; k<=19; ++k) f[i][k]=(f[i][k]+f[j][k-1])%P;
                if(j*j==i) continue;
                for(int k=2; k<=19; ++k) f[i][k]=(f[i][k]+f[i/j][k-1])%P;
            }
        for(int j=1; j<=19; ++j) {
            ans=(ans+1LL*comb(n, j)*f[i][j]%P)%P;
            //if(f[i][j]) printf("%d %d %d\n", i, j, f[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}