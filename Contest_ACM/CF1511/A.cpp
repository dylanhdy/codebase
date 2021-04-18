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

int T, n, ans, a[100005];

int main()
{
    scanf("%d", &T);
    while(T--) {
        ans=0;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            ans+=(a[i]==1 || a[i]==3);
        }
        printf("%d\n", ans);
    }
    return 0;
}