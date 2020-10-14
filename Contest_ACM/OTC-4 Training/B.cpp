#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 2000005
#define MAXM
#define P 1000000007
#define INF 0x3f3f3f3f
using namespace std;

int t, n, m, fac[MAXN], ifac[MAXN];

void init()
{
    fac[0]=fac[1]=ifac[0]=ifac[1]=1;
    for(int i=2; i<=2000000; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=2000000; ++i)
    {
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
        fac[i]=1LL*fac[i-1]*i%P;
    }
}

inline int comb(int x, int y)
{
    return 1LL*fac[x]*ifac[x-y]%P*ifac[y]%P;
}

int main()
{
    init();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        if(n==1 && m==1) printf("1\n");
        else if(n==1 || m==1) printf("2\n");
        else printf("%lld\n", 1LL*4*comb(n+m-2, n-1)%P);
    }
    return 0;
}