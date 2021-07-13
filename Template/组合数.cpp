#include <cstdio>
#include <algorithm>
#define MAXN 1005
#define P 998244353
using namespace std;

int n, fac[MAXN], ifac[MAXN];

void init()
{
    ifac[0]=ifac[1]=fac[0]=fac[1]=1;
    for(int i=2; i<=n; i++) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=n; i++)
    {
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
        fac[i]=1LL*fac[i-1]*i%P;
    }
}

int comb(int x, int y)
{
    if(y>x) return 0;
    return 1LL*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

int main()
{
    
}