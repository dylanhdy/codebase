#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 300005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int T, n, m, a[MAXN], b[MAXN];
LL ans;

int main() {
    scanf("%d", &T);
    while(T--) {
        ans=0;
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        for(int i=1; i<=m; ++i) scanf("%d", &b[i]);
        sort(a+1, a+n+1, greater<int>());
        for(int i=1; i<=n; ++i) {
            if(i<=m) ans+=min(b[i], b[a[i]]);
            else ans+=b[a[i]];
        }
        printf("%lld\n", ans);
    }
    return 0;
}