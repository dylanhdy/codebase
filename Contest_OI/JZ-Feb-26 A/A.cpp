#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 21
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, w[MAXN];
double f[1<<MAXN], p[MAXN];
LL ans;

int main()
{
    scanf("%d", &n);
    for(rint i=0; i<n; ++i)
    {
        scanf("%lf%d", &p[i], &w[i]);
        ans+=w[i];
    }
    for(rint i=1; i<(1<<n); ++i)
    {
        double up=0, down=0;
        for(rint j=0; j<n; ++j)
            if((i>>j)&1)
            {
                up+=f[i^(1<<j)]*p[j];
                down+=p[j];
            }
        f[i]=(up+1)/down;
    }
    printf("%lld\n%.3lf\n", ans, f[(1<<n)-1]);
    return 0;
}