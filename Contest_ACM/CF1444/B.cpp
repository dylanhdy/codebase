#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 300005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, a[MAXN], ifac[MAXN], fac[MAXN];
LL ans;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n*2; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n*2+1);
    for(int i=n+1; i<=n*2; ++i) ans+=a[i];
    for(int i=1; i<=n; ++i) ans-=a[i];
    fac[0]=fac[1]=ifac[0]=ifac[1]=1;
    for(int i=2; i<=n*2; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=n*2; ++i)
    {
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
        fac[i]=1LL*fac[i-1]*i%P;
    }
    printf("%lld\n", ans%P*fac[n*2]%P*ifac[n]%P*ifac[n]%P);
    return 0;
}