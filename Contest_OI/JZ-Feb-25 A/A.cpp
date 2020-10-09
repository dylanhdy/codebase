#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 100005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, a[MAXN];
LL sum, pre, d;

LL gcd(LL x, LL y)
{
    return y?gcd(y, x%y):x;
}

int main()
{
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    for(rint i=1; i<=n; ++i)
    {
        sum+=(1LL*a[i]*i-pre)*2;
        pre+=a[i];
    }
    for(rint i=1; i<=n; ++i) sum-=a[i];
    d=gcd(sum, n);
    printf("%lld %lld\n", sum/d, n/d);
    return 0;
}
