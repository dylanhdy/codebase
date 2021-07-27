#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define LD long double
#define MAXN 1000005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, k, cnt, vis[MAXN], pri[MAXN], phi[MAXN];
LL ans, fac[MAXN], ifac[MAXN], pw[MAXN];

LL qpow(LL x, LL y)
{
    LL num=1;
    while(y) {
        if(y&1) num=num*x%P;
        x=x*x%P, y>>=1;
    }
    return num;
}

void init(int lim)
{
    pw[0]=ifac[0]=ifac[1]=fac[0]=fac[1]=1;
    for(int i=2; i<=lim; i++) ifac[i]=ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=lim; i++) {
        ifac[i]=ifac[i-1]*ifac[i]%P;
        fac[i]=fac[i-1]*i%P;
    }
    for(int i=1; i<=lim; ++i) pw[i]=pw[i-1]*2%P;
    for(int i=2; i<=lim; ++i) {
        if(!vis[i]) pri[++cnt]=i, phi[i]=i-1;
        for(int j=1; j<=cnt && i*pri[j]<=lim; ++j) {
            vis[i*pri[j]]=1;
            if(i%pri[j]==0) {
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
            phi[i*pri[j]]=phi[i]*(pri[j]-1);
        }
    }
}

int comb(int x, int y)
{
    if(y>x || x<0) return 0;
    return fac[x]*ifac[y]%P*ifac[x-y]%P;
}

LL f(int x, int y)
{
    if(!y) return 2*(x%2==0);
    return pw[y]*(comb(x-y-1, y-1)+comb(x-y, y))%P;
}

int main()
{
    scanf("%d", &T);
    init(1e6);
    while(T--) {
        ans=0;
        scanf("%d%d", &n, &k);
        k=min(k, n);
        for(int j=0; j<=k; ++j) ans=(ans+f(n, j))%P;
        for(int i=1; i<n; ++i)
            if(n%i==0) {
                LL tmp=0, up=1LL*k*i/n;
                for(int j=0; j<=up; ++j) tmp=(tmp+f(i, j))%P;
                ans=(ans+tmp*phi[n/i])%P;
            }
        printf("%lld\n", ans*qpow(n, P-2)%P);
    }
    return 0;
}