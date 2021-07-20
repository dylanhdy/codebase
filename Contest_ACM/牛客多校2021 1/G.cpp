#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define LD long double
#define MAXN 500005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, k, a[MAXN], b[MAXN], c[MAXN], d[MAXN];
LL ans;

int main()
{
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1; i<=n; ++i) scanf("%d", &b[i]);
    if(n==2) {
        if(k&1) swap(a[1], a[2]);
        printf("%d\n", abs(a[1]-b[1])+abs(a[2]-b[2]));
        return 0;
    }
    for(int i=1; i<=n; ++i) {
        c[i]=min(a[i], b[i]);
        d[i]=max(a[i], b[i]);
        ans+=abs(a[i]-b[i]);
    }
    sort(c+1, c+n+1);
    sort(d+1, d+n+1);
    for(int i=1; i<=min(k, n); ++i)
        if(c[n-i+1]>d[i]) ans+=2*(c[n-i+1]-d[i]);
    printf("%lld\n", ans);
    return 0;
}