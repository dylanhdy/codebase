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

int T, n, a[100005];
LL ans;

int main()
{
    scanf("%d", &T);
    while(T--) {
        ans=0;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        for(int i=2; i<=n; ++i) ans=max(ans, 1LL*a[i-1]*a[i]);
        printf("%lld\n", ans);
    }
    return 0;
}