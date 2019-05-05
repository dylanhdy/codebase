#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 10000000
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int T, x, y, tot, mu[MAXN+10], pri[MAXN+10];
LL ans, h[MAXN+10];
bool vis[MAXN+10];

void init()
{
    mu[1]=1;
    for(rint i=2; i<=MAXN; ++i)
    {
        if(!vis[i]) pri[++tot]=i, mu[i]=-1;
        for(rint j=1; j<=tot && pri[j]*i<=MAXN; ++j)
        {
            vis[pri[j]*i]=1;
            if(i%pri[j]==0) {mu[pri[j]*i]=0; break;}
            else mu[pri[j]*i]=-mu[i];
        }
    }
    for(rint i=1; i<=tot; ++i)
        for(rint j=1; j*pri[i]<=MAXN; ++j) h[j*pri[i]]+=mu[j];
    for(rint i=2; i<=MAXN; ++i) h[i]+=h[i-1];
}

int main()
{
    init();
    scanf("%d", &T);
    while(T--)
    {
        ans=0;
        scanf("%d%d", &x, &y);
        for(int l=1, r; l<=min(x, y); l=r+1)
        {
            r=min(x/(x/l), y/(y/l));
            ans+=1LL*(h[r]-h[l-1])*(x/l)*(y/l);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
