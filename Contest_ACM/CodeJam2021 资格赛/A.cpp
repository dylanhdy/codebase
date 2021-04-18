#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 105
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, ans, a[MAXN];

int main()
{
    scanf("%d", &T);
    for(int Case=1; Case<=T; ++Case) {
        ans=0;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        for(int i=1; i<n; ++i) {
            int pos=i;
            for(int j=i+1; j<=n; ++j)
                if(a[j]<a[pos]) pos=j;
            reverse(a+i, a+pos+1);
            ans+=pos-i+1;   
        }
        //for(int i=1; i<=n; ++i) dbg("%d %d\n", i, a[i]);
        printf("Case #%d: %d\n", Case, ans);
    }
    return 0;
}