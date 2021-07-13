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

int T, n, a[1005];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        int flag=0;
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            if(a[i]<0) flag=1;
        }
        if(flag) printf("NO\n");
        else {
            printf("YES\n%d\n", 101);
            for(int i=0; i<=100; ++i) printf("%d ", i);
            printf("\n");
        }
    }
    return 0;
}