#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 605
#define P 1000000007
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, ans, k1, k2, a[MAXN], tag[MAXN], f[MAXN][305][305];

inline int add(int x, int y) {return x+y>=P?x+y-P:x+y;}
inline int sub(int x, int y) {return x>=y?x-y:x-y+P;}

int main()
{
    scanf("%d", &n);
    for(rint i=1; i<=n*2; ++i) scanf("%d", &a[i]);
    for(rint i=1; i<=n*2; i+=2)
    {
        if(a[i]==-1 && a[i+1]==-1) k1++;
        else if(a[i]==-1) k2++, tag[a[i+1]]=1;
        else if(a[i+1]==-1) k2++, tag[a[i]]=1;
        else tag[a[i]]=2, tag[a[i+1]]=2;
    }
    f[n*2+1][0][0]=1;
    for(rint i=n*2; i>=1; --i)
    {
        for(rint j=0; j<=k2; ++j)
            for(rint k=0; k<=k1+k2; ++k)
            {
                if(tag[i]==1)
                {
                    f[i][j][k]=add(f[i][j][k], f[i+1][j][k+1]);
                    if(j) f[i][j][k]=add(f[i][j][k], f[i+1][j-1][k]);
                }
                if(tag[i]==0)
                {
                    if(k) f[i][j][k]=add(f[i][j][k], f[i+1][j][k-1]);
                    f[i][j][k]=add(f[i][j][k], 1LL*(j+1)*f[i+1][j+1][k]%P);
                    f[i][j][k]=add(f[i][j][k], f[i+1][j][k+1]);
                }
                if(tag[i]==2) f[i][j][k]=f[i+1][j][k];
                //printf("%d %d %d %d %d!!!!\n", tag[i], i, j, k, f[i][j][k]);
            }
    }
    ans=f[1][0][0];
    for(rint i=1; i<=k1; ++i) ans=1LL*ans*i%P;
    printf("%d\n", ans);
    return 0;
}
