#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 100
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, tot, val, a[MAXN][MAXN], p[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];

struct Ans
{
    int x1, x2, y1, y2, k;
    Ans(int a=0, int b=0, int c=0, int d=0, int e=0)
    {
        x1=a, y1=b, x2=c, y2=d, k=e;
    }
    void print()
    {
        printf("%d %d %d %d %d\n", x1, y1, x2, y2, k);
    }
} ans[MAXN*MAXN], t;

void solve(int x1, int y1, int k)
{
    for(rint i=x1; i<=n; ++i) b[i][y1-1]=0;
    for(rint i=y1; i<=m; ++i) c[x1-1][i]=0;
    for(rint i=x1; i<=n; ++i)
        for(rint j=y1; j<=m; ++j)
        {
            int temp=0;
            if(a[i][j]==0) temp--;
            if((a[i][j]+k)%p[i][j]==0) temp++;
            b[i][j]=b[i][j-1]+temp;
            c[i][j]=c[i-1][j]+b[i][j];
            if(c[i][j]>val)
            {
                val=c[i][j];
                t=Ans(x1, y1, i, j, k);
            }
        }
}

int main()
{
    freopen("bake.in", "r", stdin);
    freopen("bake.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(rint i=1; i<=n; ++i)
        for(rint j=1; j<=m; ++j) scanf("%d", &p[i][j]);
    for(rint i=1; i<=n; ++i)
        for(rint j=1; j<=m; ++j) scanf("%d", &a[i][j]);
    for(rint i=1; i<=n; ++i)
        for(rint j=1; j<=m; ++j)
        {
            if(a[i][j]==0) continue;
            val=0;
            for(rint k=0; k<=15; ++k) solve(i, j, k*p[i][j]+p[i][j]-a[i][j]);
            ans[++tot]=t;
            for(rint x=t.x1; x<=t.x2; x++)
                for(rint y=t.y1; y<=t.y2; ++y) a[x][y]=(a[x][y]+t.k)%p[x][y];
        }
    printf("%d\n", tot);
    for(rint i=1; i<=tot; ++i) ans[i].print();
    return 0;
}