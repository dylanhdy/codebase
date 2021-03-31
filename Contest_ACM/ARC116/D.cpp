#include <bits/stdc++.h>
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

int n, m, ans, f[25][MAXN], fac[MAXN], ifac[MAXN];

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
    if(y>x) return 0;
    return 1LL*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

int main()
{
    scanf("%d%d", &n, &m);
    init();
    f[0][0]=1;
    for(int i=1; i<=13; ++i) 
        for(int j=0; j<=m/(1<<(i-1)); j+=2) {
            int temp=1LL*j*(1<<(i-1));
            for(int k=temp; k<=m; ++k)
                f[i][k]=(f[i][k]+1LL*f[i-1][k-temp]*comb(n, j)%P)%P;
        }
    printf("%d\n", f[13][m]);
    return 0;
}