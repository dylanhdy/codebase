#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 2e18
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m;
LL sum, a[MAXN];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%lld", &a[i]);
        sum+=a[i];
    }
    sort(a+1, a+n+1);
    scanf("%d", &m);
    for(int i=1; i<=m; ++i) {
        LL x, y, ans=INF;
        scanf("%lld%lld", &x, &y);
        int pos=upper_bound(a+1, a+n+1, x)-a;
        //printf("%d??\n", pos);
        if(pos<=n) {
            ans=max((LL)0, y-sum+a[pos]);
        }
        if(pos>1) {
            ans=min(ans, x-a[pos-1]+max((LL)0, y-sum+a[pos-1]));
        }
        printf("%lld\n", ans);
    }
    return 0;
}