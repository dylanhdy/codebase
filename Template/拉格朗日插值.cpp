#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#define LL long long
#define LD long double
#define MAXN 2005
#define MAXM
#define MP make_pair
#define PB push_back
#define dbg(a...) fprintf(stderr, a)
using namespace std;

using vi=vector<int>;
constexpr int P(9999991);

inline int add(int x, int y) {return x+y<P?x+y:x+y-P;}
inline int sub(int x, int y) {return x<y?x-y+P:x-y;}
inline int qpow(int x, int y=P-2)
{
    int num=1;
    for(; y; y>>=1, x=1LL*x*x%P)
        if(y&1) num=1LL*x*num%P;
    return num;
}

int T, n, k, fac[MAXN], ifac[MAXN];

void init(int lim)
{
    ifac[0]=ifac[1]=1;
    for(int i=2; i<=lim; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=lim; ++i) ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
}

int interp1(vi x, vi y, int k)
{
    int n=x.size(), ans=0;
    for(int i=0; i<n; ++i) {
        int up=y[i], down=1;
        for(int j=0; j<n; ++j) {
            if(i==j) continue;
            up=1LL*up*sub(k, x[j])%P;
            down=1LL*down*sub(x[i], x[j])%P;
        }
        ans=(ans+1LL*up*qpow(down))%P;
    }
    return ans;
}

int interp2(vi y, int k)
{
    int n=y.size(), ans=0;
    vi pre(n), suf(n);
    pre[0]=suf[n-1]=1;
    for(int i=0; i<n-1; ++i) pre[i+1]=1LL*pre[i]*sub(k, i)%P;
    for(int i=n-1; i>=1; --i) suf[i-1]=1LL*suf[i]*sub(k, i)%P;
    for(int i=0; i<n; ++i) {
        int up=1LL*y[i]*pre[i]%P*suf[i]%P;
        int down=1LL*ifac[i]*((n-i)&1?ifac[n-i-1]:P-ifac[n-i-1])%P;
        ans=(ans+1LL*up*down)%P;
    }
    return ans;
}

int main()
{
    init(2001);
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &k); //k>=0 && k<P
        vi x(n+1), y(n+1);
        for(int i=0; i<=n; ++i) scanf("%d%d", &x[i], &y[i]);
        printf("%d\n", interp1(x, y, k));
    }
    return 0;
}