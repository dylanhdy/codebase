#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 105
#define P 1000000007
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int m, ans, a[MAXN][MAXN], f[MAXN][MAXN], c[MAXN][MAXN];
LL n;

void mul(int a[MAXN][MAXN], int b[MAXN][MAXN])
{
    memset(c, 0, sizeof(c));
    for(rint i=0; i<m; ++i)
        for(rint k=0; k<m; ++k)
            for(rint j=0; j<m; ++j)
                c[i][j]=(c[i][j]+1LL*a[i][k]*b[k][j]%P)%P;
    memcpy(a, c, sizeof(c));
}

void ksm(LL x)
{
    while(x)
    {
        if(x&1) mul(a, f);
        mul(f, f), x>>=1;
    }
}

int main()
{
    scanf("%lld%d", &n, &m);
    for(rint i=0; i<m; ++i)
        f[i+1][i]=1;
    f[0][m-1]=f[0][0]=a[0][0]=1;
    ksm(n);
    printf("%d\n", a[0][0]);
    return 0;
}
