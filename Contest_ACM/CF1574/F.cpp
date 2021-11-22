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
#define MAXN 300005
#define MAXM
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

using vi=vector<int>;
constexpr int P(998244353), G(3), IG(332748118);

inline int add(int x, int y) {return x+y<P?x+y:x+y-P;}
inline int sub(int x, int y) {return x>=y?x-y:x-y+P;}
inline int qpow(int x, int y=P-2)
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

    vi inv(vi a)
    {
        int n=a.size(), m=(n+1)>>1;
        if(n==1) return {qpow(a[0])};
        vi b=inv(vi(a.begin(), a.begin()+m));
        init(n<<1);
        a.resize(1<<bit); b.resize(1<<bit);
        ntt(a, 1); ntt(b, 1);
        for(int i=0; i<1<<bit; ++i)
            b[i]=1LL*(2+P-1LL*a[i]*b[i]%P)*b[i]%P;
        ntt(b, -1);
        return vi(b.begin(), b.begin()+n);
    }
}

int n, m, k, tag[MAXN], from[MAXN], to[MAXN];

int dfs(int x)
{
    if(tag[x]) return -1;
    if(!to[x]) return 1;
    int tmp=dfs(to[x]);
    return tmp==-1?-1:tmp+1;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; ++i) {
        int c, x, last;
        scanf("%d", &c);
        for(int j=1; j<=c; ++j) {
            scanf("%d", &x);
            if(j>1) {
                if((from[x] && from[x]!=last) || (to[last] && to[last]!=x)) {
                    tag[last]=tag[x]=1;
                    continue;
                }
                from[x]=last, to[last]=x;
            }
            last=x;
        }
    }
    vi g(m+1);
    for(int i=1; i<=k; ++i)
        if(!from[i]) {
            int tmp=dfs(i);
            if(tmp!=-1 && tmp<=m) g[tmp]=sub(g[tmp], 1);
        }
    g[0]=1;
    vi f=Polynomial::inv(g);
    printf("%d\n", f[m]);
    return 0;
}