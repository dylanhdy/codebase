#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 1000005
#define P 998244353
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, cnt, ans, head[MAXN], dep[MAXN], f[MAXN][21];

int ksm(int x, int y)
{
	int sum=1;
	while(y)
	{
		if(y&1) sum=1LL*x*sum%P;
		x=1LL*x*x%P, y>>=1;
	}
	return sum;
}

struct Edge {int next, to;} edge[MAXN*2];
struct E {int x, y, val;} e[MAXN];
struct Pro
{
	int val, cnt;
	Pro(int _val=0, int _cnt=0) {val=_val, cnt=_cnt;}

	int cal() {return cnt?0:val;}

	Pro friend operator * (Pro x, int y)
	{
		if(!y) return Pro(x.val, x.cnt+1);
		return Pro(1LL*x.val*y%P, x.cnt);
	}
	Pro friend operator * (Pro x, Pro y)
	{
		return Pro(1LL*x.val*y.val%P, x.cnt+y.cnt);
	}
	Pro friend operator / (Pro x, int y)
	{
		if(!y) return Pro(x.val, x.cnt-1);
		return Pro(1LL*x.val*ksm(y, P-2)%P, x.cnt);
	}
	Pro friend operator / (Pro x, Pro y)
	{
		return Pro(1LL*x.val*ksm(y.val, P-2)%P, x.cnt-y.cnt);
	}
} sum1[MAXN], sum2[MAXN];

map<pii, Pro> mp;
 
inline void addedge(int from, int to)
{
	edge[++cnt].next=head[from];
	edge[cnt].to=to;
	head[from]=cnt;
}

void dfs1(int x, int fa)
{
	dep[x]=dep[fa]+1, f[x][0]=fa;
	for(rint i=head[x]; i; i=edge[i].next)
	{
		int to=edge[i].to;
		if(to==fa) continue;
		dfs1(to, x);
	}
}

inline int lca(int x, int y)
{
	if(dep[x]<dep[y]) swap(x, y);
	for(rint i=20; i>=0; --i)
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(rint i=20; i>=0; --i)
		if(f[x][i]!=f[y][i]) x=f[x][i], y=f[y][i];
	return f[x][0];
}

inline int jump(int x, int d)
{
	for(rint i=20; i>=0; --i)
		if(dep[f[x][i]]>=d) x=f[x][i];
	return x;
}

void dfs2(int x, int fa)
{
	for(rint i=head[x]; i; i=edge[i].next)
	{
		int to=edge[i].to;
		if(to==fa) continue;
		sum1[to]=sum1[x]*sum1[to];
		dfs2(to, x);
		sum2[x]=sum2[x]*sum2[to];
	}
}

int main()
{
	freopen("cactus.in", "r", stdin);
	freopen("cactus.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(rint i=1, x, y; i<n; ++i)
	{
		scanf("%d%d", &x, &y);
		addedge(x, y);
		addedge(y, x);
	}
	dfs1(1, 0);
	for(rint i=1; i<21; ++i)
		for(rint j=1; j<=n; ++j) f[j][i]=f[f[j][i-1]][i-1];
	for(rint i=1; i<=n; ++i) sum1[i].val=sum2[i].val=1;
	for(rint i=1; i<=m; ++i)
	{
		scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].val);
		int Lca=lca(e[i].x, e[i].y);
		int fx=jump(e[i].x, dep[Lca]+1), fy=jump(e[i].y, dep[Lca]+1);
		if(e[i].x!=Lca)
		{
			sum1[fx]=sum1[fx]*e[i].val;
			sum2[e[i].x]=sum2[e[i].x]*e[i].val;
			sum2[Lca]=sum2[Lca]/e[i].val;
		}
		if(e[i].y!=Lca)
		{
			sum1[fy]=sum1[fy]*e[i].val;
			sum2[e[i].y]=sum2[e[i].y]*e[i].val;
			sum2[Lca]=sum2[Lca]/e[i].val;
		}
		if(e[i].x!=Lca && e[i].y!=Lca)
		{
			pii temp=make_pair(min(fx, fy), max(fx, fy));
			if(mp.find(temp)==mp.end())
			{
				if(e[i].val) mp[temp]=Pro(e[i].val, 0);
				else mp[temp]=Pro(1, 1);
			}
			else mp[temp]=mp[temp]*e[i].val;
		}
	}
	dfs2(1, 0);
	//for(rint i=1; i<=n; ++i) printf("%d %d!!\n", sum1[i].cal(), sum2[i].cal());
	for(rint i=1; i<=m; ++i)
	{
		int Lca=lca(e[i].x, e[i].y);
		int fx=jump(e[i].x, dep[Lca]+1), fy=jump(e[i].y, dep[Lca]+1);
		Pro val1, val2;
		val1.val=val2.val=1;
		if(e[i].x!=Lca) val1=sum2[fx]*sum1[e[i].x]/sum1[fx];
		if(e[i].y!=Lca) val2=sum2[fy]*sum1[e[i].y]/sum1[fy];
		Pro val=val1*val2;
		if(e[i].x!=Lca && e[i].y!=Lca)
		{
			pii temp=make_pair(min(fx, fy), max(fx, fy));
			val=val/mp[temp];
		}
		val=val/e[i].val*(1+P-e[i].val);
		ans=(ans+val.cal())%P;
	}
	printf("%d\n" , (ans+P)%P);
	return 0;
}