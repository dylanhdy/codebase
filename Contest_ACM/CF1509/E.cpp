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
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, ans[MAXN];
LL k;

void dfs(int x, int last, LL res)
{
    if(x==n+1) return;
    if(last) {
        ans[x]=ans[x-1]-1;
        dfs(x+1, last-1, res);
        return;
    }
    for(int i=x; ; ++i) {
        if(log2(k)>max(n-i-1, 0)) {
            k-=(1LL<<max(n-i-1, 0));
        } else {
            ans[x]=i;
            dfs(x+1, i-x, res);
            break;
        }
    }
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%lld", &n, &k);
        if(n<=62 && (1LL<<(n-1))<k) {
            printf("-1\n");
            continue;
        }
        dfs(1, 0, k);
        for(int i=1; i<=n; ++i) printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}