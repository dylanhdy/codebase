#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n;
string s1, s2;

string solve()
{
    s2.resize(1);
    for(int i=0; i<26; ++i) {
        s2[0]=('a'+i);
        if(s1.find(s2)==-1) return s2;
    }
    s2.resize(2);
    for(int i=0; i<26; ++i) {
        s2[0]=('a'+i);
        for(int j=0; j<26; ++j) {
            s2[1]=('a'+j);
            if(s1.find(s2)==-1) return s2;
        }
    }
    s2.resize(3);
    for(int i=0; i<26; ++i) {
        s2[0]=('a'+i);
        for(int j=0; j<26; ++j) {
            s2[1]=('a'+j);
            for(int k=0; k<26; ++k) {
                s2[2]=('a'+k);
                if(s1.find(s2)==-1) return s2;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--) {
        cin>>n>>s1;
        cout<<solve()<<'\n';
    }
    return 0;
}