#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 50005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, a[MAXN], minn[MAXN], maxn[MAXN], num[MAXN*2];
LL ans;

void cal(int l, int r, int mid)
{
    minn[mid]=maxn[mid]=a[mid];
    for(rint i=mid-1; i>=l; --i)
    {
        minn[i]=min(minn[i+1], a[i]);
        maxn[i]=max(maxn[i+1], a[i]);
    }
    minn[mid+1]=maxn[mid+1]=a[mid+1];
    for(rint i=mid+2; i<=r; ++i)
    {
        minn[i]=min(minn[i-1], a[i]);
        maxn[i]=max(maxn[i-1], a[i]);
    }
    int L=mid+1, R=mid+1;
    for(rint i=mid, j=mid; i>=l; i--)
    {
        while(j<r && maxn[j+1]<maxn[i] && minn[j+1]>minn[i]) j++;
        if(mid<j && j-i==maxn[i]-minn[i]) ans++;
        while(R<=r && maxn[R]<maxn[i]) num[minn[R]+R]++, R++;
        while(L<=r && minn[L]>minn[i]) num[minn[L]+L]--, L++;
        ans+=max(0, num[maxn[i]+i]);
    }
    while(R<=r) num[minn[R]+R]++, R++;
    while(L<=r) num[minn[L]+L]--, L++;
}

void solve(int l, int r)
{
    if(l==r) {ans++; return;}
    int mid=(l+r)>>1;
    cal(l, r, mid);
    reverse(a+l, a+r+1);
    cal(l, r, l+r-mid-1);
    reverse(a+l, a+r+1);
    solve(l, mid);
    solve(mid+1, r);
}

int main()
{
    scanf("%d", &n);
    for(rint i=1, x, y; i<=n; ++i)
    {
        scanf("%d%d", &x, &y);
        a[x]=y;
    }
    solve(1, n);
    printf("%lld\n", ans);
    return 0;
}