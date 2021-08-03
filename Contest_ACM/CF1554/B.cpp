#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, k, n, a[100005];
LL ans;

int main()
{
    scanf("%d", &T);
    while(T--) {
        ans=-1e18;
        scanf("%d%d", &n, &k);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        for(int i=n; i>=max(1, n-200); --i)
            for(int j=i-1; j>=max(1, n-200); --j)
                ans=max(ans, 1LL*i*j-1LL*k*(a[i]|a[j]));
        printf("%lld\n", ans);
    }
    return 0;
}