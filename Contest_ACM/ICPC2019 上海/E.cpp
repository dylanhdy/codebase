#include "bits/stdc++.h"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

using namespace std;
template<class T>using vc = vector<T>;
using ll = int64_t;

struct UF {
  vc<int> e;
  UF(int n): e(n, -1) {}
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return 0;
    // if (e[a] > e[b]) swap(a, b);
    // e[a] += e[b], e[b] = a;
    e[b] = a;
    return 1;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  for (int cs = 1; cs <= T; ++cs) {
    int n, m, sr, sc, tr, tc; cin >> n >> m >> sr >> sc >> tr >> tc;
    vc<int> X(n * m);
    int a, b, c, p; cin >> X[0] >> X[1] >> a >> b >> c >> p;
    int nm = n * m;
    for (int i = 2; i < nm; ++i) {
      X[i] = (a * X[i - 1] + b * X[i - 2] + c) % p;
    }
    vc<array<int, 2>> edg[10005];
    constexpr int dx[] = {0, 1, -1, 0}, dy[] = {1, 0, 0, -1};
    auto id = [&](int x, int y) {
      return x * m + y;
    };
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int id1 = id(i, j);
        for (int k = 0; k < 4; ++k) {
          int x = i + dx[k], y = j + dy[k];
          if (x < 0 || y < 0 || x >= n || y >= m) continue;
          int id2 = id(x, y);
          //edg.push_back({id1, id2, X[id1] * X[id2]});
          edg[X[id1]*X[id2]].push_back({id1, id2});
        }
      }
    }
    // vc<int> ci(p * p);
    // auto sedg = edg;
    UF uf(n * m);
    // double tim = clock();
    // for (auto e: edg) ++ci[e[2]];
    // for (int i = 1; i < sz(ci); ++i) ci[i] += ci[i - 1];
    // for (auto e: edg) {
    //   sedg[--ci[e[2]]] = e;
    // }
    // cout << (clock() - tim) / CLOCKS_PER_SEC << '\n';
    ll ans = 0;
    int tot = 0;
    for (int i = p*p; i>=0; --i) {
      //auto [a, b, w] = sedg[i];
      for(auto [a, b]: edg[i]) 
      if (uf.join(a, b)) {
        ans += i;
        if (++tot == nm - 1) break;
      }
    }
    cout << "Case #" << cs << ": " << ans << '\n';
  }
}
