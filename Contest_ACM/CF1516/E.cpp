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
#define MAXN 405
#define MAXM
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, k;
LL inv[MAXN], ifac[MAXN], ans[MAXN], f[MAXN][MAXN], g[MAXN][MAXN];

void init(int lim)
{
    inv[0]=inv[1]=ifac[0]=ifac[1]=1;
    for(int i=2; i<=lim; ++i) {
        inv[i]=inv[P%i]*(P-P/i)%P;
        ifac[i]=ifac[i-1]*inv[i]%P;
    }
    for(int i=0; i<=lim; ++i) {
        g[i][0]=1;
        for(int j=1; j<=lim; ++j) g[i][j]=g[i][j-1]*(n-i-j+1)%P;
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    init(2*k);
    f[0][0]=1;
    for(int i=1; i<=k; ++i)
        for(int j=i; j<=k; ++j) {
            for(int x=1; x<=j-i+1; ++x) {
                int tmp=i-1+j-x;
                f[i][j]=(f[i][j]+f[i-1][j-x]*g[tmp][x+1]%P*inv[x+1]%P)%P;
            }
            f[i][j]=f[i][j]*inv[i]%P;
            //printf("%d %d %lld\n", i, j, f[i][j]);
        }
    ans[0]=1;
    for(int i=1; i<=k; ++i) {
        if(i>1) ans[i]=ans[i-2];
        for(int j=1; j<=i; ++j) ans[i]=(ans[i]+f[j][i])%P;
        printf("%lld ", ans[i]);
    }
    return 0;
}