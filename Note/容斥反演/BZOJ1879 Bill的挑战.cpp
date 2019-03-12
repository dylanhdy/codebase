#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define INF 0x3f3f3f3f
#define p 1000003
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int T, n, m, k, ans, C[20][20];
char s[20][55], t[55];

void init()
{
    C[0][0]=1;
    for(rint i=1; i<=15; ++i)
    {
        C[i][0]=1;
        for(rint j=1; j<=i; ++j) C[i][j]=C[i-1][j-1]+C[i-1][j]%p;
    }
}

int solve(int sta)
{
    int ans=1;
    for(rint i=0; i<m; ++i) t[i]='?';
    for(rint i=0; i<n; ++i)
        if((sta>>i)&1)
        {
            for(rint j=0; j<m; ++j)
                if(s[i][j]!='?')
                {
                    if(t[j]!='?' && t[j]!=s[i][j]) return 0;
                    t[j]=s[i][j];
                }
        }
    for(rint i=0; i<m; ++i)
        if(t[i]=='?') ans=(1LL*ans*26)%p;
    return ans;
}

int main()
{
    init();
    scanf("%d", &T);
    while(T--)
    {
        ans=0;
        scanf("%d%d", &n, &k);
        for(rint i=0; i<n; ++i) scanf("%s", s[i]);
        m=strlen(s[0]);
        for(rint sta=0; sta<(1<<n); ++sta)
        {
            int siz=0, temp=solve(sta);
            for(rint i=0; i<n; ++i) siz+=((sta>>i)&1);
            if(siz<k) continue;
            //printf("%d %d %d!!!\n", siz, sta, temp);
            if((siz-k)&1) ans=(ans+p-1LL*temp*C[siz][k]%p)%p;
            else ans=(ans+1LL*temp*C[siz][k]%p)%p;
        }
        printf("%d\n", ans);
    }
}