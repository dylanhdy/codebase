#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
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
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, a, b, c, d;

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if(min(c, d)>max(a, b) || max(c, d)<min(a, b)) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}