#include<bits/stdc++.h>
#define ll int64_t
using namespace std;

inline char gc() {
  static char buf[1 << 16];
  static size_t bc, be;
  if (bc >= be) {
    buf[0] = 0, bc = 0;
    be=fread(buf, 1, sizeof buf, stdin);
  }
  return buf[bc++];
}

void read(int &x){
  int c;
  while ((x = gc()) < 40);
  while ((c = gc()) >= 48) x = x * 10 + c - 480;
  x -= 48;
}
int main(){
  int _; read(_);
  while(_--){
    int n; read(n);
    vector<vector<int>> a(n + 1), ed(n + 1);
    vector<int> v(n + 1);
    vector<ll> tim(n + 1);
    for(int i = 1; i <= n; ++i){
      int opt; read(opt);
      if(opt == 1){
        int k; read(k);
        for(int j = 1; j <= k; ++j){
          int x; read(x); a[i].emplace_back(x);
        }
      } else{
        int x, y; read(x); read(y);
        ed[i].emplace_back(x);
        ed[i].emplace_back(y);
        ++v[x], ++v[y];
      }
    }
    queue<int>Q;
    vector<pair<int,ll> > vec;
    for(int i = 1; i <= n; ++i)
      if(v[i] == 0) Q.emplace(i);
    tim[n] = 1;
    while(!Q.empty()){
      int x = Q.front(); Q.pop();
      for(auto &y : ed[x]){
        --v[y]; if(!v[y]) Q.emplace(y);
        tim[y] += tim[x];
      }
    }
    ll len=0, val1=0, val2=0;
    for(int i=1; i<=n; ++i) {
      if(!a[i].size()) continue;
      len+=tim[i]*a[i].size();
      for(int &e: a[i]) vec.emplace_back(e, tim[i]);
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i<vec.size(); ++i) {
      if(i && vec[i].first!=vec[i-1].first) {
        val1=max(val1, val2);
        val2=0;
      }
      val2+=vec[i].second;
    }
    val1=max(val1, val2);
    cout << min(len, (len - val1) * 2) << '\n';
  }
}
