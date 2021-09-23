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
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define sz(x) (int)x.size()
#define dbg(a...) fprintf(stderr, a)
using namespace std;

using vi=vector<int>;
constexpr int P(998244353);

inline int add(int x, int y) {return x+y<P?x+y:x+y-P;}
inline int sub(int x, int y) {return x>=y?x-y:x-y+P;}
inline int qpow(int x, int y=P-2)
{
    int num=1;
    for(; y; y>>=1, x=1LL*x*x%P)
        if(y&1) num=1LL*num*x%P;
    return num;
}

void or_fwt(vi &a, int op)
{
    for(int n=sz(a), step=1; step<n; step*=2)
        for(int i=0; i<n; i+=2*step) for(int j=i; j<i+step; ++j) {
            int &u=a[j], &v=a[j+step];
            tie(u, v)=op>0?MP(add(u, v), u):MP(v, sub(u, v));
        }
}

void and_fwt(vi &a, int op)
{
    for(int n=sz(a), step=1; step<n; step*=2)
        for(int i=0; i<n; i+=2*step) for(int j=i; j<i+step; ++j) {
            int &u=a[j], &v=a[j+step];
            tie(u, v)=op>0?MP(v, add(u, v)):MP(sub(v, u), u);
        }
}

void xor_fwt(vi &a, int op)
{
    for(int n=sz(a), step=1; step<n; step*=2)
        for(int i=0; i<n; i+=2*step) for(int j=i; j<i+step; ++j) {
            int &u=a[j], &v=a[j+step];
            tie(u, v)=MP(add(u, v), sub(u, v));
        }
    if(op<0) {
        int inv=qpow(sz(a));
        for(int i=0; i<sz(a); ++i) a[i]=1LL*a[i]*inv%P;
    }
}

vi or_conv(vi a, vi b)
{
    or_fwt(a, 1), or_fwt(b, 1);
    for(int i=0; i<sz(a); ++i) a[i]=1LL*a[i]*b[i]%P;
    or_fwt(a, -1);
    return a;
}

vi and_conv(vi a, vi b)
{
    and_fwt(a, 1), and_fwt(b, 1);
    for(int i=0; i<sz(a); ++i) a[i]=1LL*a[i]*b[i]%P;
    and_fwt(a, -1);
    return a;
}

vi xor_conv(vi a, vi b)
{
    xor_fwt(a, 1), xor_fwt(b, 1);
    for(int i=0; i<sz(a); ++i) a[i]=1LL*a[i]*b[i]%P;
    xor_fwt(a, -1);
    return a;
}

int n;

int main()
{
    scanf("%d", &n);
    vi f(1<<n), g(1<<n);
    for(int i=0; i<1<<n; ++i) scanf("%d", &f[i]);
    for(int i=0; i<1<<n; ++i) scanf("%d", &g[i]);
    vi a=or_conv(f, g);
    for(int e: a) printf("%d ", e);
    printf("\n");
    vi b=and_conv(f, g);
    for(int e: b) printf("%d ", e);
    printf("\n");
    vi c=xor_conv(f, g);
    for(int e: c) printf("%d ", e);
    printf("\n"); 
    return 0;
}