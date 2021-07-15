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

int T, n, m, a[1005], b[1005];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        a[0]=a[n+1]=0;
        for(int i=1; i<=n; ++i) scanf("%1d", &a[i]);
        m=min(n, m);
        for(int i=1; i<=m; ++i) {
            for(int j=0; j<=n+1; ++j) b[j]=a[j];
            for(int j=1; j<=n; ++j)
                if(b[j-1]+b[j+1]==1) a[j]=1;
        }
        for(int i=1; i<=n; ++i) printf("%d", a[i]);
        printf("\n");
    } 
    return 0;
}