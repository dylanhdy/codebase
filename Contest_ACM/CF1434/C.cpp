#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int T, a, b, c, d;

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if(a>1LL*b*c) printf("-1\n");
        else
        {
            LL k=a/(1LL*b*d);
            printf("%lld\n", 1LL*a*(k+1)-k*(k+1)/2*b*d);
        }
    }
    return 0;
}