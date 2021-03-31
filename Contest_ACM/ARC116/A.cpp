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

int T;
LL temp;

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%lld", &temp);
        if(temp%4==0) printf("Even\n");
        else if(temp%2==0) printf("Same\n");
        else printf("Odd\n");
    }
    return 0;
}