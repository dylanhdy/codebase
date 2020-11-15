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
#define INF 0x3f3f3f3f
using namespace std;

int n, r, ans, t[MAXN], x[MAXN], y[MAXN], f[MAXN], g[MAXN];

int main()
{   
    scanf("%d%d", &r, &n);
    memset(f, -0x3f, sizeof(f));
    f[0]=0, x[0]=y[0]=1;
    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d%d", &t[i], &x[i], &y[i]);
        int j;
        for(j=i-1; j>=0 && t[i]-t[j]<2*r; --j)
            if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j]) f[i]=max(f[i], f[j]+1);
        if(j>=0) f[i]=max(f[i], g[j]+1);
        g[i]=max(f[i], g[i-1]);
        ans=max(ans, f[i]);
    }
    printf("%d\n", ans);
    return 0;
}