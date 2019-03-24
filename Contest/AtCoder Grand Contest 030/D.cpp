#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 3005
#define P 1000000007
#define INV 500000004
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, q, ans, a[MAXN], f[MAXN][MAXN];

inline int add(int x, int y) {return x+y>=P?x+y-P:x+y;}
inline int sub(int x, int y) {return x>=y?x-y:x-y+P;}

inline int ksm(int x, int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=1LL*x*ans%P;
        x=1LL*x*x%P, y>>=1;
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &q);
    for(rint i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(rint i=1; i<=n; ++i)
        for(rint j=1; j<=n; ++j) if(a[i]>a[j]) f[i][j]=1;
    for(rint i=1, x, y; i<=q; ++i)
    {
        scanf("%d%d", &x, &y);
        int t1, t2;
        for(rint j=1; j<=n; ++j)
        {
            if(j==x || j==y) continue;
            t1=f[x][j], t2=f[y][j];
            f[y][j]=f[x][j]=1LL*add(t1, t2)*INV%P;
            t1=f[j][x], t2=f[j][y];
            f[j][x]=f[j][y]=1LL*add(t1, t2)*INV%P;
        }
        
        t1=f[x][y], t2=f[y][x];
        f[x][y]=f[y][x]=1LL*add(t1, t2)*INV%P;
    }
    int temp=ksm(2, q);
    for(rint i=1; i<=n; ++i)
        for(rint j=i+1; j<=n; ++j)
            ans=add(ans, 1LL*f[i][j]*temp%P);
    printf("%d\n", ans);
    return 0;
}
