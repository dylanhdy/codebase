#include <bits/stdc++.h>
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

int t, a, b;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &a, &b);
        printf("%lld\n", 1LL*a*b);
    }
    return 0;
}