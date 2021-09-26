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
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, a[MAXN];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        sort(a+1, a+n+1);
        double ans=0;
        for(int i=1; i<n; ++i) ans+=1.0*a[i]/(n-1);
        ans+=a[n];
        printf("%.10lf\n", ans);
    }
    return 0;
}