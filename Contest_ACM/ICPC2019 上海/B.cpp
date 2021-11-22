#include <bits/stdc++.h>
using namespace std;

int T, n;
string s[10005];
unordered_map<string,int> mp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>T;
    for(int Case=1; Case<=T; ++Case) {
        mp.clear();
        int flag=1;
        cin>>n;
        for(int i=1; i<=n; ++i) {
            cin>>s[i];
            string tmp;
            for(char e: s[i]) {
                tmp+=e;
                mp[tmp]++;
            }
        }
        for(int i=1; i<=n; ++i)
            if(mp[s[i]]>1) flag=0;
        if(!flag) printf("Case #%d: No\n", Case);
        else printf("Case #%d: Yes\n", Case);
    }
}