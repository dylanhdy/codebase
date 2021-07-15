#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, k, ans, fac[MAXN], ifac[MAXN], pos[MAXN], a[MAXN];

void init(int lim)
{
    ifac[0]=ifac[1]=fac[0]=fac[1]=1;
    for(int i=2; i<=lim; i++) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=lim; i++)
    {
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
    scanf("%d%d", &n, &k);
    init(max(n, k));
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        pos[a[i]]=i;
    }
    for(int i=2; i<=n; ++i)
        if(pos[a[i]+1]>pos[a[i-1]+1]) m++;
    for(int i=max(0, n-k); i<=m; ++i)
        ans=(ans+1LL*comb(m, i)*comb(k, n-i)%P)%P;
    printf("%d\n", ans);
    return 0;
}