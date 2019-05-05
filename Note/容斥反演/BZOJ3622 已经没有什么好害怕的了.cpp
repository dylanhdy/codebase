#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 2005
#define INF 0x3f3f3f3f
#define p 1000000009
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, k, ans, a[MAXN], b[MAXN], num[MAXN], f[MAXN][MAXN], inv[MAXN], fac[MAXN];

void init()
{
    inv[0]=inv[1]=fac[0]=fac[1]=1;
    for(int i=2; i<=n; i++) inv[i]=1LL*inv[p%i]*(p-p/i)%p;
    for(int i=2; i<=n; i++)
    {
        inv[i]=1LL*inv[i-1]*inv[i]%p;
        fac[i]=1LL*fac[i-1]*i%p;
    }
}

int comb(LL x, LL y)
{
    return 1LL*fac[x]*inv[y]%p*inv[x-y]%p;
}

int main()
{
    scanf("%d%d", &n, &k);
    k=(n+k)/2;
    init();
    for(rint i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(rint i=1; i<=n; ++i) scanf("%d", &b[i]);
    sort(a+1, a+n+1); sort(b+1, b+n+1);
    f[0][0]=1; fac[0]=1;
    for(rint i=1, j=1; i<=n; ++i)
    {
        while(b[j]<a[i] && j<=n) j++;
        num[i]=j-1;
    }
    for(rint i=1; i<=n; ++i)
    {
        f[i][0]=f[i-1][0];
        for(rint j=1; j<=n; ++j)
            f[i][j]=(f[i-1][j]+1LL*f[i-1][j-1]*max(0, (num[i]-j+1))%p)%p;
    }
    for(rint i=k; i<=n; ++i)
    {
        f[n][i]=1LL*f[n][i]*fac[n-i]%p;
        if((i-k)&1) ans=(ans+p-1LL*comb(i, k)*f[n][i]%p)%p;
        else ans=(ans+1LL*comb(i, k)*f[n][i]%p)%p;
    }
    printf("%d\n", ans);
    return 0;
}