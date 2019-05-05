#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#define MAXN 100005
#define MAXM 1005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, a[MAXN];
bitset<MAXN> f, g;

int main()
{
    //freopen("array.in", "r", stdin);
    //freopen("array.out", "w", stdout);
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    if(a[1]!=a[2]) {printf("%d\n", a[1]); return 0;}
    f[0]=1;
    for(rint i=a[n], j=n; i>=1; --i)
    {
        if(a[j]==i)
        {
            f[i]=1;
            for(rint k=a[j]; k<=a[n]; k+=a[j]) g[k]=1;
            j--;
        }
        else f[i]=((f>>i)&g).any();
    }
    for(rint i=a[1]-1; i>=0; i--)
        if(f[i]) {printf("%d\n", i); return 0;}
    return 0;
}