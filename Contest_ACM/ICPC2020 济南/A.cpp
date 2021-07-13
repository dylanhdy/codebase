#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 205
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, ans=1, a[MAXN][MAXN], b[MAXN][MAXN], d[MAXN][MAXN];

void solve()
{
    int r=1, c=1;
    for(; c<=n; ++c) {
        int pos=0;
        for(int i=r; i<=n; ++i)
            if(d[i][c]) pos=i;
        if(!pos) continue;
        for(int i=c; i<=n; ++i) swap(d[r][i], d[pos][i]);
        for(int i=1; i<=n; ++i) {
            if(i==r || d[i][c]==0) continue;
            for(int j=c; j<=n; ++j) d[i][j]^=d[r][j];
        }
        r++;
    }
    for(int i=r; i<=n; ++i) ans=1LL*ans*2%P;
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j) scanf("%d", &a[i][j]);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j) scanf("%d", &b[i][j]);
    for(int j=1; j<=n; ++j) {
        for(int i=1; i<=n; ++i)
            for(int k=1; k<=n; ++k) {
                if(k==i) d[i][k]=(a[i][k]^b[i][j]);
                else d[i][k]=a[i][k];
            }
        solve();
    }
    printf("%d\n", ans);
    return 0;
}