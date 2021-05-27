#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 5005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 1e18
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, a[MAXN];
LL ans=INF, g[MAXN], f[MAXN];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1; i<=n; ++i) {
        if(!a[i]) continue;
        f[0]=INF;
        for(int j=1; j<=n; ++j) {
            if(a[j]) f[j]=f[j-1];
            else f[j]=min(f[j-1], g[j-1]+abs(i-j));
        }
        for(int j=0; j<=n; ++j) {
            g[j]=f[j];
            //printf("%d %d %lld\n", i, j, f[j]);
        }
    }
    for(int i=1; i<=n; ++i) ans=min(ans, f[i]);
    printf("%lld\n", ans);
    return 0;
}