#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 10000005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, k, ans, fac[MAXN], ifac[MAXN], f[MAXN], g[MAXN];

void init()
{
    ifac[0]=ifac[1]=fac[0]=fac[1]=1;
    for(int i=2; i<=n; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=n; ++i) {
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
        fac[i]=1LL*fac[i-1]*i%P;
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    k=min(k, n);
    if(n==1) {
        printf("1\n");
        return 0;
    }
    init();
    for(int i=1; i<=n; ++i) {
        int tmp=(g[i-1]-g[max(i-k-1, 0)]+P)%P;
        if(i<=k) tmp=(tmp+fac[n-1])%P;
        f[i]=1LL*tmp*ifac[n-i]%P;
        //printf("%d %d %d??\n", i, f[i], g[i-1]);
        g[i]=(g[i-1]+1LL*f[i]*fac[n-i-1]%P)%P;
    }
    printf("%d\n", f[n]);
    return 0;
}