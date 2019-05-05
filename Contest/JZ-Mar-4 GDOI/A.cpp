#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 505
#define P 1000000007
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, K, ans, f[MAXN][MAXN], p[MAXN], s1[MAXN][MAXN], s2[MAXN][MAXN];
int s3[MAXN][MAXN], s4[MAXN][MAXN], s5[MAXN][MAXN], s6[MAXN][MAXN];

int comb(int x)
{
    return 1LL*(x+1)*x/2%P;
}

int ksm(int x, int y)
{
    int sum=1;
    while(y)
    {
        if(y&1) sum=1LL*x*sum%P;
        y>>=1, x=1LL*x*x%P;
    }
    return sum;
}

inline int add(int x, int y)
{
    return x+y>P?x+y-P:x+y;
}

int sub(int x, int y)
{
    return x<y?x-y+P:x-y;
}

int main()
{
    freopen("inverse.in", "r", stdin);
    freopen("inverse.out", "w", stdout);
    scanf("%d%d", &n, &K);
    for(rint i=1; i<=n; ++i) scanf("%d", &p[i]);
    int inv=ksm(comb(n), P-2);
    for(rint i=1; i<=n; ++i)
        for(rint j=i+1; j<=n; ++j)
            if(p[j]<p[i]) f[i][j]=1;
    for(rint k=1; k<=K; ++k)
    {
        for(rint j=1; j<=n; ++j)
            for(rint i=1; i<j; ++i)
            {
                s1[i][j]=add(s1[i-1][j], f[i][j]);
                s2[i][j]=add(s2[i-1][j], s1[i][j]);
            }
        for(rint i=1; i<=n; ++i)
            for(rint j=i+1; j<=n; ++j)
            {
                s3[i][j]=add(s3[i][j-1], f[i][j]);
                s4[i][j]=add(s4[i][j-1], s3[i][j]);
            }
        for(rint j=0; j<n; ++j)
            for(rint i=1; j+i<=n; ++i)
            {
                s5[i][j]=add(s5[i-1][j], f[i][i+j]);
                s6[i][j]=add(s6[i-1][j], s5[i][j]);
            }
        for(rint i=1; i<=n; ++i)
            for(rint j=i+1; j<=n; ++j)
            {
                f[i][j]=1LL*f[i][j]*(comb(i-1)+comb(j-i-1)+comb(n-j))%P;
                f[i][j]=add(f[i][j], sub(s2[j-1][j], add(s2[j-i-1][j], s2[i-1][j])));
                f[i][j]=add(f[i][j], sub(add(s4[i][n], s4[i][i-1]), add(s4[i][i+n-j], s4[i][j-1])));
                f[i][j]=sub(f[i][j], sub(s6[n-j+i][j-i], add(s6[n-j][j-i], s6[i-1][j-i])));
                f[i][j]=add(f[i][j], 1LL*i*(n-j+1)%P);
                f[i][j]=1LL*f[i][j]*inv%P;
                
            }
    }
    for(rint i=1; i<=n; ++i)
        for(rint j=i+1; j<=n; ++j) ans=(ans+f[i][j])%P;
    printf("%d\n", ans);
    return 0;
}