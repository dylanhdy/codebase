#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int t, n, k, a[MAXN];
LL ans;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        sort(a+1, a+n+1);
        ans=a[n];
        for(int i=n-1; i>=n-k; --i) ans+=a[i];
        printf("%lld\n", ans); 
    }
    return 0;
}