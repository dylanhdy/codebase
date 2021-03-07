#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define INF
using namespace std;

int n, a[MAXN], b[MAXN], c[MAXN], d[MAXN];
LL ans;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        ans+=a[i];
    }
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &b[i]);
        a[i]=b[i]-a[i];
        if(i%2) c[(i+1)/2]=a[i];
        else d[i/2]=a[i];
    }
    sort(c+1, c+n/2+1, greater<int>());
    sort(d+1, d+n/2+1, greater<int>());
    for(int i=1; i<=n; ++i)
        if(c[i]+d[i]>0) ans+=c[i]+d[i];
    printf("%lld\n", ans);
    return 0;
}