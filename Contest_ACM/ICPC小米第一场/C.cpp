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
#define P
#define INF 0x3f3f3f3f
using namespace std;
 
int ans, len;
char s[MAXN];
 
int main()
{
    scanf("%s", s+1);
    len=strlen(s+1);
    for(int i=1; i<=len; ++i)
    {
        if(s[i]=='w') ans++;
        if(s[i]=='w' && s[i-1]=='w') ans++;
    }
    printf("%d\n", ans);
    return 0;
}