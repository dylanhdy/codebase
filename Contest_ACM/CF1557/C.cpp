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
#define MAXN 200005
#define MAXM
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, k, pw[MAXN], fac[MAXN], ifac[MAXN];;

void init(int lim)
{
    ifac[0]=ifac[1]=fac[0]=fac[1]=1;
    for(int i=2; i<=lim; i++) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=lim; i++) {
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
        fac[i]=1LL*fac[i-1]*i%P;
    }
}

int comb(int x, int y)
{
    if(y>x) return 0;
    return 1LL*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

int qpow(int x, int y)
{
    int num=1;
    while(y) {
        if(y&1) num=1LL*num*x%P;
        x=1LL*x*x%P, y>>=1;
    }
    return num;
}

int solve(int x)
{
    if(x==0) return 1;
    if(n&1) return 1LL*(pw[n-1]+1)*solve(x-1)%P;
    else return (qpow(pw[n], x-1)+1LL*(pw[n-1]-1)*solve(x-1))%P;
}

int main()
{
    pw[0]=1;
    for(int i=1; i<=2e5; ++i) pw[i]=1LL*pw[i-1]*2%P;
    init(2e5);
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &k);
        printf("%d\n", solve(k));
    }
    return 0;
}