#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 100005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, p, a[20][20], last[20], num[20], tag[20][20][(1<<17)+5], f[(1<<17)+5];
char s[MAXN];

int main()
{
    scanf("%d%d", &n, &p);
    scanf("%s", s);
    for(rint i=0; i<p; ++i)
        for(rint j=0; j<p; ++j) scanf("%d", &a[i][j]);
    memset(last, -1, sizeof(last));
    for(rint i=0; i<n; ++i)
    {
        int ch=s[i]-'a';
        num[ch]++;
        for(rint j=0; j<p; ++j)
        {
            int sta=(1<<p)-1;
            if(a[ch][j] || last[j]==-1) continue;
            for(rint k=0; k<p; ++k)
                if(k!=ch && last[k]>last[j]) sta^=(1<<k);
            tag[ch][j][sta]=1;
        }
        last[ch]=i;
    }
    for(rint i=0; i<p; ++i)
        for(rint j=0; j<p; ++j)
            for(rint sta=(1<<p)-1; sta>0; sta--)
            {
                if(!tag[i][j][sta]) continue;
                for(rint k=0; k<p; ++k)
                    if(k!=i && k!=j && (sta>>k)&1) tag[i][j][sta^(1<<k)]=1;
                f[sta]=n;
            }
    for(rint sta=1; sta<(1<<p); ++sta)
    {
        if(f[sta]==n) continue;
        for(rint i=0; i<p; ++i)
            if((sta>>i)&1) f[sta]+=num[i];
        for(rint i=0; i<p; ++i)
            if((sta>>i)&1) f[sta]=min(f[sta], f[sta^(1<<i)]);
    }
    printf("%d\n", f[(1<<p)-1]);
    return 0;
}
