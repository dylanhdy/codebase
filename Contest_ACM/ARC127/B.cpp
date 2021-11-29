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

int n, l, pos, cnt[20][3];

string str;
vector<string> ans;

void dfs(int p)
{
    if(p==l) {
        ans[pos]=str;
        for(int i=0; i<l; ++i) cnt[i][str[i]-'0']++;
        pos++;
        return;
    }
    for(int i=0; pos<3*n && i<3; ++i) {
        str[p]=('0'+i);
        dfs(p+1);
    }
}

char add(char x, int y)
{
    return x+y>'2'?x+y-3:x+y;
}

int main()
{
    scanf("%d%d", &n, &l);
    ans.resize(3*n), str.resize(l);
    pos=2*n;
    str[0]='2';
    dfs(1);
    // for(auto e: ans) printf("%s\n", e.c_str());
    for(int i=0; i<2*n; ++i) {
        ans[i].resize(l);
        for(int j=0; j<l; ++j) ans[i][j]=add(ans[i%n+2*n][j], i/n+1);
    }
    for(auto e: ans) printf("%s\n", e.c_str());
    return 0;
}