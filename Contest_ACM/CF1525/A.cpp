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

int T, k;

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &k);
        if(k==100) {
            printf("1\n");
            continue;
        }
        printf("%d\n", 100/__gcd(k, 100-k));
    }
    return 0;
}