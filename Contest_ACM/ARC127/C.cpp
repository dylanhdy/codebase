#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#define LL long long
#define LD long double
#define MAXN
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, m, pos;;
string str, ans;

void sub0()
{
    str[pos]--;
    if(pos+1==str.length()) str.pop_back();
    if(!pos) {
        while(str[pos]=='0') pos++;
    } else {
        for(int i=0; i<pos; ++i) str[i]++;
        pos=0;
    }
}

void sub1()
{
    str.pop_back();
    while(str.length() && str.back()=='0') str.pop_back();
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>str;
    reverse(str.begin(), str.end());
    while(str[pos]=='0') pos++;
    sub0();
    ans="1";
    for(int i=n; i>=2; --i) {
        if(!str.length()) break;
        if(i==str.length()) {
            ans+='1';
            sub1();
        } else {
            ans+='0';
            sub0();
        }
    }
    cout<<ans;
    return 0;
}