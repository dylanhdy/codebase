#include <cstdio>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

using namespace std;
template<class T> using vc = vector<T>;
using ll = int64_t;

constexpr ll md = 998244353;
struct Mod {
  ll x;
  Mod(ll x = 0): x(x>=0?x%md:x%md+md) {}
  Mod operator+(Mod b) {ll y=x+b.x;return y<md ? y : y - md; }
  Mod operator-(Mod b) { return x - b.x + (x < b.x ? md : 0); }
  Mod operator * (Mod b) { return x * b.x % md; }
  void operator += (Mod b) { x += b.x; x < md ?: x -= md; }
  void operator *= (Mod b) { (x *= b.x) %= md; }
  void operator -= (Mod b) { x -= b.x; -x < 0 ?: x += md; }
};

int main() {
  constexpr ll root = 62, LIM = 1 << 17;
  auto mdPow = [&](Mod b, ll e) {
    Mod res = 1;
    for (; e; b *= b, e /= 2)
      if (e & 1) res *= b;
    return res;
  };
  auto mdInv = [&] {
    vc<ll> inv(LIM); inv[1] = 1;
    for (int i = 2; i < LIM; ++i) 
      inv[i] = md - (md / i) * inv[md % i] % md;
    return inv;
  };
  auto iv = mdInv();
  auto ntt = [&](vc<Mod> &a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vc<Mod> rt(2, 1);
    for (static int k = 2, s = 2; k < n; k *= 2, ++s) {
      rt.resize(n);
      array<Mod, 2> z{1, mdPow(root, md >> s)};
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
  };
  auto conv = [&](vc<Mod> a, vc<Mod> b) -> vc<Mod> {
    if (a.empty() || b.empty()) return {};
    int s = sz(a) + sz(b) - 1,
        n = 1 << (32 - __builtin_clz(s - 1));
    Mod inv = md - (md - 1) / n;
    vc<Mod> out(n);
    a.resize(n), b.resize(n);
    ntt(a), ntt(b);
    for (int i = 0; i < n; ++i)
      out[-i & (n - 1)] = a[i] * b[i] * inv;
    ntt(out);
    return {out.begin(), out.begin() + s};
  };
  auto invIter = [&](vc<Mod> &a, vc<Mod> &in, vc<Mod> &b) {
    int n = sz(in);
    vc<Mod> out(n);
    copy(a.begin(), a.begin() + min(sz(a), n), out.begin());
    auto conv = [&] {
      ntt(out);
      for (int i = 0; i < n; ++i) out[i] *= in[i];
      ntt(out), reverse(out.begin() + 1, out.end());
    };
    conv(), fill(out.begin(), out.begin() + sz(b), 0), conv();
    b.resize(n);
    Mod inv = md - (md - 1) / n; inv *= inv;
    for (int i = n / 2; i < n; ++i)
      b[i] = out[i].x ? inv * (md - out[i].x) : 0;
  };
  auto polyInv = [&](vc<Mod> a) -> vc<Mod> {
    if (a.empty()) return {};
    vc<Mod> b{mdPow(a[0], md - 2)};
    b.reserve(sz(a));
    while (sz(b) < sz(a)) {
      vc<Mod> in(sz(b) * 2);
      copy(all(b), in.begin()), ntt(in);
      invIter(a, in, b);
    }
    return {b.begin(), b.begin() + sz(a)};
  };
  auto polyMod = [&](vc<Mod> a, vc<Mod> b) -> vc<Mod> {
    if (sz(a) < sz(b)) return a;
    int n = sz(a) - sz(b) + 1;
    vc<Mod> da(a.rbegin(), a.rend()), db(b.rbegin(), b.rend());
    da.resize(n), db.resize(n);
    da = conv(da, polyInv(db));
    da.resize(n), reverse(all(da));
    auto c = conv(da, b);
    a.resize(sz(b) - 1);
    for (int i = 0; i < sz(a); ++i) a[i] -= c[i];
    return a;
  };
  auto deri = [&](vc<Mod> a) {
    for (int i = 1; i < sz(a); ++i) a[i - 1] = a[i] * i;
    a.pop_back();
    return a;
  };
  auto inte = [&](vc<Mod> a) {
    for (int i = sz(a) - 1; i >= 1; --i)
      a[i] = a[i - 1] * iv[i];
    a[0] = 0;
    return a;
  };
  auto polyLn = [&](vc<Mod> &a) -> vc<Mod> {
    if (a.empty()) return {};
    int n = 1 << (32 - __builtin_clz(2 * sz(a) - 2));
    Mod inv = md - (md - 1) / n;
    vc<Mod> b = polyInv(a), c = deri(a);
    b.resize(n), c.resize(n);
    ntt(b), ntt(c);
    for (int i = 0; i < n; ++i) b[i] = b[i] * c[i] * inv;
    ntt(b), reverse(b.begin() + 1, b.end());
    b = inte(b);
    return {b.begin(), b.begin() + sz(a)};
  };
  auto polyExp = [&](vc<Mod> &a) -> vc<Mod> {
    if (a.empty()) return {};
    vc<Mod> b{1}, ib{1};
    b.reserve(sz(a)), ib.reserve(sz(a));
    auto conv = [&](vc<Mod> &a, vc<Mod> &b) {
      ntt(a);
      for (int i = 0; i < sz(a); ++i) a[i] *= b[i];
      ntt(a), reverse(a.begin() + 1, a.end());
    };
    while (sz(b) < sz(a)) {
      int h = sz(b), n = h * 2;
      Mod inv = md - (md - 1) / n;
      vc<Mod> db(n), dib(n), A(deri(b)), B(n);
      copy(all(ib), dib.begin()), ntt(dib);
      copy(all(b), db.begin()), ntt(db);
      A.resize(n), conv(A, dib);
      for (int i = 0; i < n; ++i) B[i] = db[i] * dib[i];
      ntt(B), reverse(B.begin() + 1, B.end());
      fill(B.begin(), B.begin() + h, 0);
      vc<Mod> da(deri(vc<Mod>(a.begin(), a.begin() + h)));
      da.resize(n), ntt(da), conv(B, da);
      for (int i = min(n, sz(a)) - 1; i >= h; --i)
        A[i] = (A[i - 1] - B[i - 1] * inv) * iv[i] * inv - a[i];
      fill(A.begin(), A.begin() + h, 0), conv(A, db);
      b.resize(n);
      for (int i = h; i < n; ++i) 
        b[i] = A[i].x ? inv * (md - A[i].x) : 0;
      if (sz(b) < sz(a)) invIter(b, dib, ib);
    }
    return {b.begin(), b.begin() + sz(a)};
  };
  auto polyPow = [&](vc<Mod> &a, ll k) {
    auto b = polyLn(a);
    for (Mod &e: b) e *= k;
    return polyExp(b);
  };

  cin.tie(0)->sync_with_stdio(0);
  int m, k;
  cin>>m>>k;
  vc<Mod> a(k), b(k), c(k), f(k+1);
  f[0]=1;
  for(int i=1, tmp; i<=k; ++i) {cin>>tmp; f[i]=-tmp;}
  for(int i=0, tmp; i<k; ++i) {cin>>tmp; c[i]=tmp;}
  vc<Mod> g=polyInv(vc<Mod>(f.begin(), f.begin()+k-1));
  reverse(all(f));
  int s=2*k-1, n=1<<(32-__builtin_clz(s-1));
  g.resize(n), f.resize(n);
  ntt(g), ntt(f);

  auto combine = [&](vc<Mod> a, vc<Mod> b) -> vc<Mod> {
    Mod inv = md - (md - 1) / n;
    vc<Mod> c(n), d(n);
    a=conv(a, b);
    copy(a.rbegin(), a.rbegin()+k-1, c.begin());
    ntt(c);
    for (int i=0; i<n; ++i) d[-i&(n-1)]=c[i]*g[i]*inv;
    ntt(d);
    copy(d.rend()-k+1, d.rend(), c.begin());
    fill(c.begin()+k-1, c.end(), 0);
    ntt(c);
    for (int i=0; i<n; ++i) d[-i&(n-1)]=c[i]*f[i]*inv;
    ntt(d);
    for(int i=0; i<k; ++i) a[i]-=d[i];
    return {a.begin(), a.begin()+k};
  };

  a[1]=1, b[0]=1;
  for(; m; m>>=1) {
    if(m&1) b=combine(a, b);
    a=combine(a, a);
  }
  Mod ans;
  for(int i=0; i<k; ++i) ans+=c[i]*b[i];
  cout<<ans.x;
}