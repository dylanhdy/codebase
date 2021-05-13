#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 5005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n;
LL ans1, ans2, a[MAXN], b[MAXN], f[MAXN][MAXN];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%lld", &a[i]);
    for(int i=1; i<=n; ++i) {
        scanf("%lld", &b[i]);
        ans1+=a[i]*b[i];
    }
    for(int len=2; len<=n; ++len)
        for(int i=1; i+len-1<=n; ++i) {
            int j=i+len-1;
            f[i][j]=f[i+1][j-1]+b[i]*(a[j]-a[i])+b[j]*(a[i]-a[j]);
            ans2=max(ans2, f[i][j]);
        }
    printf("%lld\n", ans1+ans2);
    return 0;
}