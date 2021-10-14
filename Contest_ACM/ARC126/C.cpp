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
#define MAXN 300005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, a[MAXN], suf[MAXN];
LL k, ans, sum;

int main()
{
    scanf("%d%lld", &n, &k);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        m=max(a[i], m);
        suf[a[i]]++;
        sum+=a[i];
    }
    for(int i=m; i>=1; --i) suf[i]+=suf[i+1];
    for(int i=1; i<=m; ++i) {
        LL num=0;
        for(int j=0; j*i<=m; ++j) num+=suf[i*j+1];
        if(num*i<=sum+k) ans=max(ans, (LL)i);
    }
    if(1LL*n*m<=sum+k) ans=max(ans, (sum+k)/n);
    printf("%lld\n", ans);
    return 0;
}