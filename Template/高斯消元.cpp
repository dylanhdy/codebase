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
        for(int j=r; j<=n; ++j)
            if(a[j][c]!=0) pos=j;
        if(pos==0) continue;
        for(int j=c; j<=n+1; ++j) swap(a[r][j], a[pos][j]);
        for(int j=n+1; j>=c; --j) a[r][j]/=a[r][c];
        for(int j=1; j<=n; ++j) {
            if(r==j) continue;
            for(int k=n+1; k>=c; --k) a[j][k]-=a[j][c]*a[r][k];
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