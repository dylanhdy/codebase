#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int t, n, k, ans;

LL ksm(LL x, int y)
{
    LL ans=1;
    while(y)
    {
        if(y&1) ans*=x;
        x*=x, y>>=1;
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    for(int qwq=1; qwq<=t; ++qwq)
    {
        ans=0;
        scanf("%d%d", &n, &k);
        if(k==1)
        {
            printf("Case #%d: %d\n", qwq, n);
            continue;
        }
        int up=pow(n, 1.0/k);
        for(int i=1, last=1; i<=up; ++i)
        {
            if(i==up)
            {
                ans+=(n-last+i)/i;
                break;
            }
            ans+=(ksm(i+1, k)-last+i-1)/i;
            last=ksm(i+1, k);
        }
        printf("Case #%d: %d\n", qwq, ans);
    }
    return 0;
}