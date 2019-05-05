#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 1000005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, num[MAXN], f[MAXN][3][3];

int main()
{
    scanf("%d%d", &n, &m);
    for(rint i=1, x; i<=n; ++i)
    {
        scanf("%d", &x);
        num[x]++;
    }
    memset(f, -0x3f, sizeof(f));
    f[0][0][0]=0;
    for(rint i=1; i<=m; ++i)
    {
        for(rint j=0; j<=2; ++j)
            for(rint k=0; k<=2; ++k)
            {
                for(rint a=0; a<=2; ++a)
                {
                    int val=num[i]-j-k-a;
                    if(val>=0) f[i][j][k]=max(f[i][j][k], f[i-1][k][a]+a+val/3);
                }
            }
    }
    printf("%d\n", f[m][0][0]);
    return 0;
}
