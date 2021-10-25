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
#define MAXN 100005
#define P 998244353
#define G 3
#define IG 332748118
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

using vi = vector<int>;

int T, n, ans, v[MAXN], pos[MAXN*4], fac[MAXN], ifac[MAXN];

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

inline int qpow(int x, int y=P-2)
{
    int num=1;
    while(y) {
        if(y&1) num=1LL*num*x%P;
        x=1LL*x*x%P, y>>=1;
    }
    return num;
}
inline void inc(int &x, int y) { (x += y) >= P ? x -= P : 0; }
inline int sum(int x, int y) { return x + y >= P ? x + y - P : x + y; }
inline int sub(int x, int y) { return x - y < 0 ? x - y + P : x - y; }

vector<int> w;
void getOmega(int k) {
  w.resize(k);
  w[0] = 1;
  int base = qpow(G, (P - 1) / (k << 1));
  for (int i = 1; i < k; i++) w[i] = 1LL * w[i - 1] * base % P;
}
void dft(vector<int> &a, int n) {
  for (int k = n >> 1; k; k >>= 1) {
    getOmega(k);
    for (int i = 0; i < n; i += k << 1) {
      for (int j = 0; j < k; j++) {
        int y = a[i + j + k];
        a[i + j + k] = (1LL * a[i + j] - y + P) * w[j] % P;
        inc(a[i + j], y);
      }
    }
  }
}
void idft(vector<int> &a, int n) {
  for (int k = 1; k < n; k <<= 1) {
    getOmega(k);
    for (int i = 0; i < n; i += k << 1) {
      for (int j = 0; j < k; j++) {
        int x = a[i + j], y = 1LL * a[i + j + k] * w[j] % P;
        a[i + j] = sum(x, y);
        a[i + j + k] = sub(x, y);
      }
    }
  }
  int inv = qpow(n, P-2);
  for (int i = 0; i < n; i++) a[i] = 1LL * a[i] * inv % P;
  reverse(a.begin() + 1, a.begin()+n);
}


void divide(vector<int> &a, int l, int r)
{
    if(l==r) {a={1, v[l]}; return;}
    int mid=(l+r)>>1, bit=0;
    while((1<<bit)<=r-l+1) bit++;
    vector<int> b((1<<bit)+5), c((1<<bit)+5);
    divide(b, l, mid), divide(c, mid+1, r);
    dft(b, 1<<bit), dft(c, 1<<bit);
    for(int i=0; i<1<<bit; ++i) a[i]=1LL*b[i]*c[i]%P;
    idft(a, 1<<bit);
}

int main()
{
    init(1e5);
    scanf("%d", &T);
    while(T--) {
        ans=0;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &v[i]);
        vi a(n*2);
        divide(a, 1, n);
        for(int i=1; i<=n; ++i) ans=(ans+1LL*a[i]*qpow(comb(n, i)))%P;
        printf("%d\n", ans);
    }
    return 0;
}