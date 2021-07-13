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
#define dbg(a...) fprintf(stderr, a)
using namespace std;

LL T, n;

int main()
{
    scanf("%lld", &T);
    while(T--) {
        scanf("%lld", &n);
        if(n%2050) {
            printf("-1\n");
            continue;
        }
        n/=2050;
        int ans=0;
        while(n) {
            ans+=n%10;
            n/=10;
        }
        printf("%d\n", ans);
    }
    return 0;
}