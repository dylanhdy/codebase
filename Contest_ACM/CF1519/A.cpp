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

int T, a, b, d;

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &a, &b, &d);
        int x=min(a, b), y=max(a, b)-min(a, b);
        if(1LL*x*d>=y) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}