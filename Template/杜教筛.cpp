#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <unordered_map>
#define LL long long
#define LD long double
#define MAXN 5000005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int T, n, tot, vis[MAXN], pri[MAXN];
LL mu[MAXN], phi[MAXN];

unordered_map<int, LL> muf, phif;

void init()
{
    mu[1]=phi[1]=1;
    for(int i=2; i<=5e6; ++i)
    {
        if(!vis[i]) pri[++tot]=i, phi[i]=i-1, mu[i]=-1;
        for(int j=1; j<=tot && pri[j]*i<=5e6; ++j)
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
    for(int i=1; i<=5e6; ++i) phi[i]+=phi[i-1], mu[i]+=mu[i-1];
}

LL mus(int x)
{
    if(x<=5e6) return mu[x];
    if(muf[x]) return muf[x];
    LL sum=1;
    for(uint l=2, r; l<=x; l=r+1)
    {
        r=x/(x/l);
        sum-=1LL*(r-l+1)*mus(x/l);
    }
    muf[x]=sum;
    return sum;
}

LL phis(int x)
{
    if(x<=5e6) return phi[x];
    if(phif[x]) return phif[x];
    LL sum=1LL*x*(x+1)/2;
    for(uint l=2, r; l<=x; l=r+1)
    {
        r=x/(x/l);
        sum-=1LL*(r-l+1)*phis(x/l);
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