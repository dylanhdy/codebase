#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 1000006
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;
 
int n;
LL ans, b[MAXN], a[MAXN];
 
int main()
{
    scanf("%d", &n);
    for(rint i=1,x ; i<=n; ++i)
    {
        scanf("%d", &x);
        a[x]++;
    }
    for(rint i=1; i<=n; ++i)
    {
        a[i]+=a[i-1];
        b[i]=a[i]-i;
    }
    sort(b+1, b+n+1);
    LL mid=b[(n+1)/2];
    for(rint i=1; i<=n; ++i) ans+=abs(b[i]-mid);
    printf("%lld\n", ans);
    return 0;
}