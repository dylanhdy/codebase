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
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int T, n, x, a[MAXN], b[MAXN];

LL solve() {
    LL num=0;
    while(1) {
        for(int i=1; i<=n; ++i) {
            if(a[i]%x) return num;
            a[i]/=x;
            num+=b[i];
        }
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        LL num=0;
        scanf("%d%d", &n, &x);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            num+=a[i];
            b[i]=a[i];
        }
        printf("%lld\n", num+solve());
    }
    return 0;
}