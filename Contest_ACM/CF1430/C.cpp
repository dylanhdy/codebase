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

int n, t;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", 2);
        if(n==2)
        {
            printf("1 2\n");
            continue;
        }
        printf("%d %d\n", n, n-2);
        printf("%d %d\n", n-1, n-1);
        for(int i=3; i<n; ++i)
        {
            printf("%d %d\n", n-i, n-i+2);
        }
    }
    return 0;
}