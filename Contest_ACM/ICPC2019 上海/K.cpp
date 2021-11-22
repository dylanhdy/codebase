#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int I = 1; I <= T; I++){
        int n, m;
        cin >> n >> m;
        vector<pair<int, int> > e(m + 1);
        for(int i = 1; i <= m; i++){
            cin >> e[i].first >> e[i].second;
            e[i].first--; e[i].second--;
        }
        int Ans = 0;
        for(int i = 0; i < (1 << n); i++){
            int ans = 0;
            for(int j = 1; j <= m; j++){
                int x = (i >> e[j].first) & 1, y = (i >> e[j].second) & 1;
                if(x ^ y) ans++;
            }
            Ans = max(Ans, ans);
        }
        cout << "Case #" << I << ": " << Ans << endl;
    }
}