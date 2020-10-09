#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 100005
#define P 998244353
#define INF 0x3f3f3f3f
#define eps 1e-11
#define rint register int
#define LL long long
#define LD long double
#define ls (root<<1)
#define rs (root<<1|1)
#define mid ((l+r)>>1)
using namespace std;

int n, m, sum[MAXN*4];
LD maxn[MAXN*4];

int cal(int root, int l, int r, LD k)
{
    if(l==r) return maxn[root]>k;
    if(maxn[ls]>k) return cal(ls, l, mid, k)+sum[root]-sum[ls];
    else return cal(rs, mid+1, r, k);
}

void update(int root, int l, int r, int x, LD k)
{
    if(l==r)
    {
        sum[root]=1, maxn[root]=k;
        return;
    }
    if(x<=mid) update(ls, l, mid, x, k);
    else update(rs, mid+1, r, x, k);
    maxn[root]=max(maxn[ls], maxn[rs]);
    sum[root]=sum[ls]+cal(rs, mid+1, r, maxn[ls]);
}

int main()
{
    scanf("%d%d", &n, &m);
    for(rint i=1, x, y; i<=m; ++i)
    {
        scanf("%d%d", &x, &y);
        update(1, 1, n, x, 1.0*y/x);
        printf("%d\n", sum[1]);
    }
    return 0;
}
