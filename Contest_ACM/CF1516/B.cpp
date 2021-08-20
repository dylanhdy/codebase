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

int T, n, k, a[10005];

int main()
{
    scanf("%d", &T);
    while(T--) {
        int flag1=0, flag2=0;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            a[i]^=a[i-1];
        }
        for(int i=1; i<n; ++i) {
            if(a[i]==a[n]) flag1=1;
            if(flag1 && a[i]==0) flag2=1;
        }
        if(flag2 || a[n]==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}