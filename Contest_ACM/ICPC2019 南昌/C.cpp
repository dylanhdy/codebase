#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P 1000000007
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;

int T, len, f[MAXN];
char s[MAXN];

int dp(int x, int tag)
{
    if(x==len+1) return 1;
    if(!tag && f[x]!=-1) return f[x];
    int temp=(2-tag)*dp(x+1, tag)%P;
    if(s[x]=='1') temp=(temp+dp(x+1, 0))%P;
    if(!tag) f[x]=temp;
    return temp;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s+1);
        len=strlen(s+1);
        for(int i=1; i<=len; ++i) f[i]=-1;
        printf("%d\n", dp(1, 1));
    }
}