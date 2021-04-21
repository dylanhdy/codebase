#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 105
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, ans;
string s[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    for(int qwq=1; qwq<=T; ++qwq) {
        ans=0;
        cin>>n;
        for(int i=1; i<=n; ++i) cin>>s[i];
        for(int i=2; i<=n; ++i) {
            if(s[i].length()==s[i-1].length()) {
                if(s[i]<=s[i-1]) s[i]+='0', ans++;
            } else if(s[i].length()<s[i-1].length()) {
                if(s[i]>s[i-1]) {
                    ans+=s[i-1].length()-s[i].length();
                    for(int j=s[i].length(); j<s[i-1].length(); ++j) s[i]+='0';
                } else if(s[i-1].find(s[i])==0) {
                    int pos=0;
                    for(int j=s[i-1].length()-1; j>=s[i].length(); --j)
                        if(s[i-1][j]!='9') {
                            pos=j;
                            break;
                        }
                    if(!pos) {
                        ans+=s[i-1].length()-s[i].length()+1;
                        for(int j=s[i].length(); j<=s[i-1].length(); ++j) s[i]+='0';
                    } else {
                        ans+=s[i-1].length()-s[i].length();
                        for(int j=s[i].length(); j<pos; ++j) s[i]+=s[i-1][j];
                        s[i]+=(s[i-1][pos]+1);
                        for(int j=pos+1; j<s[i-1].length(); ++j) s[i]+='0';
                    }
                } else {
                    ans+=s[i-1].length()-s[i].length()+1;
                    for(int j=s[i].length(); j<=s[i-1].length(); ++j) s[i]+='0';
                }
            }
            //cout<<s[i]<<'\n';
        }
        cout<<"Case #"<<qwq<<": "<<ans<<"\n";
    }
    return 0;
}