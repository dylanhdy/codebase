#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, a[MAXN];

int gcd(int x, int y)
{
    return y?gcd(y, x%y):x;
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &a[1]);
    int ans=a[1];
    for(int i=2; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        ans=gcd(ans, a[i]);
    }
    printf("%d\n", ans);
    return 0;
}