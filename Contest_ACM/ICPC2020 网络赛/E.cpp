#include<bits/stdc++.h>
#define INF 1e18
#define MAXN 105
#define LL long long
using namespace std;
 
int n, a[MAXN];
LL f[MAXN][MAXN];
 
int main()
{
    while(scanf("%d", &n)!=EOF)
    {
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        for(int i=1; i<=n-1; ++i) f[i][i+1]=0;
        for(int i=2; i<=n-1; ++i)
            for(int j=1; j+i<=n; ++j)
            {
                LL temp=INF;
                for(int k=j+1; k<i+j; ++k) temp=min(temp, f[j][k]+f[k][i+j]+1LL*(a[j]+a[k]+a[i+j])*(a[j]+a[k]+a[i+j]));
                f[j][i+j]=temp;
            }
        printf("%lld\n", f[1][n]);         
    }
    return 0;
}