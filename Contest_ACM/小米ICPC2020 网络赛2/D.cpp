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
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, x, a[MAXN], b[MAXN];

int main() {
    while(scanf("%d%d", &n, &x)!=EOF) {
        LL ans=0;
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        for(int i=1; i<=n; ++i) scanf("%d", &b[i]);
        for(int i=1; i<=n; ++i) ans=(ans+1LL*a[i]*b[i])%P;
        ans=(ans+x)%P;
        for(int i=2; i<=n; ++i) ans=ans*x%P;
        printf("%lld\n", ans);
    }
    return 0;
}