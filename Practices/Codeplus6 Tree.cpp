#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <unordered_map>
#define MAXN 5000005
#define MAXM 1305
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define uint unsigned int
#define LL unsigned long long
#define LD long double
using namespace std;

int T, n, tot, vis[MAXN], pri[MAXN];
LL mu[MAXN], phi[MAXN];

unordered_map<int, LL> muf, phif;

void init()
{
    mu[1]=phi[1]=1;
    for(rint i=2; i<=MAXN-5; ++i)
    {
        if(!vis[i]) pri[++tot]=i, phi[i]=i-1, mu[i]=-1;
        for(rint j=1; j<=tot && pri[j]*i<=MAXN-5; ++j)
        {
            vis[pri[j]*i]=1;
            if(i%pri[j]==0)
            {
                phi[i*pri[j]]=phi[i]*pri[j];
                mu[i*pri[j]]=0;
                break;
            }
            phi[i*pri[j]]=phi[i]*(pri[j]-1);
            mu[i*pri[j]]=-mu[i];
        }
    }
    for(rint i=1; i<=MAXN-5; ++i) phi[i]+=phi[i-1], mu[i]+=mu[i-1];
}

LL mus(int x)
{
    if(x<=MAXN-5) return mu[x];
    if(muf[x]) return muf[x];
    LL sum=1;
    for(uint l=2, r; l<=x; l=r+1)
    {
        r=x/(x/l);
        sum-=1ULL*(r-l+1)*mus(x/l);
    }
    muf[x]=sum;
    return sum;
}

LL phis(int x)
{
    if(x<=MAXN-5) return phi[x];
    if(phif[x]) return phif[x];
    LL sum=1ULL*x*(x+1LL)/2;
    for(uint l=2, r; l<=x; l=r+1)
    {
        r=x/(x/l);
        sum-=1ULL*(r-l+1)*phis(x/l);
    }
    phif[x]=sum; 
    return sum;
}

int main()
{
    init();
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        printf("%lld %lld\n", phis(n), mus(n));
    }
    return 0;
}