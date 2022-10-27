#include <cstdio>
#include <algorithm>
#include <cmath>
#include <complex>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
using namespace std;

template<class T> using vc = vector<T>;
using C = complex<double>;
using vd = vc<double>;
 
void fft(vc<C> &a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vc<C> rt(2, 1);
    static vc<complex<long double>> R(2, 1);
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n), rt.resize(n);
        auto x = polar(1.L, acos(-1.L) / k);
        for (int i = k; i < k * 2; ++i)
            rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
    vc<int> rev(n);
    for (int i = 0; i < n; ++i) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for (int i = 0 ; i < n; ++i) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += k * 2) {
            auto it1 = &a[i], it2 = it1 + k;
            for (int j = 0; j < k; ++j, ++it1, ++it2) {
                auto x = (double *)&rt[j + k], y = (double *)it2;
                C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
                *it2 = *it1 - z;
                *it1 += z;
            }
        }
}
 
vd conv(vd &a, vd&b) {
    if (a.empty() || b.empty()) return vd();
    vd res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res) - 1), n = 1 << L;
    vc<C> in(n), out(n);
    copy(all(a), begin(in));
    for (int i = 0; i < sz(b); ++i) in[i].imag(b[i]);
    fft(in);
    for (C &x: in) x *= x;
    for (int i = 0; i < n; ++i) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    for (int i = 0; i < sz(res); ++i) res[i] = imag(out[i]) / (n * 4);
    return res;
}

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    vd a(n+1), b(m+1);
    for(int i=0; i<=n; ++i) scanf("%lf", &a[i]);
    for(int i=0; i<=m; ++i) scanf("%lf", &b[i]);
    a=conv(a, b);
    for(double e: a) printf("%d ", int(e+0.5));
}