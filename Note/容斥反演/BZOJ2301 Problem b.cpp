#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 50005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int T, a, b, c, d, k, tot, mu[MAXN], pri[MAXN], vis[MAXN];

void init()
{
    mu[1]=1;
    for(rint i=2; i<=50000; ++i)
    {
        if(!vis[i]) pri[++tot]=i, mu[i]=-1;
        for(rint j=1; j<=tot && pri[j]*i<=50000; ++j)
        {
            vis[pri[j]*i]=1;
            if(i%pri[j]==0) {mu[pri[j]*i]=0; break;}
            else mu[pri[j]*i]=-mu[i];
        }
    }
    for(rint i=2; i<=50000; ++i) mu[i]+=mu[i-1];
}

LL solve(int x, int y)
{
    LL ans=0;
    x/=k, y/=k;
    for(int l=1, r; l<=min(x, y); l=r+1)
    {
        r=min(x/(x/l), y/(y/l));
        ans+=1LL*(mu[r]-mu[l-1])*(x/l)*(y/l);
    }
    return ans;
}

int main()
{
    init();
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        printf("%lld\n", solve(d, b)-solve(a-1, d)-solve(b, c-1)+solve(a-1, c-1));
    }
    return 0;
}
