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

int T, n, a[55];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        int flag=1;
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            if(a[i]!=i) flag=0;
        }
        if(flag) {
            printf("0\n");
            continue;
        }
        if(a[1]==1 || a[n]==n) {
            printf("1\n");
        } else if(a[1]==n && a[n]==1) {
            printf("3\n");
        } else {
            printf("2\n");
        }
    }
    return 0;
}