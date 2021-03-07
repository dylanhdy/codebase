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
#define INF
using namespace std;

int n, L, a[MAXN], b[MAXN];
LL ans;

int main()
{
    scanf("%d%d", &n, &L);
    a[0]=0, a[n+1]=L+1;
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1; i<=n; ++i) scanf("%d", &b[i]);

    for(int l=1, r=0, pos=0; l<=n; ++l)
    {
        if(l<=r) a[l]=a[r]-r+l;
        if(a[l]<b[l])
        {
            while(a[pos+1]-b[l]<pos+1-l && pos<=n) pos++;
            if(a[pos+1]-b[l]==pos+1-l && pos<=n)
            {
                pos++, r=pos;
                ans+=pos-l;
                a[l]=b[l];
            }
        }
    }
    for(int r=n, l=n+1, pos=n+1; r>=1; --r)
    {
        if(l<=r) a[r]=a[l]+r-l;
        if(a[r]>b[r])
        {
            while(b[r]-a[pos-1]<r-pos+1 && pos>=1) pos--;
            if(b[r]-a[pos-1]==r-pos+1 && pos>=1)
            {
                pos--, l=pos;
                ans+=r-pos;
                a[r]=b[r];
            }
        }
    }
    for(int i=1; i<=n; ++i)
        if(a[i]!=b[i])
        {
            printf("-1\n");
            return 0;
        }
    printf("%lld\n", ans);
    return 0;
}