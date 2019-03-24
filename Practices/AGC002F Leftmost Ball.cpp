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
#define p 1000000007
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, k, f[MAXN][MAXN], inv[MAXN*MAXN], fac[MAXN*MAXN];

void init()
{
    inv[0]=inv[1]=fac[0]=fac[1]=1;
    for(rint i=2; i<=n*k; ++i) inv[i]=1LL*inv[p%i]*(p-p/i)%p;
    for(rint i=2; i<=n*k; ++i)
    {
        inv[i]=1LL*inv[i]*inv[i-1]%p;
        fac[i]=1LL*fac[i-1]*i%p;
    }
}

int comb(int x, int y)
{
    return 1LL*fac[x]*inv[y]%p*inv[x-y]%p;
}

int main()
{
    scanf("%d%d", &n, &k);
    init();
    f[0][0]=1;
    if(k==1) {printf("1\n"); return 0;}
    for(rint i=1; i<=n; ++i)
        for(rint j=0; j<=i; ++j)
        {
            f[i][j]=(f[i][j]+f[i-1][j])%p;
            if(j)
            {
                int temp=n-i+(n-j+1)*(k-1)-1;
                f[i][j]=(f[i][j]+1LL*f[i][j-1]*(n-j+1)%p*comb(temp, k-2)%p)%p;
            }
        }
    printf("%d\n", f[n][n]);
    return 0;
}
