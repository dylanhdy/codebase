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
#define MAXN 400005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;

int n, cnt, ans, x[MAXN], y[MAXN], z[MAXN], sub[MAXN], val[MAXN], f[MAXN], pre[MAXN];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
        sub[++cnt]=x[i], sub[++cnt]=y[i];
    }
    sort(sub+1, sub+cnt+1);
    for(int i=1; i<=n; ++i) {
        x[i]=lower_bound(sub+1, sub+cnt+1, x[i])-sub;
        y[i]=lower_bound(sub+1, sub+cnt+1, y[i])-sub;
        val[x[i]]=y[i];
    }
    for(int i=1; i<=cnt; ++i) {
        if(val[i])
            f[i]=((pre[i-1]-pre[val[i]]+sub[i]-sub[val[i]])%P+P)%P;
        pre[i]=(pre[i-1]+f[i])%P;
    }
    for(int i=1; i<=n; ++i)
        if(z[i]) ans=(ans+f[x[i]])%P;
    printf("%d\n", (ans+sub[cnt]+1)%P);
    return 0;
}