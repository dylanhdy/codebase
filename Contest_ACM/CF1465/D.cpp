#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, x, y, cnt1, cnt2, pre[MAXN][2], suf[MAXN][2];
char s[MAXN];
LL ans, val;

int main()
{
    scanf("%s%d%d", s+1, &x, &y);
    n=strlen(s+1);
    cnt1=1;
    for(int i=1; i<=n; ++i)
    {
        if(s[i]=='?')
        {
            cnt1++;
            pre[cnt1][0]+=pre[cnt1-1][0];
            pre[cnt1][1]+=pre[cnt1-1][1];
        }
        if(s[i]=='1')
        {
            pre[cnt1][1]++;
            val+=1LL*pre[cnt1][0]*x;
        }
        if(s[i]=='0')
        {
            pre[cnt1][0]++;
            val+=1LL*pre[cnt1][1]*y;
        }
    }
    cnt2=cnt1-1;
    for(int i=n; i>=1; --i)
    {
        if(s[i]=='?')
        {
            cnt2--;
            suf[cnt2][0]+=suf[cnt2+1][0];
            suf[cnt2][1]+=suf[cnt2+1][1];
        }
        else suf[cnt2][s[i]-'0']++;
    }
    for(int i=1; i<cnt1; ++i) val+=1LL*suf[i][1]*x+1LL*pre[i][1]*y;
    ans=val;
    for(int i=1; i<cnt1; ++i)
    {
        val-=1LL*(pre[i][1]+i-1)*y+1LL*suf[i][1]*x;
        val+=1LL*pre[i][0]*x+1LL*(suf[i][0]+cnt1-i-1)*y;
        ans=min(ans, val); 
    }
    for(int i=1; i<cnt1; ++i)
    {
        val-=1LL*(pre[i][0]+i-1)*x+1LL*suf[i][0]*y;
        val+=1LL*pre[i][1]*y+1LL*(suf[i][1]+cnt1-i-1)*x;
        ans=min(ans, val);
    }
    printf("%lld\n", ans);
    return 0;
}
/*
10001?0011?0??1?1001??001?001?0100??00???0???011?00111???1?1?0?0?0??1?1?1?1?1010?1101?0000?1??11?101
0 1
*/