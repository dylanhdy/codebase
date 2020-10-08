#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 305
#define P 998244353
using namespace std;

int n, ans, K, cnt, num1, num0, num[MAXN], h[MAXN][MAXN][MAXN], g[MAXN][MAXN][MAXN], f[MAXN][MAXN][MAXN];
char s[MAXN];

int main()
{
    scanf("%s%d", s+1, &K);
    n=strlen(s+1);
    s[n+1]='0';
    for(int i=1; i<=n+1; ++i)
    {
        if(s[i]=='1') cnt++, num1++;
        if(s[i]=='0')
        {
            num[++num0]=cnt;
            cnt=0;
        }
    }
    K=min(K, num1);
    for(int i=0; i<=num[num0]; ++i)
    {
        f[num0][i][i]=1;
        for(int j=i; j>=0; --j)
            g[num0][i][j]=1;
    }
    for(int i=0; i<=K; ++i) h[num0][i][i]=f[num0][i][i]+h[num0][i-1][i-1];
    for(int i=num0-1; i>=1; --i)
        for(int j=0; j<=K; ++j)
        {
            for(int k=0; k<=j; ++k)
            {
                f[i][j][k]=g[i+1][j][k];
                if(num[i]>0 && k>0)
                {
                    f[i][j][k]=(f[i][j][k]+h[i+1][j-1][k-1])%P;
                    if(k>num[i]) f[i][j][k]=(f[i][j][k]-h[i+1][j-num[i]-1][k-num[i]-1]+P)%P;
                }
                h[i][j][k]=f[i][j][k];
                if(k>0) h[i][j][k]=(h[i][j-1][k-1]+h[i][j][k])%P;
            }
            for(int k=j; k>=0; --k)
                g[i][j][k]=(g[i][j][k+1]+f[i][j][k])%P;
        }
    for(int i=0; i<=K; ++i) ans=(ans+f[1][i][0])%P;
    printf("%d\n", ans);
    return 0;
}