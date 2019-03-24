#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 505
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, k, c[MAXN][MAXN];

int main()
{
    scanf("%d", &k);
    if(k==1)
    {
        printf("1\n1\n");
        return 0;
    }
    n=(k+3)/4*2;
    for(rint i=0; i<n; ++i)
        for(rint j=0; j<n; ++j)
        {
            if(j&1) c[i][j]=(i+j)%n+n;
            else c[i][j]=(i+j)%n;
            if(c[i][j]>=k) c[i][j]-=n;
        }
    printf("%d\n", n);
    for(rint i=0; i<n; ++i)
    {
        for(rint j=0; j<n; ++j) printf("%d ", c[i][j]+1);
        printf("\n");
    }
    return 0;
}