#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 500005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, ans, fac[MAXN*2], ifac[MAXN*2];

inline int add(int x, int y) {return x+y>=P?x+y-P:x+y;}
inline int sub(int x, int y) {return x<y?x-y+P:x-y;}

inline int ksm(int x, int y)
{
    int sum=1;
    while(y)
    {
        if(y&1) sum=1LL*sum*x%P;
        x=1LL*x*x%P, y>>=1;
    }
    return sum;
}

void init()
{
    ifac[0]=ifac[1]=fac[0]=fac[1]=1;
    for(rint i=2; i<=n+m; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(rint i=2; i<=n+m; ++i)
    {
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
        fac[i]=1LL*fac[i-1]*i%P;
    }
}

int comb(int x, int y)
{
    return 1LL*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

int main()
{
    freopen("fft.in", "r", stdin);
    freopen("fft.out", "w", stdout);
    scanf("%d%d", &n, &m);
    if(n<m) swap(n, m);
    init();
    for(rint i=1; i<=m; ++i) ans=add(ans, 1LL*comb(i*2, i)*comb(n+m-i*2, n-i)%P);
    ans=1LL*ans*ksm(2LL*comb(n+m, m)%P, P-2)%P;
    printf("%d\n", sub(n+m, add(ans, n)));
    return 0;
}