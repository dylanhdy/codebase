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

int T, n, k, a[1005];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &k);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        for(int i=1; i<n; ++i) {
            int tmp=min(a[i], k);
            a[i]-=tmp, k-=tmp, a[n]+=tmp;
            if(!k) break;
        }
        for(int i=1; i<=n; ++i) printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}