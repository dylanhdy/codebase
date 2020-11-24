#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, h, l, r, ans, a[MAXN], f[MAXN][205];

int main()
{
    memset(f, -0x3f, sizeof(f));
    scanf("%d%d%d%d", &n, &h, &l, &r);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        a[i]+=a[i-1];
    }
    f[0][0]=0;
    for(int i=1; i<=n; ++i)
        for(int j=0; j<=h-1; ++j)
        {
            int temp=((a[i]-j)%h>=l && (a[i]-j)%h<=r);
            if(j) f[i][j]=max(f[i-1][j], f[i-1][j-1])+temp;
            else f[i][j]=max(f[i-1][j], f[i-1][h-1])+temp;
        }
    for(int i=0; i<=h-1; ++i) ans=max(ans, f[n][i]);
    printf("%d\n", ans);
    return 0;
}