#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 2000005
#define p 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

inline int R()
{
    int rt = 0; char ch = getchar(); bool isn = false;
    for (; ch < '0' || ch > '9'; ch = getchar()) isn = ch == '-' ? true : isn;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) rt = rt * 10 + ch - '0';
    return isn ? -rt : rt;
}
int n, q, S, A, B, P, tp, top, a[MAXN], Log[MAXN], sta[MAXN], f[MAXN][23];
LL ans, lastans, pre[MAXN], spre[MAXN], suf[MAXN], ssuf[MAXN], s1[MAXN], s2[MAXN];

inline int Rand()
{
    S = (S * A % P + (B ^ (tp * lastans))) % P;
    S = S < 0 ? -S : S;
    return S;
}

inline int query(int x, int y)
{
    int k=Log[y-x+1];
    if(a[f[x][k]]>a[f[y-(1<<k)+1][k]]) return f[x][k];
    else return f[y-(1<<k)+1][k];
}

inline LL Solve(int l, int r)
{
    LL sum=0;
    int pos=query(l, r);
    sum+=1LL*(pos-l+1)*(r-pos+1)*a[pos];
    sum+=ssuf[l]-ssuf[pos]-1LL*(pos-l)*suf[pos];
    sum+=spre[r]-spre[pos]-1LL*(r-pos)*pre[pos];
    sum+=1LL*(n-r)*(s2[r-1]-s2[max(0, l-2)])-(s1[r-1]-s1[max(0, l-2)]);
    return sum;
}

int main()
{
    freopen("cubelia.in", "r", stdin);
    freopen("cubelia.out", "w", stdout);
    n = R(), q = R();
    for (rint i = 1; i <= n; ++i)
    {
        a[i] = R() + a[i - 1];
        s1[i]=s1[i-1]+1LL*a[i]*(n-i);
        s2[i]=s2[i-1]+a[i];
    }
    S = R(), A = R(), B = R(), P = R(), tp = R();
    for(rint i=1; i<=n; ++i)
    {
        f[i][0]=i;
        if(i>1) Log[i]=Log[i/2]+1;
    }
    for (rint i = 1; i < 23; ++i)
        for (rint j = 1; j + (1 << i) - 1 <= n; ++j)
        {
            if (a[f[j][i - 1]] > a[f[j + (1 << i - 1)][i - 1]])
                f[j][i] = f[j][i - 1];
            else
                f[j][i] = f[j + (1 << i - 1)][i - 1];
        }
    sta[top=0]=0;
    for(rint i=1; i<=n; ++i)
    {
        while(top && a[sta[top]]<a[i]) top--;
        pre[i]=pre[sta[top]]+1LL*a[i]*(i-sta[top]);
        sta[++top]=i;
        spre[i]=spre[i-1]+pre[i];
    }
    sta[top=0]=n+1;
    for(rint i=n; i>=1; --i)
    {
        while(top && a[sta[top]]<a[i]) top--;
        suf[i]=suf[sta[top]]+1LL*(sta[top]-i)*a[i];
        sta[++top]=i;
        ssuf[i]=ssuf[i+1]+suf[i];
    }
    for (rint i = 1; i <= q; ++i)
    {
        int l = Rand() % n + 1, r = Rand() % n + 1;
        if (l > r)
            swap(l, r);
        lastans = Solve(l, r);
        ans+=lastans%p;
    }
    printf("%lld\n", (ans%p+p)%p);
    return 0;
}