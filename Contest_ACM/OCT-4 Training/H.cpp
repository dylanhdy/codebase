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

int a, b, c;

int main()
{
    scanf("%d%d%d", &a, &b, &c);
    if(a+b+c==1)
        printf("YES\n0\n");
    else if(a>b+c)
        printf("YES\n%d\n", (b+c)*2+1);
    else
        printf("NO\n");
    return 0;
}