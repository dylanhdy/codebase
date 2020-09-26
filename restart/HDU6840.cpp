#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 100005
#define P 200003
using namespace std;

int t, n, k, l, a[MAXN];
LL ans1, ans2;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ans1=ans2=0;
        scanf("%d%d%d", &n, &l, &k);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        sort(a+1, a+n+1, greater<int>());
        for(int i=0; i<=n-l; ++i)
        {
            if(i%l<=l-k) ans1+=a[(i/l+1)*k];
            else ans1+=a[(i/l+2)*k+i%l-l];
        }
        reverse(a+1, a+n+1);
        k=l-k+1;
        for(int i=0; i<=n-l; ++i)
        {
            if(i%l<=l-k) ans2+=a[(i/l+1)*k];
            else ans2+=a[(i/l+2)*k+i%l-l];
        }
        printf("%lld %lld\n", ans1, ans2);
    }
    return 0;
}
//特殊情况 k=1