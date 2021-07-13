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
        sum=0;
        scanf("%d%d", &n, &x);
        for(int i=1; i<=n; ++i) scanf("%d", &w[i]);
        for(int i=1; i<=n; ++i) {
            sum+=w[i];
            if(i<=n && sum==x) swap(w[i], w[i+1]); 
        }
        if(sum==x) printf("NO\n");
        else {
            printf("YES\n");
            for(int i=1; i<=n; ++i) printf("%d ", w[i]);
            printf("\n");
        }
    }
    return 0;
}