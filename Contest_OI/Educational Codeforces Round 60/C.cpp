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

int sx, sy, ex, ey, n, nx[MAXN], ny[MAXN];
char s[MAXN];

bool check(LL mid)
{
    LL x=sx+mid/n*nx[n]+nx[mid%n];
    LL y=sy+mid/n*ny[n]+ny[mid%n];
    return abs(x-ex)+abs(y-ey)<=mid;
}

int main()
{
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    scanf("%d", &n);
    scanf("%s", s+1); 
    for(rint i=1; i<=n; ++i)
    {
        if(s[i]=='R') nx[i]++;
        if(s[i]=='L') nx[i]--;
        if(s[i]=='U') ny[i]++;
        if(s[i]=='D') ny[i]--;
        nx[i]+=nx[i-1], ny[i]+=ny[i-1];
    }
    LL l=0, r=1e14, ans=-1;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(check(mid)) ans=mid, r=mid-1;
        else l=mid+1;
    }
    printf("%lld\n", ans);
    return 0;
}
