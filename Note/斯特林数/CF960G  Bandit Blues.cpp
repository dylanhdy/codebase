#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 100005
#define P 998244353
#define G 3
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, A, B, f[MAXN<<2], pos[MAXN<<2], b[MAXN<<2], c[MAXN<<2], d[MAXN<<2], fac[MAXN], ifac[MAXN];

inline int add(int x, int y) {return x+y>=P?x+y-P:x+y;}
inline int sub(int x, int y) {return x>=y?x-y:x-y+P;}

inline int ksm(int x, int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=1LL*x*ans%P;
        x=1LL*x*x%P, y>>=1;
    }
    return ans;
}

void init()
{
    ifac[0]=fac[0]=ifac[1]=fac[1]=1;
    for(rint i=2; i<=n; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(rint i=2; i<=n; ++i)
    {
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
        fac[i]=1LL*fac[i-1]*i%P;
    }
}

inline int comb(int x, int y)
{
    return 1LL*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

void ntt(int a[], int n, int op)
{
    for(rint i=0; i<n; ++i)
        if(pos[i]>i) swap(a[pos[i]], a[i]);
    for(rint i=1; i<n; i<<=1)
    {
        int wn=ksm(G, op>0?(P-1)/(i<<1):P-1-(P-1)/(i<<1));
        for(rint j=0; j<n; j+=(i<<1))
            for(rint k=0, w=1; k<i; ++k, w=1LL*w*wn%P)
            {
                int x=a[j+k], y=1LL*a[i+j+k]*w%P;
                a[j+k]=add(x, y), a[i+j+k]=sub(x, y);
            }
    }
    if(op>0) return;
    int inv=ksm(n, P-2);
    for(rint i=0; i<n; ++i) a[i]=1LL*a[i]*inv%P;
}

void divide(int a[], int l, int r)
{
    if(l==r) {a[0]=0, a[1]=1; return;}
    int mid=r>>1, bit=0;
    divide(a, l, mid);
    while((1<<bit)<=(r-l+1)) bit++;
    for(rint i=0; i<1<<bit; ++i)
    {
        pos[i]=(pos[i>>1]>>1)|((i&1)<<(bit-1));
        b[i]=c[i]=d[i]=0;
    }
    for(rint i=0, t=1; i<=mid; ++i, t=1LL*t*mid%P)
    {
        d[mid-i]=1LL*t*ifac[i]%P;
        c[i]=1LL*a[i]*fac[i]%P;
    }
    ntt(c, 1<<bit, 1), ntt(d, 1<<bit, 1);
    for(rint i=0; i<1<<bit; ++i) c[i]=1LL*c[i]*d[i]%P;
    ntt(c, 1<<bit, -1);
    for(rint i=0; i<=mid; ++i) b[i]=1LL*c[i+mid]*ifac[i]%P;
    ntt(a, 1<<bit, 1), ntt(b, 1<<bit, 1);
    for(rint i=0; i<1<<bit; ++i) a[i]=1LL*a[i]*b[i]%P;
    ntt(a, 1<<bit, -1);
    if(r%2==0) return;
    for(rint i=r-1; i>=0; --i) a[i+1]=add(a[i], 1LL*a[i+1]*(r-1)%P);
}

int main()
{
    scanf("%d%d%d", &n, &A, &B);
    if(!A || !B || A+B-2>n-1) {printf("0\n"); return 0;}
    if(n==1) {printf("1\n"); return 0;}
    init();
    divide(f, 1, n-1);
    printf("%lld\n", 1LL*f[A+B-2]*comb(A+B-2, A-1)%P);
    return 0;
}