#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 1000005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, p[MAXN];
LL ans, f[MAXN], t[MAXN*2];

struct A {int id, a, t;} a[MAXN];

bool CMP(A x, A y)
{
    return x.id-x.t<y.id-y.t;
}

inline void add(int x, LL y)
{
    for(; x<=n*2; x+=(x&-x)) t[x]=max(t[x], y);
}

inline LL ask(int x)
{
    LL sum=0;
    for(; x; x-=(x&-x)) sum=max(sum, t[x]);
    return sum;
}

int main()
{
    freopen("fc.in", "r", stdin);
    freopen("fc.out", "w", stdout);
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i) scanf("%d", &p[i]), a[i].t=p[i];
    for(rint i=1; i<=n; ++i) scanf("%d", &a[i].a), a[i].id=i;
    sort(a+1, a+n+1, CMP);
    int pos=1;
    while(a[pos].id-a[pos].t<=0 && pos<=n)
    {
        f[a[pos].id]=max(f[a[pos].id], 1LL*a[pos].t*a[pos].a);
        pos++;
    }
    for(rint i=1; i<=n; ++i)
    {
        add(i+p[i], f[i]);
        while(a[pos].id-a[pos].t==i && pos<=n)
        {
            f[a[pos].id]=max(f[a[pos].id], ask(a[pos].id)+1LL*a[pos].t*a[pos].a);
            pos++;
        }
    }
    printf("%lld\n", ask(n*2));
    return 0;
}