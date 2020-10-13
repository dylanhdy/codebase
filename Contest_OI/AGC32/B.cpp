#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 
#define P 998244353
#define G 3
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define fuck printf("FUCK!!\n");
using namespace std;

int n, cnt, tot;
pair<int,int> e[100000], ans[1000000];

int main()
{
    scanf("%d", &n);
    for(rint i=1; i<=n/2; ++i) e[++cnt]=make_pair(i, n-i+(n%2==0));
    for(rint i=1; i<=cnt; ++i)
    {
        for(rint j=i+1; j<=cnt; ++j)
        {
            ans[++tot]=make_pair(e[i].first, e[j].first);
            ans[++tot]=make_pair(e[i].first, e[j].second);
            ans[++tot]=make_pair(e[i].second, e[j].first);
            ans[++tot]=make_pair(e[i].second, e[j].second);
        }
        if(n&1)
        {
            ans[++tot]=make_pair(e[i].first, n);
            ans[++tot]=make_pair(e[i].second, n);
        }
    }
    printf("%d\n", tot);
    for(rint i=1; i<=tot; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}
