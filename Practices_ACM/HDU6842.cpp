#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P 998244353
#define INF 0x3f3f3f3f
using namespace std;

int t, n, m, p, q, ans, fac[MAXN*2], ifac[MAXN*2], g[MAXN], a[MAXN], b[MAXN], c[MAXN];

int ksm(int x, int y)
{
    int num=1;
    while(y)
    {
        if(y&1) num=1LL*num*x%P;
        y>>=1, x=1LL*x*x%P;
    }
    return num;
}

void init()
{
    ifac[0]=ifac[1]=fac[0]=fac[1]=1;
    for(int i=2; i<=2e5; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=2e5; ++i)
    {
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
        fac[i]=1LL*fac[i-1]*i%P;
    }
}

inline int comb(int x, int y)
{
    return 1LL*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

int main()
{
    init();
    scanf("%d", &t);
    while(t--)
    {
        ans=0;
        scanf("%d%d%d%d", &n, &m, &p, &q);
        p=1LL*p*ksm(100, P-2)%P;
        q=1LL*q*ksm(100, P-2)%P;
        int inv=ksm((P-1LL*p*q%P+p+q)%P, P-2);
        a[0]=b[0]=c[0]=1;
        a[1]=1LL*(P+1-q)*p%P*inv%P;
        b[1]=1LL*p*q%P*inv%P;
        c[1]=1LL*q*(P+1-p)%P*inv%P;
        for(int i=2; i<=max(n, m); ++i)
        {
            a[i]=1LL*a[i-1]*a[1]%P;
            b[i]=1LL*b[i-1]*b[1]%P;
            c[i]=1LL*c[i-1]*c[1]%P;
        }
        g[0]=1;
        for(int i=1; i<=n; ++i)
            g[i]=(g[i-1]+1LL*c[i]*comb(m-1+i, i)%P)%P;
        for(int i=0; i<=min(n, m)-1; ++i)
            ans=(ans+1LL*comb(m-1, i)*b[i]%P*a[m-i-1]%P*g[n-i-1]%P)%P;
        printf("%lld\n", 1LL*ans*p%P*inv%P);
    }
    return 0;
}