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

int a[5];

int main()
{
    scanf("%d%d%d%d", &a[1], &a[2], &a[3], &a[4]);
    int sum=a[1]+a[2]+a[3]+a[4];
    for(int i=1; i<=4; ++i)
        for(int j=i+1; j<=4; ++j)
            if((a[i]+a[j])*2==sum)
            {
                printf("Yes\n");
                return 0;
            }
    for(int i=1; i<=4; ++i)
        if(a[i]*2==sum)
        if(a[i]*2==sum)
        {
            printf("Yes\n");
            return 0;
        }
    printf("No\n");
    return 0;
}