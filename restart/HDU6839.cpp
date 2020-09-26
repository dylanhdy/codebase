#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 100005
#define P 998244353
#define INF 0x3f3f3f3f
using namespace std;

int n, t, ans, dif[MAXN], num1[MAXN], num2[MAXN];
char S[MAXN], T[MAXN];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%s%s", &n, S+1, T+1);
        S[n+1]='0', S[n+2]=0;
        T[n+1]='0', T[n+2]=0;
        dif[n+2]=dif[n+1]=0;
        for(rint i=n; i>=1; --i)
        {
            if(S[i]!=T[i]) dif[i]=dif[i+1]+1;
            else dif[i]=dif[i+1];
        }
        for(rint i=1; i<=n; ++i)
        {
            num1[i]=num1[i-1]+(S[i]=='0');
            num2[i]=num2[i-1]+(T[i]=='1');
        }
        ans=dif[1];
        for(rint i=1; i<=n+1; ++i)
            ans=min(ans, num1[i-1]+num2[i-1]+(S[i]=='1')+(T[i]=='0')+dif[i+1]+1);
        printf("%d\n", ans);
    }
}