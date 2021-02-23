#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

LL n, ans, inv1=499122177, inv2=166374059;

inline void add(LL &x, LL y) {x=(x+y<P)?x+y:x+y-P;}
inline void sub(LL &x, LL y) {x=(x>=y)?x-y:x-y+P;}

LL solve(LL x)
{
    return x*(x+1)%P*(2*x+1)%P*inv2%P;
}

int main()
{
    scanf("%lld", &n);
    int lim=sqrt(n);
    for(int i=2; i<=lim; ++i)
    {
        LL last=i, val=i;
        for(int j=1; ; ++j)
        {
            val*=i;
            if(val>n)
            {
                add(ans, (n-last+1)%P*i*j%P);
                break;
            }
            add(ans, (val-last)%P*i*j%P);
            last=val;
        }
    }
    n%=P;
    add(ans, (n+1)*(n+lim+1)%P*(n-lim+P)%P*inv1%P);
    sub(ans, solve(n));
    add(ans, solve(lim));
    printf("%lld\n", ans);
    return 0;
}