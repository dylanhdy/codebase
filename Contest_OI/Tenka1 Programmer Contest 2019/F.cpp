#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#define rint register int
#define LL long long
#define P 998244353
#define MAXN 3005
using namespace std;

int n, x, ans, c[MAXN][MAXN];

inline int add(int x, int y) {return x+y<P?x+y:x+y-P;}
inline int sub(int x, int y) {return x<y?x-y+P:x-y;}

int solve(int tot)
{
	int ans=0;
	if(x&1 || 2*tot<x) ans=1;
	for(rint i=tot; i<tot*2; ++i)
	{
		if(i>=x && (i-x)%2==0) continue;
		if(i<x) {ans=add(ans, c[tot][i-tot]); continue;}
		int temp=(i-x+1)/2;
		int resnum=i-temp*4, respos=tot-temp*2;
		if(temp*2<tot && resnum>=respos && resnum<=respos*2) ans=add(ans, c[respos][resnum-respos]);
	}
	return ans;
}

int main()
{
	scanf("%d%d", &n, &x);
	c[0][0]=1;
	for(rint i=1; i<=n; ++i)
	{
		c[i][0]=1;
		for(rint j=1; j<=i; ++j) c[i][j]=add(c[i-1][j], c[i-1][j-1]);
	}
	for(rint i=0; i<=n; ++i) ans=(ans+1LL*c[n][i]*solve(n-i))%P;
	printf("%d\n", ans);
	return 0;
}
