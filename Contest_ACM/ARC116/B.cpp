#include <bits/stdc++.h>
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

int n, ans, inv2[MAXN], pow2[MAXN], val[MAXN], a[MAXN];

int ksm(int x, int y)
{
    int num=1;
    while(y) {
        if(y&1) num=1LL*num*x%P;
        x=1LL*x*x%P; y>>=1;
    }
    return num;
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    inv2[0]=pow2[0]=1;
    int inv=ksm(2, P-2);
    for(int i=1; i<=n; ++i) {
        pow2[i]=1LL*pow2[i-1]*2%P;
        inv2[i]=1LL*inv2[i-1]*inv%P;
    }
    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i) {
        ans=(ans+1LL*a[i]*pow2[i]%P*val[i-1]%P)%P;
        val[i]=(val[i-1]+1LL*a[i]*inv2[i+1]%P)%P;
    }
    for(int i=1; i<=n; ++i) ans=(ans+1LL*a[i]*a[i]%P)%P;
    printf("%d\n", ans);
    return 0;
}