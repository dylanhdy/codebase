#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <array>
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
using namespace std;

template<class T> using vc = vector<T>;
using ll = int64_t;
constexpr ll md = 998244353, root = 62, LIM = 1 << 18;
struct Mod {
  ll x;
  Mod(ll x = 0): x(x) {}
  Mod operator+(Mod b) {ll y=x+b.x;return y<md ? y : y - md; }
  Mod operator-(Mod b) { return x - b.x + (x < b.x ? md : 0); }
  Mod operator*(Mod b) { return x * b.x % md; }
  void operator += (Mod b) { x += b.x; x < md ?: x -= md; }
  void operator *= (Mod b) { (x *= b.x) %= md; }
  void operator -= (Mod b) { x -= b.x; -x < 0 ?: x += md; }
};
Mod qpow(Mod b, ll e) {
    Mod res = 1;
    for (; e; b *= b, e /= 2)
        if (e & 1) res *= b;
    return res;
}

void ntt(vc<Mod> &a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vc<Mod> rt(2, 1);
    for (static int k = 2, s = 2; k < n; k *= 2, ++s) {
        rt.resize(n);
        array<Mod, 2> z{1, qpow(root, md >> s)};
        for (int i = k; i < k * 2; ++i) 
            rt[i] = rt[i / 2] * z[i & 1];
    }
    vc<int> rev(n);
    for (int i = 0; i < n; ++i)
        rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for (int i = 0; i < n; ++i)
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2) 
        for (int i = 0 ; i < n; i += k * 2) {
        auto it1 = &a[i], it2 = it1 + k;
        for (int j = 0; j < k; ++j, ++it1, ++it2) {
            Mod z = rt[j + k] * *it2;
            *it2 = *it1 - z, *it1 += z;
        }
    }
}

vc<Mod> conv(vc<Mod> a, vc<Mod> b) {
    if (a.empty() || b.empty()) return {};
    int s = sz(a) + sz(b) - 1, n = 1 << (32 - __builtin_clz(s - 1));
    Mod iv = md - (md - 1) / n;
    vc<Mod> out(n);
    a.resize(n), b.resize(n);
    ntt(a), ntt(b);
    for (int i = 0; i < n; ++i)
        out[-i & (n - 1)] = a[i] * b[i] * iv;
    ntt(out);
    return {out.begin(), out.begin() + s};
}

int n;
vc<Mod> f, g;

vc<Mod> solve(int l, int r)
{
if(l==r) return vec[l];
/* 找重心分治
int mid=l, sum1=0, sum2=sz(vec[mid]);
for(int i=l; i<=r; ++i) sum1+=sz(vec[l]);
while(mid+1<r && sum2+sz(vec[mid+1])<=sum1/2) sum2+=sz(vec[++mid]); */
int mid=(l+r)/2;
return conv(solve(l, mid), solve(mid+1, r));
}

void divide(int l, int r)
{
    if(l==r) return;
    int mid=(l+r)>>1;
    divide(l, mid);
    vc<Mod> a{f.begin()+l, f.begin()+mid+1};
    vc<Mod> b{g.begin(), g.begin()+r-l+1};
    a=conv(a, b);
    for(int i=mid+1; i<=r; ++i) f[i]+=a[i-l];
    divide(mid+1, r);
}

// f[0]=1 且满足递推关系 f[n]=\sum_i^n g[i]*f[n-i]
int main()
{
    scanf("%d", &n);
    f.resize(n), g.resize(n);
    for(int i=1; i<n; ++i) scanf("%lld", &g[i].x);
    f[0]=1;
    divide(0, n-1);
    for(int i=0; i<n; ++i) printf("%lld ", f[i].x);
}