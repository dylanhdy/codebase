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

int T, n, x, sum, w[105];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        int num1=sqrt(n/2), num2=sqrt(n/4);
        if(n%2==0 && num1*num1==n/2) {
            printf("YES\n");
            continue;
        }
        if(n%4==0 && num2*num2==n/4) {
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
    return 0;
}