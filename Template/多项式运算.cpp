#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <array>
#define ll long long
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
using namespace std;

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
template<class T> using vc = vector<T>;
using poly = vc<Mod>;

poly inv(LIM), fac(LIM), ifac(LIM);

void init()
{
    inv[0]=inv[1]=ifac[0]=fac[0]=1;
    for(int i=2; i<LIM; ++i) inv[i]=inv[md%i]*(md-md/i);
    for(int i=1; i<LIM; ++i) {
        ifac[i]=ifac[i-1]*inv[i];
        fac[i]=fac[i-1]*i;
    }
}

void ntt(poly &a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static poly rt(2, 1);
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

poly conv(poly a, poly b) {
    if (a.empty() || b.empty()) return {};
    int s = sz(a) + sz(b) - 1, n = 1 << (32 - __builtin_clz(s - 1));
    Mod iv = md - (md - 1) / n;
    poly out(n);
    a.resize(n), b.resize(n);
    ntt(a), ntt(b);
    for (int i = 0; i < n; ++i)
        out[-i & (n - 1)] = a[i] * b[i] * iv;
    ntt(out);
    return {out.begin(), out.begin() + s};
}

void invIter (poly &a, poly &in, poly &b) {
    int n = sz(in);
    poly out(n);
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

poly polyInv (poly a) {
    if (a.empty()) return {};
    poly b{qpow(a[0], md - 2)};
    b.reserve(sz(a));
    while (sz(b) < sz(a)) {
      poly in(sz(b) * 2);
      copy(all(b), in.begin()), ntt(in);
      invIter(a, in, b);
    }
    return {b.begin(), b.begin() + sz(a)};
}

poly polyMod (poly a, poly b) {
    if (sz(a) < sz(b)) return a;
    int n = sz(a) - sz(b) + 1;
    poly da(a.rbegin(), a.rend()), db(b.rbegin(), b.rend());
    da.resize(n), db.resize(n);
    da = conv(da, polyInv(db));
    da.resize(n), reverse(all(da));
    auto c = conv(da, b);
    a.resize(sz(b) - 1);
    for (int i = 0; i < sz(a); ++i) a[i] -= c[i];
    return a;
}

poly deri (poly a) {
    for (int i = 1; i < sz(a); ++i) a[i - 1] = a[i] * i;
    a.pop_back();
    return a;
}

// initialize array inv
poly inte (poly a) {
    for (int i = sz(a) - 1; i >= 1; --i) a[i] = a[i - 1] * inv[i];
    a[0] = 0;
    return a;
}

poly polyLn (poly &a) {
    if (a.empty()) return {};
    int n = 1 << (32 - __builtin_clz(2 * sz(a) - 2));
    Mod iv = md - (md - 1) / n;
    poly b = polyInv(a), c = deri(a);
    b.resize(n), c.resize(n);
    ntt(b), ntt(c);
    for (int i = 0; i < n; ++i) b[i] = b[i] * c[i] * iv;
    ntt(b), reverse(b.begin() + 1, b.end());
    b = inte(b);
    return {b.begin(), b.begin() + sz(a)};
}

poly polyExp (poly &a) {
    if (a.empty()) return {};
    poly b{1}, ib{1};
    b.reserve(sz(a)), ib.reserve(sz(a));
    auto conv = [&](poly &a, poly &b) {
        ntt(a);
        for (int i = 0; i < sz(a); ++i) a[i] *= b[i];
        ntt(a), reverse(a.begin() + 1, a.end());
    };
    while (sz(b) < sz(a)) {
        int h = sz(b), n = h * 2;
        Mod iv = md - (md - 1) / n;
        poly db(n), dib(n), A(deri(b)), B(n);
        copy(all(ib), dib.begin()), ntt(dib);
        copy(all(b), db.begin()), ntt(db);
        A.resize(n), conv(A, dib);
        for (int i = 0; i < n; ++i) B[i] = db[i] * dib[i];
        ntt(B), reverse(B.begin() + 1, B.end());
        fill(B.begin(), B.begin() + h, 0);
        poly da(deri(poly(a.begin(), a.begin() + h)));
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

poly polyPow (poly &a, ll k) {
    poly b = polyLn(a);
    for (Mod &e: b) e *= k;
    return polyExp(b);
}

int main()
{
	init();
}