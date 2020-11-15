#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 55
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, t, a[MAXN];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        int sum=0;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &a[i]);
            sum+=a[i];
        }
        sort(a+1, a+n+1);
        if(sum==0) printf("NO\n");
        if(sum>0)
        {
            printf("YES\n");
            for(int i=n; i>=1; --i) printf("%d ", a[i]);
            printf("\n");
        }
        if(sum<0)
        {
            printf("YES\n");
            for(int i=1; i<=n; ++i) printf("%d ", a[i]);
            printf("\n");
        }
    }
    return 0;
}