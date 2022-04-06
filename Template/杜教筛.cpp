#include <cstdio>
#include <algorithm>
using namespace std;

using ll=long long;
constexpr int LIM=5e6, INF=0x3f3f3f3f;

int T, n, tot, pri[1000000], vis[LIM];
ll phi[LIM], mu[LIM], visp[500], vism[500];

void init()
{
    mu[1]=phi[1]=1;
    for(int i=2; i<LIM; ++i) {
        if(!vis[i]) pri[++tot]=i, phi[i]=i-1, mu[i]=-1;
        for(int j=1; j<=tot && pri[j]*i<LIM; ++j) {
            vis[pri[j]*i]=1;
            if(i%pri[j]==0) {
                phi[i*pri[j]]=phi[i]*pri[j];
                mu[i*pri[j]]=0;
                break;
            }
            phi[i*pri[j]]=phi[i]*(pri[j]-1);
            mu[i*pri[j]]=-mu[i];
        }
    }
    for(int i=2; i<LIM; ++i) phi[i]+=phi[i-1], mu[i]+=mu[i-1];
}

ll cal_phi(ll x)
{
    if(x<LIM) return phi[x];
    if(visp[n/x]!=-INF) return visp[n/x];
    ll sum=x*(x+1)/2;
    for(ll l=2, r; l<=x; l=r+1) {
        r=x/(x/l);
        sum-=cal_phi(x/l)*(r-l+1);
    }
    return visp[n/x]=sum;
}

ll cal_mu(ll x)
{
    if(x<LIM) return mu[x];
    if(vism[n/x]!=-INF) return vism[n/x];
    ll sum=1;
    for(ll l=2, r; l<=x; l=r+1) {
        r=x/(x/l);
        sum-=cal_mu(x/l)*(r-l+1);
    }
    return vism[n/x]=sum;
}

int main()
{
    init();
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=1; i<=n/LIM; ++i) visp[i]=vism[i]=-INF;
        printf("%lld %lld\n", cal_phi(n), cal_mu(n));
    }
}