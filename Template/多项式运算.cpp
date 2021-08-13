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
#define P 998244353
#define G 3
#define IG 332748118
using namespace std;

using vi=vector<int>;

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

    vi inverse(vi a)
    {
        int n=a.size();
        if(n==1) return {qpow(a[0], P-2)};
        vi b=inverse(vi(a.begin(), a.begin()+((n+1)>>1)));
        init(n<<1);
        a.resize(1<<bit), b.resize(1<<bit);
        ntt(a, 1), ntt(b, 1);
        for(int i=0; i<1<<bit; ++i)
            b[i]=1LL*sub(2, 1LL*a[i]*b[i]%P)*b[i]%P;
        ntt(b, -1);
        b.resize(n);
        return b;
    }

    vi div(vi a, vi b)
    {
        int n=a.size(), m=b.size();
        init((n-m+1)<<1);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        a.resize(1<<bit), b.resize(1<<bit);
        b=inverse(b);
        ntt(a, 1), ntt(b, 1);
        for(int i=0; i<1<<bit; ++i) a[i]=1LL*a[i]*b[i]%P;
        ntt(a, -1);
        a.resize(n-m+1);
        reverse(a.begin(), a.end());
        return a;
    }

    vi mod(vi a, vi b)
    {
        int n=a.size(), m=b.size();
        vi c=div(a, b);
        init(n);
        b.resize(1<<bit), c.resize(1<<bit);
        ntt(b, 1), ntt(c, 1);
        for(int i=0; i<1<<bit; ++i) b[i]=1LL*b[i]*c[i];
        ntt(b, -1);
        a.resize(m-1);
        for(int i=0; i<m-1; ++i) a[i]=sub(a[i], b[i]);
        return a;
    }

    vi deriv(vi a)
    {
        int n=a.size();
        for(int i=0; i<n-1; ++i) a[i]=1LL*a[i+1]*(i+1)%P;
        a.resize(n-1);
        return a;
    }

    vi integ(vi a, int c=0)
    {
        int n=a.size();
        a.resize(n+1);
        vi inv(n+1);
        inv[0]=inv[1]=1;
        for(int i=2; i<=n; ++i) inv[i]=1LL*inv[P%i]*(P-P/i)%P;
        for(int i=n; i>=1; --i) a[i]=1LL*a[i-1]*inv[i]%P;
        a[0]=c;
        return a;
    }

    vi ln(vi a)
    {
        int n=a.size();
        vi b=inverse(a), c=deriv(a);
        init(n<<1);
        b.resize(1<<bit), c.resize(1<<bit);
        ntt(b, 1), ntt(c, 1);
        for(int i=0; i<1<<bit; ++i) b[i]=1LL*b[i]*c[i]%P;
        ntt(b, -1);
        b.resize(n-1);
        return integ(b);
    }

    vi exp(vi a)
    {
        int n=a.size();
        if(n==1) return {1};
        vi b=Polynomial::exp(vi(a.begin(), a.begin()+((n+1)>>1)));
        b.resize(n);
        vi c=ln(b);
        init(n<<1);
        b.resize(1<<bit), c.resize(1<<bit);
        for(int i=0; i<n; ++i) c[i]=sub(a[i], c[i]);
        c[0]=add(c[0], 1);
        ntt(b, 1), ntt(c, 1);
        for(int i=0; i<1<<bit; ++i) b[i]=1LL*b[i]*c[i]%P;
        ntt(b, -1);
        b.resize(n);
        return b;
    }

    vi qpow(vi a, int k)
    {
        int n=a.size();
        vi b=ln(a);
        for(int i=0; i<n; ++i) b[i]=1LL*b[i]*k%P;
        b=exp(b);
        return b;
    }
}

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    n++, m++;
    vi a(n), b(m);
    vi c=Polynomial::div(a, b);
    vi d=Polynomial::mod(a, b);
    for(int e: c) printf("%d ", e);
    printf("\n");
    for(int e: d) printf("%d ", e);
}