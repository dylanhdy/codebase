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

int n;
double a[MAXN][MAXN];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n+1; ++j) scanf("%lf", &a[i][j]);
    int c=1, r=1;
    for(; c<=n; ++c) {
        int pos=0;
        for(int i=r; i<=n; ++i)
            if(a[i][c]!=0) pos=i;
        if(pos==0) continue;
        for(int i=c; i<=n+1; ++i) swap(a[r][i], a[pos][i]);
        for(int i=n+1; i>=c; --i) a[r][i]/=a[r][c];
        for(int i=1; i<=n; ++i) {
            if(r==i) continue;
            for(int j=n+1; j>=c; --j) a[i][j]-=a[i][c]*a[r][j];
        }
        r++;
    }
    if(r<=n) {
        printf("No Solution\n");
        return 0;
    }
    for(int i=1; i<=n; ++i) printf("%.2lf\n", a[i][n+1]);
    return 0;
}