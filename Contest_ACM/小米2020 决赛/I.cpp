#include <bits/stdc++.h>
#define LL long long
#define ls (root<<1)
#define rs (root<<1|1)
#define mid ((l+r)>>1)
#define MAXN 200005
using namespace std;

int n, k, T, a[MAXN];
LL pre[MAXN], f[MAXN], t[MAXN<<2], ans=1e18;

int find(int l, int r, LL val)
{
    int pos=r;
    while(l<=r)
    {
        if(pre[mid-1]>=val) pos=mid, r=mid-1;
        else l=mid+1;
    }
    return pos;
}

void update(int root, int l, int r, int x, LL k)
{
    if(l==r)
    {
        t[root]=k;
        return;
    }
    if(x<=mid) update(ls, l, mid, x, k);
    else update(rs, mid+1, r, x, k);
    t[root]=min(t[ls], t[rs]);
}

LL query(int root, int l, int r, int x, int y)
{
    if(l>y || r<x) return 1e18;
    if(l>=x && r<=y) return t[root];
    return min(query(ls, l, mid, x, y), query(rs, mid+1, r, x, y));
}

int main()
{
    memset(t, 0x3f, sizeof(t));
    scanf("%d%d%d", &n, &k, &T);
    update(1, 0, n, 0, 0);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        pre[i]=pre[i-1]+a[i];
        int pos=find(1, i, pre[i]-T);
        LL temp=1e18;
        if(pos<=i-k)
            temp=query(1, 0, n, pos-1, i-k-1);
        f[i]=min(f[i-1]+a[i], temp);
        update(1, 0, n, i, f[i]);
        //printf("%d %d %lld %lld\n", i, pos, f[i], temp);
    }
    for(int i=n; i>=1; --i)
        if(pre[n]-pre[i]<=T) ans=min(ans, f[i]);
    printf("%lld\n", ans);
}