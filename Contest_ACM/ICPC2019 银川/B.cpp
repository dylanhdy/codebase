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
using namespace std;

int n, a[1005][1005], x, y;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
        {
            scanf("%d", &a[i][j]);
            if(a[i][j]==-1) x=i, y=j;
        }
    printf("%d\n", a[(x+n-1)%n][y]+a[x][(y+n-1)%n]-a[(x+n-1)%n][(y+n-1)%n]);
    return 0;
}