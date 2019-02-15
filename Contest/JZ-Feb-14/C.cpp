#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAXN 1005
#define P 1000000007
#define rint register int
#define INF 0x3f3f3f3f
using namespace std;

int n, m, ans, f[MAXN], a[MAXN], b[MAXN], g[MAXN], tag[MAXN];

int main()
{
	scanf("%d%d", &n, &m);
	for(rint i=1, x, y; i<=m; ++i)
	{
		scanf("%d%d", &x, &y);
		f[max(x, y)]++;
		g[min(x, y)]++;
	}
    int minn=INF;
	for(rint i=1; i<=n; ++i)
	{
		a[i]=i-f[i]+g[i];
		if(a[i]<minn)
        {
            minn=a[i];
            b[i]=1;
        }
	}
	for(rint i=1; i<=n; ++i)
    {
        int temp=0;
        for(rint j=i-1; j>=1; --j)
            if(a[j]>temp && a[j]<a[i])
            {
                temp=a[j];
                b[i]=(b[i]+b[j])%P;
            } 
    }
    int maxn=0;
	for(rint i=n; i>=1; --i)
        if(a[i]>maxn)
        {
            ans=(ans+b[i])%P;
            maxn=a[i];
        }
    printf("%d\n", ans);
}
