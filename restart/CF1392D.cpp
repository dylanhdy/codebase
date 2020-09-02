#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 200005
using namespace std;

int t, n;
char s[MAXN];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        scanf("%s", s+1);
        int len=0, l=1, r=n, ans=0;
        while(s[l]==s[n]) l++, len++;
        while(s[r]==s[1]) r--, len++;
        ans+=len/3;
        len=1;
        for(rint i=l; i<=r; i++, len++)
            if(s[i]!=s[i+1])
            {
                ans+=len/3;
                len=0;
            }
        if(l==n+1 && r==0) ans=(n+2)/3;
        printf("%d\n", ans);
    }
    return 0;
}
