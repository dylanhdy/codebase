#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 200005
using namespace std;

int t, n, a[MAXN], b[MAXN];
LL ans;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ans=0;
        scanf("%d", &n);
        for(rint i=1; i<=n; ++i) scanf("%d", &a[i]);
        for(rint i=2; i<=n; ++i)
        {
            b[i]=a[i]-a[i-1];
            if(b[i]<0) ans-=b[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}