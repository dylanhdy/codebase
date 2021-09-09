#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
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

int T, ans;

char s[15];

int solve()
{
    //printf("%s\n", s+1);
    int cnt=0;
    for(int i=1; i<=10; ++i) {
        if(s[i]=='1') {
            if(i&1) cnt++;
            else cnt--;
        }
        //printf("%d %d\n", i, cnt);
        if(cnt>0 && cnt>(11-i)/2) return i;
        if(cnt<0 && -cnt>(10-i)/2) return i;
    }
    return 10;
}

void dfs(int x)
{
    if(x==11) {
        ans=min(solve(), ans);
        return;
    }
    if(s[x]=='?') {
        s[x]='0';
        dfs(x+1);
        s[x]='1';
        dfs(x+1);
        s[x]='?';
    } else dfs(x+1);
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        ans=INF;
        scanf("%s", s+1);
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}