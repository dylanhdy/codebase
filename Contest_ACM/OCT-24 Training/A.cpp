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

int t, a, b;

int gcd(int x, int y)
{
    return y?gcd(y, x%y):x;
}

int main()
{
    scanf("%d", &t);
    for(int qwq=1; qwq<=t; ++qwq)
    {
        scanf("%d%d", &a, &b);
        int up=a*(a-1);
        int down=(a+b)*(a+b-1);
        int g=gcd(down, up);
        printf("Case #%d: %d/%d\n", qwq, up/g, down/g);
    }
    return 0;
}
