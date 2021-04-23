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

int n, m, a[MAXN], b[MAXN], num[MAXN];
LL f[MAXN][MAXN];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        b[i]=a[i];
    }
    sort(a+1, a+n+1);
    m=unique(a+1, a+n+1)-a-1;
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j) num[i]+=(a[i]==b[j]);
    for(int len=1; len<=m; ++len)
        for(int i=1; i+len<=m; ++i) {
            LL temp=a[i+len]-a[i];
            f[i][i+len]=min(f[i+1][i+len]+num[i]*temp, f[i][i+len-1]+num[i+len]*temp); 
        }        
    printf("%lld\n", f[1][m]);
    return 0;
}