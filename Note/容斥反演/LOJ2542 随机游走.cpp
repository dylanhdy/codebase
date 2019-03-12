#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 
#define p 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, q, x, cnt, head[20], deg[20], a[20], b[20], f[1<<19], siz[1<<19];

struct Edge {int next, to;} edge[40];

void addedge(int from, int to)
{
	edge[++cnt].next=head[from];
	edge[cnt].to=to;
	deg[to]++;
	head[from]=cnt;
}

int ksm(int x, int y)
{
	int sum=1;
	while(y)
	{
		if(y&1) sum=(1LL*x*sum)%p;
		x=(1LL*x*x)%p; y>>=1;
	}
	return sum;
}

void dp(int sta, int x, int fa)
{

	int suma=0, sumb=0;
	if((sta>>(x-1))&1) {a[x]=b[x]=0; return;}
	for(rint i=head[x]; i; i=edge[i].next)
	{
		int to=edge[i].to;
		if(to==fa) continue;
		dp(sta, to, x);
		suma=(suma+a[to])%p;
		sumb=(sumb+b[to])%p;
	}
	int temp=ksm((deg[x]+p-suma)%p, p-2);
	a[x]=1LL*temp;
	b[x]=1LL*(sumb+deg[x])%p*temp%p;
}

int main()
{
	scanf("%d%d%d", &n, &q, &x);
	for(rint i=1, x, y; i<n; ++i)
	{
		scanf("%d%d", &x, &y);
		addedge(x, y);
		addedge(y, x);
	}
	for(rint sta=0; sta<(1<<n); ++sta)
	{
		dp(sta, x, 0);
		f[sta]=b[x];
		siz[sta]=siz[sta>>1]+(sta&1);
	}
	while(q--)
	{
		int sta=0, ans=0, k;
		scanf("%d", &k);
		for(rint i=1, x; i<=k; ++i)
		{
			scanf("%d", &x);
			sta|=(1<<(x-1));
		}
		for(rint i=sta; i; i=(i-1)&sta)
		{
			if(siz[i]&1) ans=(ans+f[i])%p;
			else ans=(ans+p-f[i])%p;
		}
		printf("%d\n", ans);
	}
	return 0;
}