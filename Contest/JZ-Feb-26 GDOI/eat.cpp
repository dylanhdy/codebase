#pragma G++ optimize (2)
#pragma G++ optimize (ofast)
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 205
#define P 1000000007
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, K, ans, a[MAXN][MAXN], f[MAXN][55][55], inv[MAXN], fac[MAXN], finv[MAXN];

void init()
{
    inv[1]=fac[0]=fac[1]=finv[0]=finv[1]=1;
    for(rint i=2; i<=200; ++i) inv[i]=1LL*inv[P%i]*(P-P/i)%P;
    for(rint i=2; i<=200; ++i)
    {
        finv[i]=1LL*inv[i]*finv[i-1]%P;
        fac[i]=1LL*fac[i-1]*i%P;
    }
}

void add(int &x, int y)
{
    if(x+y>P) x=x+y-P;
    else x=x+y;
}

int main()
{
    freopen("eat.in", "r", stdin);
    freopen("eat.out", "w", stdout);
    init();
    scanf("%d%d%d", &n, &m, &K);
    for(rint i=1; i<=n; ++i)
        for(rint j=1; j<=m; ++j) scanf("%d", &a[i][j]);
    for(rint x=1; x<=n; ++x)
    {
        f[0][0][0]=1;
        for(rint i=1; i<=m; ++i)
            for(rint j=0; j<=min(K, i); ++j)
                for(rint l=0; l<=K; ++l)
                {
                    f[i][j][l]=f[i-1][j][l];
                    if(j==0) continue;
                    for(rint k=1, temp=1; k<=l; ++k)
                    {
                        temp=1LL*temp*a[x][i]%P;
                        add(f[i][j][l], 1LL*f[i-1][j-1][l-k]*temp%P*finv[k]%P);
                    }
                }
        for(rint i=1; i<=K; ++i)
        {
            add(ans, 1LL*f[m][i][K]*inv[i+1]%P);
        }
    }
    for(rint x=1; x<=m; ++x)
    {
        f[0][0][0]=1;
        for(rint i=1; i<=n; ++i)
            for(rint j=0; j<=min(K, i); ++j)
                for(rint l=0; l<=K; ++l)
                {
                    f[i][j][l]=f[i-1][j][l];
                    if(j==0) continue;
                    for(rint k=1, temp=1; k<=l; ++k)
                    {
                        temp=1LL*temp*a[i][x]%P;
                        add(f[i][j][l], 1LL*f[i-1][j-1][l-k]*temp%P*finv[k]%P);
                    }
                }
        for(rint i=1; i<=K; ++i)
        {
            add(ans, 1LL*f[n][i][K]*inv[i+1]%P);
        }
    }
    printf("%lld\n", 1LL*ans*fac[K]%P);
    return 0;
}