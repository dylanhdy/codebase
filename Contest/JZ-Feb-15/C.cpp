#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 205
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, cnt, num, ans[MAXN], head[MAXN], match[MAXN], vis[MAXN], tag[MAXN][MAXN];

struct Edge {int next, to;} edge[MAXN*MAXN];
struct A {int l, r;} a[MAXN];

void addedge(int from, int to)
{
	edge[++cnt].next=head[from];
 	edge[cnt].to=to;
 	head[from]=cnt;
}

bool dfs(int x)
{
	for(rint i=head[x]; i; i=edge[i].next)
	{
		int to=edge[i].to;
		if(!vis[to])
		{
			vis[to]=1;
			if(!match[to] || dfs(match[to]))
			{
				match[to]=x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(rint i=1; i<=n; ++i) a[i].l=1, a[i].r=n;
	for(rint i=1; i<=m; ++i)
	{
		int op, x, y, v;
		scanf("%d%d%d%d", &op, &x, &y, &v);
		a[v].l=max(a[v].l, x);
		a[v].r=min(a[v].r, y);
		if(op==1)
			for(rint j=v+1; j<=n; ++j)
				for(rint k=x; k<=y; ++k) tag[j][k]=1;
		else
			for(rint j=1; j<v; ++j)
				for(rint k=x; k<=y; ++k) tag[j][k]=1;
		
	}
	for(rint i=1; i<=n; ++i)
	{
		if(a[i].l>a[i].r) {printf("-1\n"); return 0;}
		for(rint j=a[i].l; j<=a[i].r; ++j)
			if(!tag[i][j]) addedge(i, j);
	}
	for(rint i=1; i<=n; ++i)
	{
		memset(vis, 0, sizeof(vis));
		if(dfs(i)) num++;
	}
	if(num<n) {printf("-1\n"); return 0;}
	for(rint i=1; i<=n; ++i) printf("%d ", match[i]);
 	return 0;
}
