#include "bits/stdc++.h"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

using namespace std;
template<class T>using vc = vector<T>;
using ll = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  for (int cs = 1; cs <= T; ++cs) {
    int n, K; cin >> n >> K;
    vc<vc<int>> g(n);
    for (int i = 1; i < n; ++i) {
      int u, v; cin >> u >> v;
      --u, --v;
      g[u].emplace_back(v), g[v].emplace_back(u);
    }
    vc<int> w(n);
    ll l = 0, r = 0;
    for (auto &e: w) cin >> e, r += e, l = max(l, (ll)e);
    ll ans = r;
    auto check = [&](ll mid) {
      vc<ll> sum(n);
      int nowK = 1;
      function<void(int, int)> dfs = [&](int u, int fa) {
        sum[u] = w[u];
        // cerr << u << ' ' << sum[u] << '\n';
        priority_queue<ll> Q;
        for (auto v: g[u]) {
          if (v == fa) continue;
          dfs(v, u);
          sum[u] += sum[v];
          Q.emplace(sum[v]);
        }
        while (!Q.empty() && sum[u] > mid) {
          ++nowK;
          sum[u] -= Q.top();
          Q.pop();
        }
        // cerr << u << ' ' << sum[u] << '\n';
      };
      dfs(0, -1);
      // cerr << "------------\n";
      return nowK <= K;
    };
    while (l <= r) {
      ll mid = (l + r) / 2;
      if (check(mid)) ans = mid, r = mid - 1;
      else l = mid + 1;
    }
    cout << "Case #" << cs << ": " << ans << '\n';
  }
}
