#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 105
#define P 998244353
#define G 3
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define fuck printf("FUCK!!\n");
using namespace std;

int n, ans[MAXN], a[MAXN], vis[MAXN];

int main()
{
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(rint i=1; i<=n; ++i)
    {
        int num=0, pos=0;
        for(rint j=1; j<=n; ++j)
        {
            if(vis[j]) continue;
            num++;
            if(num==a[j]) pos=j;
        }
        if(!pos) {printf("-1\n"); return 0;}
        vis[pos]=1, ans[i]=a[pos], vis[pos]=1;
    }
    for(rint i=n; i>=1; --i) printf("%d\n", ans[i]);
    return 0;
}
