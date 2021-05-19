#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 1000005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, f[MAXN];

void init()
{
    for(int i=2; i<=1e6; ++i) {
        f[i]=1;
        for(int j=2; j*j<=i; ++j)
            if(i%j==0) {
                f[i]=max(f[i], f[i/j-1]+1);
                f[i]=max(f[i], f[j-1]+1);
            }
        //printf("%d %d\n", i, f[i]);
    }
}

int main()
{
    init();
    scanf("%d", &T);
    for(int i=1; i<=T; ++i) {
        scanf("%d", &n);
        int ans=1;
        for(int i=3; i*i<=n; ++i)
            if(n%i==0) {
                ans=max(ans, f[n/i-1]+1);
                ans=max(ans, f[i-1]+1);
            }
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}