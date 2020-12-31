#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int t, n, a[1005];
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        int ans1=0, ans2=0;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &a[i]);
            a[i]+=a[i-1];
            ans1=max(ans1, a[i]);
        }
        scanf("%d", &n);
        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &a[i]);
            a[i]+=a[i-1];
            ans2=max(ans2, a[i]);
        }
        printf("%d\n", ans1+ans2);
    }
    return 0;
}