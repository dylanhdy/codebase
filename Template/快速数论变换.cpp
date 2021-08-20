#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 1000005
#define INF 0x3f3f3f3f
#define LL long long
#define LD long double
using namespace std;

using vi=vector<int>;
constexpr int P(998244353), G(3), IG(332748118);

inline int add(int x, int y) {return x+y<P?x+y:x+y-P;}
inline int sub(int x, int y) {return x>=y?x-y:x-y+P;}
inline int qpow(int x, int y)
{
    int num=1;
    for(; y; y>>=1, x=1LL*x*x%P)
        if(y&1) num=1LL*num*x%P;
    return num;
}

namespace Polynomial {
    int bit, pos[MAXN*4];

    void init(int n)
    {
        while(1<<bit<n) bit++;
        for(int i=0; i<1<<bit; ++i)
            pos[i]=(pos[i>>1]|(i&1)<<bit)>>1;
    }

    void ntt(vi &a, int op)
    {
        int n=a.size();
        for(int i=0; i<n; ++i)
            if(pos[i]>i) swap(a[pos[i]], a[i]);
        for(int i=1; i<n; i<<=1) {
            int wn=qpow(op>0?G:IG, (P-1)/(i<<1));
            for(int j=0; j<n; j+=(i<<1)) 
                for(int k=0, w=1; k<i; ++k, w=1LL*w*wn%P) {
                    int x=a[j+k], y=1LL*a[i+j+k]*w%P;
                    a[j+k]=add(x, y), a[i+j+k]=sub(x, y);
                }
        }
        if(op==-1) {
            int inv=qpow(n, P-2);
            for(int i=0; i<n; ++i) a[i]=1LL*a[i]*inv%P;
        }
    }

    vi mul(vi a, vi b)
    {
        int n=a.size(), m=b.size();
        init(n+m-1);
        a.resize(1<<bit), b.resize(1<<bit);
        ntt(a, 1), ntt(b, 1);
        for(int i=0; i<1<<bit; ++i) a[i]=1LL*a[i]*b[i]%P;
        ntt(a, -1);
        a.resize(n+m-1);
        return a;
    }
}

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    vi a(n+1), b(m+1);
    for(int i=0; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=0; i<=m; ++i) scanf("%d", &b[i]);
    a=Polynomial::mul(a, b);
    for(int i=0; i<=n+m; ++i) printf("%d ", a[i]);
    return 0;
}