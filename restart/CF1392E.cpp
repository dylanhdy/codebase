#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 200005
using namespace std;

int n, q;
LL k, a[26][26];

int main()
{
    scanf("%d", &n);
    fflush(stdout);
    a[1][1]=1;
    for(rint i=3; i<=n; i+=2) a[i][1]=a[i-2][1]*4;
    for(rint i=1; i<=n; ++i)
    {
        for(rint j=1; j<=n; ++j)
        {
            if(j>=2) a[i][j]=a[i][j-1]*2;
            printf("%lld ", a[i][j]);
        }
        printf("\n"); fflush(stdout);
    }
    scanf("%d", &q);
    while(q--)
    {
        scanf("%lld", &k);
        printf("1 1\n"); fflush(stdout);
        int x=1, y=1;
        for(rint i=1; i<=(n-1)*2; ++i)
        {
            if(a[x+1][y]==(k&(1LL<<i)) && x<n) x++;
            else y++;
            printf("%d %d\n", x, y); fflush(stdout);
        }
    }
    return 0;
}
