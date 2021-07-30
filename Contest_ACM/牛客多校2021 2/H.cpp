#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define LD long double
#define MAXN 600005
#define P 998244353
#define G 3
#define IG 332748118
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, k, val[MAXN], pos[MAXN*2], pre[MAXN], fac[MAXN*2], ifac[MAXN*2];
vector<int> f(MAXN*2);
char s[MAXN];

void init(int lim)
{
    ifac[0]=ifac[1]=fac[0]=fac[1]=1;
    for(int i=2; i<=lim; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=lim; ++i) {
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
        fac[i]=1LL*fac[i-1]*i%P;
    }
}

inline int comb(int x, int y)
{
    return 1LL*fac[x]*ifac[x-y]%P*ifac[y]%P;
}

inline int fpow(int x, int y)
{
    int num=1;
    while(y) {
        if(y&1) num=1LL*num*x%P;
        x=1LL*x*x%P, y>>=1;
    }
    return num;
}

void ntt(vector<int> &a, int n, int op)
{
    for(int i=0; i<n; ++i)
        if(pos[i]>i) swap(a[pos[i]], a[i]);
    for(int i=1; i<n; i<<=1) {
        int wn=fpow(op>0?G:IG, (P-1)/(i<<1));
        for(int j=0; j<n; j+=(i<<1))
            for(int k=0, w=1; k<i; ++k, w=1LL*w*wn%P) {
                int x=a[j+k], y=1LL*a[i+j+k]*w%P;
                a[j+k]=(x+y)%P, a[i+j+k]=(x-y+P)%P;
            }
    }
    if(op>0) return;
    int inv=fpow(n, P-2);
    for(int i=0; i<n; ++i) a[i]=1LL*a[i]*inv%P;
}

void divide(vector<int> &a, int l, int r)
{
    if(l==r) {
        int fac2=1;
        for(int i=0; i<=val[l]; ++i) {
            if(i>0) fac2=1LL*fac2*(2*i-1)%P;
            a[i]=1LL*comb(val[l]+i, val[l]-i)*fac2%P*ifac[i]%P;    
        }
        return;
    }
    int mid=(l+r)>>1, bit=0;
    while((1<<bit)<=pre[r]-pre[l-1]) bit++;
    vector<int> b((1<<bit)+5), c((1<<bit)+5);
    divide(b, l, mid), divide(c, mid+1, r);
    for(int i=0; i<1<<bit; ++i)
        pos[i]=(pos[i>>1]>>1)|((i&1)<<(bit-1));
    ntt(b, 1<<bit, 1), ntt(c, 1<<bit, 1);
    for(int i=0; i<1<<bit; ++i) a[i]=1LL*b[i]*c[i]%P;
    ntt(a, 1<<bit, -1);
}

int main()
{
    scanf("%d%d%s", &n, &k, s+1);
    init(n*2);
    int cnt=0;
    for(int i=1; i<=n; ++i) {
        if(s[i]=='1') cnt++;
        if(s[i]=='0' && s[i-1]=='0' && cnt) {
            val[++m]=cnt;
            cnt=0;
        }
    }
    if(cnt) val[++m]=cnt;
    for(int i=1; i<=m; ++i) pre[i]=pre[i-1]+val[i];
    divide(f, 1, m);
    printf("%lld\n", 1LL*fac[k]*f[k]%P);
    return 0;
}
/*
11 2
10101000101
*/