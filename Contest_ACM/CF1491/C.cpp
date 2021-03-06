#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 5005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int T, n, a[MAXN], b[MAXN];

int main() {
    scanf("%d", &T);
    while(T--) {
        LL ans=0;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            b[i]=0;
        }
        for(int i=1; i<=n; ++i) {
            ans+=max(0, a[i]-b[i]);
            b[i+1]+=max(0, b[i]-a[i]);
            for(int j=i+1; j<=min(n, i+a[i]); ++j) b[j]++;
        }
        printf("%lld\n", ans-1);
    }
    return 0;
}