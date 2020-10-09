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

int n, c[MAXN], t[MAXN];

map<int, int> num;

int main()
{
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i) scanf("%d", &c[i]);
    for(rint i=1; i<=n; ++i) scanf("%d", &t[i]);
    if(c[1]!=t[1] || c[n]!=t[n])
    {
        printf("No\n");
        return 0;
    }
    for(rint i=2; i<=n; ++i) num[c[i]-c[i-1]]++;
    for(rint i=2; i<=n; ++i)
    {
        num[t[i]-t[i-1]]--;
        if(num[t[i]-t[i-1]]==-1)
        {
        printf("No\n");
        return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
