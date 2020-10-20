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

int n, m, ans=INF, w[10], pos[10], len[MAXN], f[10][10], pre[10];

struct Bridge {int l, v;} bri[MAXN];

bool CMP(Bridge x, Bridge y)
{
    if(x.v!=y.v) return x.v<y.v;
    return x.l>=y.l;
}

int divide(int weight)
{
    int l=1, r=m, ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(weight>bri[mid].v) ans=mid, l=mid+1;
        else r=mid-1;
    }
    return len[ans];
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d", &w[i]);
    for(int i=1; i<=m; ++i) scanf("%d%d", &bri[i].l, &bri[i].v);
    sort(bri+1, bri+m+1, CMP);
    for(int i=1; i<=n; ++i)
        if(w[i]>bri[1].v)
        {
            printf("-1\n");
            return 0;
        }
    for(int i=1; i<=m; ++i) len[i]=max(len[i-1], bri[i].l);
    for(int i=1; i<=n; ++i) pos[i]=i;
    while(next_permutation(pos+1, pos+n+1))
    {
        for(int i=1; i<=n; ++i) pre[i]=pre[i-1]+w[pos[i]];
        for(int i=1; i<=n; ++i)
            for(int j=i+1; j<=n; ++j)
                f[i][j]=divide(pre[j]-pre[i-1]);
        for(int k=1; k<=n; ++k)
            for(int i=1; i<k; ++i)
                for(int j=k+1; j<=n; ++j) f[i][j]=max(f[i][j], f[i][k]+f[k][j]);
        ans=min(ans, f[1][n]);
    }
    printf("%d\n", ans);
    return 0;
}