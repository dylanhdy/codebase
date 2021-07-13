#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, a[MAXN];
LL ans, pre[MAXN], suf[MAXN], val[MAXN];

int solve(int x, LL lim)
{
    int num=0, l=0, r=(n-x+1)/2, ans=-(x!=1);
    while(l<=r) {
        int mid=(l+r)/2;
        if(val[x]-val[x+mid*2]+suf[x+mid*2]+lim>0) ans=mid, l=mid+1;
        else r=mid-1;
    }
    num+=ans+(x!=1);
    //printf("1 %d %d %d!\n", x, lim, ans);
    if(x==n) return num;
    lim-=a[n]*2;
    l=0, r=(n-x)/2-1, ans=-(x!=1);
    while(l<=r) {
        int mid=(l+r)/2;
        if(val[x]-val[x+mid*2]+suf[x+mid*2]+lim>0) ans=mid, l=mid+1;
        else r=mid-1;
    }
    num+=ans+(x!=1);
    //printf("2 %d %d %d!\n", x, lim, ans);
    return num;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        ans=0;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        if(n==2) {
            if(a[1]!=a[2]) printf("2\n");
            else printf("1\n");
            continue;
        }
        pre[0]=suf[n+1]=val[n+1]=0;
        for(int i=1; i<=n; ++i) pre[i]=pre[i-1]+a[i];
        for(int i=n; i>=1; --i) suf[i]=suf[i+1]+a[i];
        for(int i=n; i>=1; --i) val[i]=a[i]-val[i+1];
        for(int i=0; i<n; ++i) {
            ans+=solve(i+1, -pre[i]);
            if(i>2) ans+=solve(i+1, a[1]*2-pre[i]);
        }
        for(int i=1; i<=n; ++i) ans+=(pre[i]>suf[i+1]);
        printf("%lld\n", ans%P);
    }
    return 0;
}