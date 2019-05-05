#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 200005
#define MAXM 205
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, q, a[MAXN], sum[MAXM], tag[MAXM], f[MAXM][MAXM], g[MAXM][MAXM], h[MAXM], ans[MAXN];

struct Ask {int b, c, d, id;} ask[MAXN];

bool CMP(Ask x, Ask y) {return x.b<y.b;}

inline int add(int x, int y)
{
    return x+y>P?x+y-P:x+y;
}

inline int sub(int x, int y)
{
    return x<y?x-y+P:x-y;
}

int main()
{
    freopen("third.in", "r", stdin);
    freopen("third.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for(rint i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(rint i=1; i<=q; ++i)
    {
        scanf("%d%d%d", &ask[i].b, &ask[i].c, &ask[i].d);
        ask[i].id=i;
    }
    sort(ask+1, ask+q+1, CMP);
    for(rint i=0; i<=m; ++i) f[i][i]=1, sum[i]=1;
    for(rint i=1; i<=n; ++i)
        for(rint j=0; j<=m; ++j)
        {
            int temp=f[j][a[i]];
            f[j][a[i]]=sum[j];
            sum[j]=add(sum[j], sub(sum[j], temp));
        }
    for(rint i=0; i<=m; ++i) g[i][i]=1, sum[i]=1;
    for(rint i=1, k=1; i<=n; ++i)
    {
        for(rint j=0; j<=m; ++j)
        {
            int temp=tag[j];
            tag[j]=add(tag[j], sub(f[a[i]][j], temp));
            f[a[i]][j]=add(f[a[i]][j], sub(f[a[i]][j], temp));
        }
        while(ask[k].b==i && k<=q)
        {
            int c=ask[k].c, d=ask[k].d;
            for(rint j=0; j<=m; ++j) h[j]=sub(add(f[0][j], f[c][j]), tag[j]*2%P);
            for(rint j=0; j<=m; ++j) ans[ask[k].id]=add(ans[ask[k].id], 1LL*h[j]*g[j][d]%P);
            k++;
        }
        for(rint j=0; j<=m; ++j)
        {
            int temp=g[j][a[i]];
            g[j][a[i]]=sum[j];
            sum[j]=add(sum[j], sub(sum[j], temp));
        }
    }
    for(rint i=1; i<=q; ++i) printf("%d\n", ans[i]);
    return 0;
}