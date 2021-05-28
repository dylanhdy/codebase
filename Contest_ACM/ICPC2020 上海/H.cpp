#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 1005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, k, ans, a[MAXN], b[MAXN], c[MAXN];

int main()
{
    scanf("%d", &T);
    while(T--) {
        ans=INF;
        scanf("%d%d", &n, &k);
        for(int i=0; i<k; ++i) scanf("%d", &a[i]);
        for(int i=0; i<k; ++i) scanf("%d", &b[i]);
        sort(a, a+k);
        sort(b, b+k);
        for(int i=0; i<k; ++i) {
            for(int j=0; j<k; ++j) c[j]=(a[j]-b[(j+i)%k]+n)%n;
            sort(c, c+k);
            int l=c[0], r=c[k-1];
            ans=min(ans, min(n-l, r));
            for(int j=k-1; j>=1; --j) {
                l=c[j]-n, r=c[j-1];
                ans=min(ans, r-l+min(-l, r));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}