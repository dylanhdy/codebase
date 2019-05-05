#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#define MAXN 1000005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, k, c, r, l=1, q[MAXN];
LL a[MAXN], f[MAXN], g[MAXN];

double K(int x, int y)
{
    return 1.0*(f[x]+a[x+1]*a[x+1]-f[y]-a[y+1]*a[y+1])/(a[x+1]-a[y+1]);
}

void insert(int i)
{
    while(l<=r && a[i-k+1]==a[q[r]+1])
    {
        if(f[i-k]<f[q[r]]) r--;
        else return;
    }
    while(l<r && K(i-k, q[r])<K(q[r], q[r-1])) r--;
    q[++r]=i-k;
}

int main()
{
    scanf("%d%d%d", &n, &k, &c);
    for(rint i=1; i<=n; ++i) scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
    q[++r]=0;
    for(rint i=k; i<=n; ++i)
    {
        if(i>=2*k)
        {
            insert(i);
            while(l<r && K(q[l+1], q[l])<a[i]*2) l++;
        }
        int pos=q[l];
        f[i]=f[pos]+(a[i]-a[pos+1])*(a[i]-a[pos+1])+c;
    }
    printf("%lld\n", f[n]);
    return 0;
}
