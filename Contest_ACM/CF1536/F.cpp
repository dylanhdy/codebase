#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 1000005
#define MAXM
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, ans, fac[MAXN], ifac[MAXN], inv[MAXN];

void init()
{
    inv[0]=inv[1]=fac[0]=ifac[0]=1;
    for(int i=2; i<=n; i++) inv[i]=1LL*inv[P%i]*(P-P/i)%P;
    for(int i=1; i<=n; i++)
    {
        ifac[i]=1LL*ifac[i-1]*inv[i]%P;
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
    scanf("%d", &n);
    init();
    for(int i=(n%2); 2*i<=n; i+=2) {
        int tmp=1;
        if(i) tmp=1LL*n*inv[i]%P*comb(n-i-1, i-1)%P;
        ans=(ans+1LL*fac[n-i]*tmp%P)%P;
    }
    printf("%d\n", ans*2%P);
    return 0;
}