#include <bits/stdc++.h>
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

int n, m, ans, d[22][MAXN], num[22], ifac[22], fac[22];

void init()
{
    fac[0]=fac[1]=ifac[0]=ifac[1]=1;
    for(int i=2; i<=n; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=n; ++i) {
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
        fac[i]=1LL*fac[i-1]*i%P;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    init();
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) scanf("%d", &d[i][j]);
    for(int i=1; i<=m; ++i) {
        int tmp=1;
        for(int j=0; j<=n; ++j) num[j]=0;
        for(int j=1; j<=n; ++j) num[n-d[j][i]+2]++;
        for(int j=1; j<=n; ++j) {
            num[j]+=num[j-1];
            tmp=1LL*tmp*(num[j]-j+1)%P;
        }
        ans=((ans+fac[n]-tmp)%P+P)%P;
        //printf("%d %d\n", i, fac[n]-tmp);
    }
    //printf("%d?\n", ans);
    printf("%lld\n", 1LL*ans*ifac[n]%P);
    return 0;
}