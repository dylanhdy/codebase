#include "bits/stdc++.h"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

using namespace std;
template<class T>using vc = vector<T>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, d, c; cin >> n >> d >> c;
  if (d == 0) {
    if (c != n) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
      for (int i = 0; i < n; ++i) cout << '\n';
    }
    return 0;
  }
  if (d == 1) {
    if (n != 2 * c) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
      for (int i = 1; i <= n; ++i) {
        if (i & 1) cout << i + 1 << '\n';
        else cout << i - 1 << '\n';
      }
    }
    return 0;
  }
  if (n < c * (d + 1)) {
    cout << "No\n";
    return 0;
  }
  int m = n - (c - 1) * (d + 1);
  if ((d & 1) && (m & 1)) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  auto id = [&](int x) {
    return (x - 1 + m) % m + 1;
  };
  vc<vc<int>> g(m + 1);
  if (~d & 1) {
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= d / 2; ++j) g[i].emplace_back(id(i - j)), g[i].emplace_back(id(i + j));
      sort(all(g[i]));
      for (auto e: g[i]) cout << e << ' ';
      cout << '\n';
    }
  } else {
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= d / 2; ++j) g[i].emplace_back(id(i - j)), g[i].emplace_back(id(i + j));
      g[i].emplace_back(id(i + m / 2));
      sort(all(g[i]));
      for (auto e: g[i]) cout << e << ' ';
      cout << '\n';
    }
  }
  for (int i = m + 1; i <= n; i += d + 1) {
    for (int j = 0; j <= d; ++j) {
      int now = i + j;
      for (int k = i; k <= i + d; ++k) {
        if (k == now) continue;
        cout << k << ' ';
      }
      cout << '\n';
    }
  }
}