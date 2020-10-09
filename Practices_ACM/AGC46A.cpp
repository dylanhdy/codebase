#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 1000005
#define P 998244353
#define INF 0x3f3f3f3f
using namespace std;

int x;

int gcd(int x, int y)
{
    return y?gcd(y, x%y):x;
}

int main()
{
    scanf("%d", &x);
    printf("%d\n", 360/gcd(360, x));
    return 0;
}