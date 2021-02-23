#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 10005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int x, y, n, m, ans[MAXN], z[MAXN];
char s[MAXN];

int main()
{
    scanf("%d%d%s", &x, &y, s+1);
    n=strlen(s+1);
    for(int i=1; i<=n; ++i)
    {
        if(s[i]>='0' && s[i]<='9') z[i]=s[i]-'0';
        if(s[i]>='A' && s[i]<='Z') z[i]=s[i]-'A'+10;
        if(s[i]>='a' && s[i]<='z') z[i]=s[i]-'a'+36;
    }
    while(1)
    {
        int zero=1;
        for(int i=1; i<=n; ++i)
        {
            z[i+1]+=z[i]%y*x;
            z[i]/=y;
            if(z[i]>0) zero=0;
        }
        ans[++m]=z[n+1]/x;
        z[n+1]=0;
        if(zero) break;
    }
    for(int i=m; i>=1; --i)
    {
        if(ans[i]<10) printf("%c", ans[i]+'0');
        if(ans[i]>=10 && ans[i]<36) printf("%c", ans[i]-10+'A');
        if(ans[i]>=36) printf("%c", ans[i]-36+'a');
    }
    return 0;
}