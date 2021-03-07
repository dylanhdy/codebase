#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 3005
#define P 998244353
#define INF 0x3f3f3f3f
using namespace std;

int a, b, c, d, f[MAXN][MAXN];

int main()
{
    scanf("%d%d%d%d", &a, &b, &c, &d);
    f[a][b]=1;
    for(rint i=1; i<=c; ++i)
        for(rint j=1; j<=d; ++j)
        {
            f[i][j]=(f[i][j]+1LL*f[i-1][j]*j+1LL*f[i][j-1]*i)%P;
            f[i][j]=(f[i][j]-1LL*(i-1)*(j-1)*f[i-1][j-1]%P+P)%P;
        }
    printf("%d\n", f[c][d]);
    return 0;
}