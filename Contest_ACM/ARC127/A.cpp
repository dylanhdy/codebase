#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#define LL long long
#define LD long double
#define MAXN
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

LL n, ans;

int main()
{
    scanf("%lld", &n);
    for(LL x=1; x<=n; x*=10)
        for(LL y=x; y<=n; y=y*10+x)
            ans+=min(x, max((LL)0, n-y+1));
    printf("%lld\n", ans);
    return 0;
}