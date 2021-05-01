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
    for(int i=1; i<=n; ++i) {
        int pos=0;
        for(int j=i; j<=n; ++j)
            if(a[j][i]!=0) pos=j;
        if(pos==0) continue;
        for(int j=i; j<=n+1; ++j) swap(a[i][j], a[pos][j]);
        for(int j=n+1; j>=i; --j) a[i][j]/=a[i][i];
        for(int j=1; j<=n; ++j) {
            if(i==j) continue;
            for(int k=n+1; k>=i; --k) a[j][k]-=a[j][i]*a[i][k];
        }
    }
    for(int i=1; i<=n; ++i)
        if(a[i][i]==0) {
            printf("No Solution\n");
            return 0;
        }
    for(int i=1; i<=n; ++i) printf("%.2lf\n", a[i][n+1]);
    return 0;
}