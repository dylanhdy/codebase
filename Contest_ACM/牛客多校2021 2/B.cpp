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
#define MAXN 10000005
#define MAXM
#define P 1000000009
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m;
LL ans1, ans2, pre1, pre2, pw[MAXN], ifac[MAXN], fac[MAXN];

void init(int lim)
{
    ifac[0]=ifac[1]=fac[0]=pw[0]=1;
    for(int i=2; i<=lim; ++i) ifac[i]=ifac[P%i]*(P-P/i)%P;
    for(int i=1; i<=lim; ++i) {
        pw[i]=pw[i-1]*2%P;
        ifac[i]=ifac[i-1]*ifac[i]%P;
        fac[i]=fac[i-1]*i%P;
    }
}

int comb(int x, int y)
{
    return fac[x]*ifac[y]%P*ifac[x-y]%P;
}

int main()
{
    scanf("%d%d", &n, &m);
    if(n<m) swap(n, m);
    n-=2, m-=2;
    init(n+m);
    for(int i=0; i<=m+n; ++i) ans1^=pw[i]*fac[n+m]%P*ifac[n+m-i]%P;
    for(int i=m+n; i>n; --i) {
        ans2^=pw[n+m]*fac[n]%P*fac[m]%P*ifac[n+m-i]%P;
        //printf("%lld ", pw[n+m]*fac[n]%P*fac[m]%P*ifac[n+m-i]%P);
    }
    pre1=pw[m];
    for(int i=n; i>m; --i) {
        ans2^=pw[i]*fac[n]%P*fac[m]%P*ifac[n+m-i]%P*pre1%P;
        //printf("%lld ", pw[i]*fac[n]%P*fac[m]%P*ifac[n+m-i]%P*pre1%P);
        pre1=(2*pre1-comb(n+m-i, m)+P)%P;
    }
    for(int i=m; i>=0; --i) {
        ans2^=pw[i]*fac[n]%P*fac[m]%P*ifac[n+m-i]%P*(pre1-pre2+P)%P;
        //printf("%lld ", pw[i]*fac[n]%P*fac[m]%P*ifac[n+m-i]%P*(pre1-pre2+P)%P);
        pre1=(2*pre1-comb(n+m-i, m)+P)%P;
        pre2=(2*pre2-comb(n+m-i, m-i-1)+comb(n+m-i+1, m-i)+P)%P;
    }
    printf("%lld %lld\n", ans1, ans2);
    return 0;
}