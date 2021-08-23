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


int T, n;
LL a[100005], b[100005];
int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%lld", &a[i]), a[i]+=a[i-1];
        for(int i=1; i<=n; ++i) scanf("%lld", &b[i]), b[i]+=b[i-1];
        LL ans=INF;
        for(int i=1; i<=n; ++i) ans=min(ans, max(b[i-1], a[n]-a[i]));
        printf("%lld\n", ans);
    }
    return 0;
}