#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#define MAXN 520
#define INF 0x3f3f3f3f
#define rint register int
using namespace std;

int k, n, ans=INF, w[MAXN][MAXN], f[MAXN][MAXN];

int main()
{
	scanf("%d", &k);
    n=1<<k;
	for(rint i=0; i<n; ++i)
		for(rint j=0; j<n; ++j) scanf("%d", &w[i][j]);
    memset(f, 0x3f, sizeof(f));
    for(rint i=0; i<n; ++i) f[0][i]=0;
    for(rint i=1; i<n; ++i)
        for(rint j=0; j<n; ++j)
        {
            int lowbit=i&(-i);
            int l=(j^lowbit)&(~(lowbit-1));
            int r=l+lowbit-1;
            for(rint k=l; k<=r; ++k) f[i][k]=min(f[i][k], f[i-1][j]+w[j][k]);
        }
    for(rint i=0; i<n; ++i) ans=min(ans, f[n-1][i]);
	printf("%d\n", ans);
}
