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

vc<Mod> inv(LIM), fac(LIM), ifac(LIM);

void init()
{
    inv[0]=inv[1]=ifac[0]=fac[0]=1;
    for(int i=2; i<LIM; ++i) inv[i]=inv[md%i]*(md-md/i);
    for(int i=1; i<LIM; ++i) {
        ifac[i]=ifac[i-1]*inv[i];
        fac[i]=fac[i-1]*i;
    }
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

void invIter (vc<Mod> &a, vc<Mod> &in, vc<Mod> &b) {
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
    Mod iv = md - (md - 1) / n; iv *= iv;
    for (int i = n / 2; i < n; ++i)
        b[i] = out[i].x ? iv * (md - out[i].x) : 0;
}

vc<Mod> polyInv (vc<Mod> a) {
    if (a.empty()) return {};
    vc<Mod> b{qpow(a[0], md - 2)};
    b.reserve(sz(a));
    while (sz(b) < sz(a)) {
      vc<Mod> in(sz(b) * 2);
      copy(all(b), in.begin()), ntt(in);
      invIter(a, in, b);
    }
    return {b.begin(), b.begin() + sz(a)};
}

vc<Mod> polyMod (vc<Mod> a, vc<Mod> b) {
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
}

vc<Mod> deri (vc<Mod> a) {
    for (int i = 1; i < sz(a); ++i) a[i - 1] = a[i] * i;
    a.pop_back();
    return a;
}

// initialize array inv
vc<Mod> inte (vc<Mod> a) {
    for (int i = sz(a) - 1; i >= 1; --i) a[i] = a[i - 1] * inv[i];
    a[0] = 0;
    return a;
}

vc<Mod> polyLn (vc<Mod> &a) {
    if (a.empty()) return {};
    int n = 1 << (32 - __builtin_clz(2 * sz(a) - 2));
    Mod iv = md - (md - 1) / n;
    vc<Mod> b = polyInv(a), c = deri(a);
    b.resize(n), c.resize(n);
    ntt(b), ntt(c);
    for (int i = 0; i < n; ++i) b[i] = b[i] * c[i] * iv;
    ntt(b), reverse(b.begin() + 1, b.end());
    b = inte(b);
    return {b.begin(), b.begin() + sz(a)};
}

vc<Mod> polyExp (vc<Mod> &a) {
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
        Mod iv = md - (md - 1) / n;
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
            A[i] = (A[i - 1] - B[i - 1] * iv) * inv[i] * iv - a[i];
        fill(A.begin(), A.begin() + h, 0), conv(A, db);
        b.resize(n);
        for (int i = h; i < n; ++i) 
            b[i] = A[i].x ? iv * (md - A[i].x) : 0;
        if (sz(b) < sz(a)) invIter(b, dib, ib);
    }
    return {b.begin(), b.begin() + sz(a)};
}

vc<Mod> polyPow (vc<Mod> &a, ll k) {
    vc<Mod> b = polyLn(a);
    for (Mod &e: b) e *= k;
    return polyExp(b);
}

int recurrence(vc<Mod> f, vc<Mod> a, ll m)
{
    int k=a.size(), n=1<<(32-__builtin_clz(2*k-2));
    vc<Mod> g=polyInv(vc<Mod>(f.begin(), f.begin()+k-1));
    reverse(all(f));
    g.resize(n), f.resize(n);
    ntt(g), ntt(f);
    auto combine = [&](vc<Mod> a, vc<Mod> b) -> vc<Mod> {
        Mod iv = md - (md - 1) / n;
        vc<Mod> c(n), d(n);
        a=conv(a, b);
        copy(a.rbegin(), a.rbegin()+k-1, c.begin());
        ntt(c);
        for (int i=0; i<n; ++i) d[-i&(n-1)]=c[i]*g[i]*iv;
        ntt(d);
        copy(d.rend()-k+1, d.rend(), c.begin());
        fill(c.begin()+k-1, c.end(), 0);
        ntt(c);
        for (int i=0; i<n; ++i) d[-i&(n-1)]=c[i]*f[i]*iv;
        ntt(d);
        for(int i=0; i<k; ++i) a[i]-=d[i];
        return {a.begin(), a.begin()+k};
    };
    vc<Mod> b(k), c(k);
    b[0]=1, c[1]=1;
    for(; m; m>>=1) {
        if(m&1) b=combine(b, c);
        c=combine(c, c);
    }
    Mod ans;
    for(int i=0; i<k; ++i) ans+=a[i]*b[i];
    return ans.x;
}

// f[0]=P-1 且有递推关系 a[n]=\sum_i^k f[i]*a[n-i]
int main()
{
    int m, k;
    cin>>m>>k;
    vc<Mod> a(k), f(k+1);
    f[0]=Mod(md-1);
    for(int i=1, tmp; i<=k; ++i) {
        cin>>tmp;
        f[i]=Mod((tmp%md+md)%md);
    }
    for(int i=0, tmp; i<k; ++i) {
        cin>>tmp;
        a[i]=Mod((tmp%md+md)%md);
    }
    // a[m] 值为 recurrence(f, a, m)
    return 0;
}