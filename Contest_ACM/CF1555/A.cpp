#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T;
LL n, ans;

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%lld", &n);
        if(n<=6) n=6;
        ans=(n+1)/2*5;
        printf("%lld\n", ans);
    }
    return 0;
}