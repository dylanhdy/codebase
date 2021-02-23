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

int T, n, x, a[MAXN];
LL num1, num2;

int main() {
    scanf("%d", &T);
    while(T--) {
        num1=num2=0;
        scanf("%d%d", &n, &x);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            num2+=(a[i]+x-1)/x;
            num1+=a[i];
        }
        printf("%lld %lld\n", (num1+x-1)/x, num2);
    }
    return 0;
}