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
#define MAXN 505
#define MAXM
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

using vi=vector<int>;
constexpr int P(1000000007);

inline int add(int x, int y) {return x+y<P?x+y:x+y-P;}
inline int sub(int x, int y) {return x<y?x-y+P:x-y;}
inline int qpow(int x, int y=P-2)
{
    int num=1;
    for(; y; y>>=1, x=1LL*x*x%P)
        if(y&1) num=1LL*x*num%P;
    return num;
}

int gcd(int x, int y)
{
    return y?gcd(y, x%y):x;
}

int T, n, a[MAXN], f[MAXN*5000];
LL k;

int interp(vi x, vi y, int k)
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

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%lld", &n, &k);
        int lcm=1;
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            lcm=lcm*a[i]/gcd(lcm, a[i]);
        }
        f[0]=1;
        for(int i=1; i<=lcm*(n+1); ++i) f[i]=0;
        for(int i=1; i<=n; ++i)
            for(int j=a[i]; j<=lcm*(n+1); ++j) f[j]=add(f[j], f[j-a[i]]);
        vi x, y;
        for(int i=0; i<=n; ++i) x.PB(i), y.PB(f[i*lcm+k%lcm]);
        printf("%d\n", interp(x, y, k/lcm%P));
    }
    return 0;
}