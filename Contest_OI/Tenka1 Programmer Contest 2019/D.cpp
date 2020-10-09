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

int n, a[MAXN], b[MAXN], ans=INF;
char s[MAXN];

int main()
{
    scanf("%d%s", &n, s+1);
    for(rint i=1; i<=n; ++i)
    {
        a[i]=a[i-1];
        if(s[i]=='#') a[i]++;
    }
    for(rint i=n; i>=1; --i)
    {
        b[i]=b[i+1];
        if(s[i]=='.') b[i]++;
    }
    for(rint i=0; i<=n; ++i) ans=min(ans, a[i]+b[i+1]);
    printf("%d\n", ans);
    return 0;
}
