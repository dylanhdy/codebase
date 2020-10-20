#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 100005
#define P 
using namespace std;

int t, n, a[MAXN], pre[MAXN], suf[MAXN];

int main()
{
    scanf("%d", &t);
    for(int num=1; num<=t; ++num)
    {
        LL add=0, ans=0, sum=0;
        scanf("%d", &n);
        pre[0]=0, suf[n]=0;
        for(int i=1; i<n; ++i)
        {
            scanf("%d", &a[i]);
            sum+=a[i];
        }
        for(int i=1; i<n; ++i) pre[i]=pre[i-1]+a[i];
        for(int i=n-1; i>=1; --i) suf[i]=suf[i+1]+a[i];
        printf("0");
        for(int i=1; i<n; ++i)
        {
            if(i%2) add+=sum-(pre[i/2]+suf[n-i/2]);
            ans+=add;
            printf(" %lld", ans);
        }
        printf("\n");
    }
    return 0;
}