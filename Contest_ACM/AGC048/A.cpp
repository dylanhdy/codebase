#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 1005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int t, n;
char s[MAXN], a[MAXN]="atcoder";

void solve()
{
    for(int i=0; i<n; ++i)
    {
        if(s[i]>a[i])
        {
            printf("0\n");
            return;
        }
        if(s[i]<a[i]) break;
    }
    for(int i=0; i<n; ++i)
        if(s[i]!='a')
        {
            if(s[i]>'t' && i>=2) printf("%d\n", i-1);
            else printf("%d\n", i);
            return;
        }
    printf("-1\n");
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s);
        n=strlen(s);
        solve();
    }
    return 0;
}