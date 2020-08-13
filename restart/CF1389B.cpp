#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#define rint register int
#define MAXN 100005
using namespace std;

int n, t, K, z, ans, a[MAXN], f[6][MAXN];

int main()
{
    scanf("%d", &t);
    for(rint i=1; i<=t; ++i)
    {
        ans=0;
        scanf("%d%d%d", &n, &K, &z);
        for(rint j=1; j<=n; ++j) scanf("%d", &a[j]);
        for(rint j=1; j<=K+1; ++j)
        {
            f[0][j]=f[0][j-1]+a[j];
            ans=max(ans, f[0][j]);
        }
        for(rint j=1; j<=z; ++j)
            for(rint k=1, temp=K+1-j*2; k<=temp; ++k)
            {
                f[j][k]=max(f[j-1][k+1], f[j][k-1])+a[k];
                ans=max(ans, f[j][k]);
            }
        printf("%d\n", ans);
    }
    return 0;
}