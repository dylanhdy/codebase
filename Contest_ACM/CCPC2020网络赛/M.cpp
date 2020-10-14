#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P 998244353
#define G 3
#define INF 0x3f3f3f3f
#define mid ((l+r)>>1)
using namespace std;

int t, n, a[MAXN<<2], b[MAXN<<2], c[MAXN<<2], u[MAXN<<2], v[MAXN<<2], pos[MAXN<<2], fac[MAXN], ifac[MAXN];

void init()
{
    ifac[0]=fac[0]=ifac[1]=fac[1]=1;
    for(int i=2; i<=100000; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=100000; ++i)
    {
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
        fac[i]=1LL*fac[i-1]*i%P;
    }
}

int ksm(int x, int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=1LL*x*ans%P;
        x=1LL*x*x%P, y>>=1;
    }
    return ans;
}

void ntt(int f[], int n, int op)
{
    for(int i=0; i<n; ++i)
        if(pos[i]>i) swap(f[pos[i]], f[i]);
    for(int i=1; i<n; i<<=1)
    {
        int wn=ksm(G, op>0?(P-1)/(i<<1):P-1-(P-1)/(i<<1));
        for(int j=0; j<n; j+=(i<<1))
            for(int k=0, w=1; k<i; ++k, w=1LL*w*wn%P)
            {
                int x=f[j+k], y=1LL*f[i+j+k]*w%P;
                f[j+k]=(x+y)%P, f[i+j+k]=(x-y+P)%P;
            }
    }
    if(op>0) return;
    int inv=ksm(n, P-2);
    for(int i=0; i<n; ++i) f[i]=1LL*f[i]*inv%P;
}

void divide(int f[], int l, int r)
{
    if(l==r)
    {
        f[0]=c[l], f[1]=b[l];
        return;
    }
    int bit=0;
    while((1<<bit)<=(r-l+1)) bit++;
    int g[(1<<bit)+5], h[(1<<bit)+5];
    for(int i=0; i<(1<<bit); ++i) g[i]=h[i]=0;
    divide(g, l, mid), divide(h, mid+1, r);
    for(int i=0; i<(1<<bit); ++i) pos[i]=(pos[i>>1]>>1)|((i&1)<<(bit-1));
    ntt(g, 1<<bit, 1), ntt(h, 1<<bit, 1);
    for(int i=0; i<(1<<bit); ++i) f[i]=1LL*g[i]*h[i]%P;
    ntt(f, 1<<bit, -1);
}

int main()
{
    init();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0; i<=n; ++i) scanf("%d", &a[i]);
        for(int i=0; i<n-1; ++i) scanf("%d", &b[i]);
        for(int i=0; i<n-1; ++i) scanf("%d", &c[i]);
        divide(u, 0, n-2);
        reverse(u, u+n);
        for(int i=0; i<=n; ++i) a[i]=1LL*a[i]*fac[i]%P;
        int bit=0;
        while((1<<bit)<n*2) bit++;
        for(int i=0; i<(1<<bit); ++i) pos[i]=(pos[i>>1]>>1)|((i&1)<<(bit-1));
        ntt(a, 1<<bit, 1), ntt(u, 1<<bit, 1);
        for(int i=0; i<(1<<bit); ++i) v[i]=1LL*a[i]*u[i]%P;
        ntt(v, 1<<bit, -1);
        for(int i=0; i<=n; ++i)
        {
            if(i) printf(" ");
            printf("%lld", 1LL*v[i+n-1]*ifac[i]%P);
        }
        printf("\n");
        for(int i=0; i<(1<<bit); ++i) a[i]=u[i]=v[i]=0;
    }
    return 0;
}