#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 200005
#define P 998244353
#define G 3
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define fuck printf("FUCK!!\n");
using namespace std;
 
int n, m, ans, a[MAXN];
 
bool check(int mid)
{
    for(rint i=mid*2+1, j=2*n; i<=j; i++, j--)
        if(a[i]+a[j]<m) return false;
    return true;
}
 
int main()
{
    scanf("%d%d", &n, &m);
    for(rint i=1; i<=n*2; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n*2+1);
    int l=0, r=n, pos=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) pos=mid, r=mid-1;
        else l=mid+1;
    }
    for(rint i=1, j=pos*2; i<=j; ++i, --j) ans=max(ans, a[i]+a[j]);
    for(rint i=pos*2+1, j=2*n; i<+j; ++i, --j) ans=max(ans, a[i]+a[j]-m);
    printf("%d\n", ans);
    return 0;
}