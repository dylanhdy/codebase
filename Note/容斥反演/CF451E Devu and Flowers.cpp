#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 25
#define P 1000000007
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, ans, inv[MAXN];
LL s, a[MAXN];

int comb(int x, int y)
{
    if(x<y) return 0;
    int ans=1;
    for(rint i=0; i<y; ++i)
    {
        ans=1LL*ans*(x-i)%P;
        ans=1LL*ans*inv[i+1]%P;
    }
    return ans;
}

int main()
{
    scanf("%d%lld", &n, &s);
    for(rint i=0; i<n; ++i) scanf("%lld", &a[i]);
    inv[0]=inv[1]=1;
    for(rint i=2; i<=n; ++i) inv[i]=1LL*inv[P%i]*(P-P/i)%P;
    for(rint sta=0; sta<(1<<n); ++sta)
    {
        LL num=s, cnt=0;;
        for(rint i=0; i<n; ++i)
            if((sta>>i)&1)
            {
                cnt++;
                num-=(a[i]+1);
            }
        if(cnt&1) ans=(ans-comb((num+n-1)%P, n-1)+P)%P;
        else ans=(ans+comb((num+n-1)%P, n-1))%P;
    }
    printf("%d\n", ans);
    return 0;
}