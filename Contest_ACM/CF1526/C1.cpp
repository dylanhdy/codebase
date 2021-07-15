#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 2005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, ans, a[MAXN];
LL f[MAXN][MAXN];

int main()
{
    scanf("%d", &n);
    memset(f, -0x3f, sizeof(f));
    f[0][0]=0;
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        f[i][0]=f[i-1][0];
        for(int j=1; j<=i; ++j) {
            f[i][j]=f[i-1][j];
            if(f[i-1][j-1]+a[i]>=0) f[i][j]=max(f[i][j], f[i-1][j-1]+a[i]);
        }
    }
    for(int i=0; i<=n; ++i)
        if(f[n][i]>=0) ans=i;
    printf("%d\n", ans);
}