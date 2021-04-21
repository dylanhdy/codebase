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

int T, n, f[MAXN][MAXN], g[MAXN][MAXN], a[MAXN];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        for(int i=1; i<=n; ++i) f[i][i]=g[i][i];
        for(int len=2; len<=n; ++len)
            for(int i=1; i+len-1<=n; ++i) {
                int j=i+len-1;
                if(g[i+1][j]>a[j]) f[i][j]=1;
                else f[i][j]=min(a[i]+1, f[i][j-1]+a[j]-g[i+1][j]+1);
                if(f[i][j-1]>a[i]) g[i][j]=1;
                else g[i][j]=min(a[j]+1, g[i+1][j]+a[i]-f[i][j-1]+1);
            }
        if(f[1][n]<=a[1]) printf("First\n");
        else printf("Second\n");
    }
    return 0;
}