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
using namespace std;
 
int n, m, siz, bel[MAXN], top[400];
LD h[MAXN], sta[400][405];
 
 
int main()
{
    scanf("%d%d", &n, &m);
    siz=400;
    for(rint i=1; i<=n; ++i) bel[i]=(i-1)/siz+1;
    for(rint i=1, x, y; i<=m; ++i)
    {
        scanf("%d%d", &x, &y);
        int pos=bel[x], ans=0;
        top[pos]=0, h[x]=1.0*y/x;
        for(rint j=(pos-1)*siz+1; j<=pos*siz; ++j)
            if(h[j]>sta[pos][top[pos]]) sta[pos][++top[pos]]=h[j];
        LD maxn=0;
        /*
        for(rint j=1; j<=bel[n]; ++j)
        {
            printf("%d:", j);
            for(rint k=1; k<=top[j]; ++k) printf("%lf ", sta[j][k]);
            printf("\n");
        }
        */
        for(rint j=1; j<=bel[n]; ++j)
        {
            int l=1, r=top[j], p=top[j]+1;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(sta[j][mid]>maxn+eps) p=mid, r=mid-1;
                else l=mid+1;
            }
            ans+=top[j]-p+1;
            maxn=max(maxn, sta[j][top[j]]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
