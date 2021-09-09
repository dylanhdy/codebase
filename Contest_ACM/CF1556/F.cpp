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
#define MAXN
#define MAXM
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, ans, a[20], g[15][200005], f[200005];

inline int qpow(int x, int y=P-2)
{
    int num=1;
    for(; y; y>>=1, x=1LL*x*x%P)
        if(y&1) num=1LL*num*x%P;
    return num;
}
inline int dec(int x, int y) {return x<y?x-y+P:x-y;}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &a[i]);
    for(int i=0; i<n; ++i)
        for(int sta=0; sta<(1<<n); ++sta)
            if(!((sta>>i)&1)) {
                if(!sta) g[i][sta]=1;
                else {
                    int bit=31-__builtin_clz(sta);
                    g[i][sta]=1LL*g[i][sta^(1<<bit)]*a[i]%P*qpow(a[i]+a[bit])%P;
                }
            }
    for(int sta=0; sta<(1<<n); ++sta) {
        f[sta]=1;
        for(int sub=(sta-1)&sta; sub; sub=(sub-1)&sta) {
            int tmp=sta^sub, val=1;
            for(int i=0; i<n; ++i)
                if((tmp>>i)&1) val=1LL*val*g[i][sub]%P;
            f[sta]=dec(f[sta], 1LL*f[sub]*val%P);
        }
        int tmp=((1<<n)-1)^sta, val=1, siz=0;
        for(int i=0; i<n; ++i) {
            if((sta>>i)&1) {
                siz++;
                val=1LL*val*g[i][tmp]%P;
            }
        }
        ans=(ans+1LL*f[sta]*val%P*siz)%P;
    }
    printf("%d\n", ans);
    return 0;
}