#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, k, fac[MAXN], ifac[MAXN];

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

int main()
{
    init(1e5);
    scanf("%d", &T);
    while(T--) {
        int ans=0;
        scanf("%d%d", &n, &k);
        for(int i=1; i<=n/(k-1)+1; ++i) {
            int val1=1LL*ifac[n]*fac[i]%P*fac[n-i]%P;
            ans=(ans+1LL*val1*comb(n-(i-1)*(k-1), i)%P)%P;
        }
        printf("%d\n", ans+1);
    }
    return 0;
}