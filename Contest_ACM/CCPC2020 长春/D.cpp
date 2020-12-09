#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 3005
#define MAXM
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, c, f[MAXN];
char s[MAXN];

int dp(int x, int lim)
{
    if(x==n+1) return 1;
    if(!lim && f[x]!=-1) return f[x];
    int temp=dp(x+1, lim&(s[x]=='0'));
    if(!lim || s[x]=='1') temp=(temp+1LL*c*dp(x+1, lim&(s[x]=='1')))%P;
    if(!lim) f[x]=temp;
    return temp;
}

int main()
{
    memset(f, -1, sizeof(f));
    scanf("%s%d", s+1, &c);
    n=strlen(s+1);
    printf("%d\n", dp(1, 1));  
    return 0;
}