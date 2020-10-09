#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 5005
#define P 998244353
#define G 3
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define fuck printf("FUCK!!\n");
using namespace std;

int n, a, b, num[MAXN];
LL ans=1e18, f[MAXN][MAXN];

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for(rint i=1; i<=n; ++i) scanf("%d", &num[i]);
    memset(f, 0x3f, sizeof(f));
    for(rint i=1; i<=n; ++i) f[0][i]=0;
    for(rint i=1; i<=n; ++i)
        for(rint j=1; j<=n; ++j)
        {
            if(num[i]>=j)
            {
                f[i][num[i]]=min(f[i][num[i]], f[i-1][j]);
                f[i][j]=min(f[i][j], f[i-1][j]+a);
            }
            else f[i][j]=min(f[i][j], f[i-1][j]+b);
        }
    for(rint i=1; i<=n; ++i) ans=min(ans, f[n][i]);
    printf("%lld\n", ans);
    return 0;
}
