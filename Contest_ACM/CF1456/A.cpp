#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int t, n, p, k, x, y;
char s[MAXN];
LL ans, f[MAXN];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ans=1e18;
        scanf("%d%d%d%s%d%d", &n, &p, &k, s+1, &x, &y);
        for(int i=n; i>=1; --i)
        {
            if(i+k>n) f[i]=x*(s[i]=='0');
            else f[i]=f[i+k]+x*(s[i]=='0');
        }
        for(int i=p; i<=n; ++i) ans=min(ans, 1LL*(i-p)*y+f[i]);
        printf("%lld\n", ans);
    }
    return 0;
}