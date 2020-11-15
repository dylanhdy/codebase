#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int t, n, k, cnt, num, ans, tag, len, a[MAXN];
char s[MAXN];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        scanf("%s", s+1);
        len=num=ans=cnt=tag=0;
        for(int i=1; i<=n; ++i)
        {
            if(s[i]=='W') tag=1;
            if(s[i]=='L') len++, num++;
            if(s[i+1]=='W' && s[i]=='L')
            {
                if(tag) a[++cnt]=len;
                len=0;
            }
            if(s[i-1]!='W' && s[i]=='W') ans++;
            if(s[i]=='W' && s[i-1]=='W') ans+=2;
        }
        k=min(k, num);
        sort(a+1, a+cnt+1);
        if(tag) ans+=k*2;
        else ans=max(0, 2*k-1);
        for(int i=1; i<=cnt; ++i)
            if(k>=a[i]) ans++, k-=a[i];
        printf("%d\n", ans);
    }
    return 0;
}