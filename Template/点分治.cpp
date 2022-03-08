#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define MAXN 10005
#define INF 0x3f3f3f3f
using namespace std;

int n, m, tot, rt, f[MAXN], siz[MAXN], k[MAXN], ans[MAXN], vis[MAXN];

vector<pair<int,int>> g[MAXN];
vector<int> vec;

void find(int x, int fa)
{
	siz[x]=1; f[x]=0;
	for(auto [to, d]: g[x]) {
		if(to==fa || vis[to]) continue;
		find(to, x);
		siz[x]+=siz[to];
		f[x]=max(f[x], siz[to]);
	}
	f[x]=max(f[x], tot-siz[x]);
	if(!rt || f[x]<f[rt]) rt=x;
}

void dfs(int x, int fa, int dis)
{
	vec.push_back(dis);
	for(auto [to, d]: g[x]) {
		if(to==fa || vis[to]) continue;
		dfs(to, x, dis+d);
	}
}

void divide(int x)
{
	vis[x]=1;
	set<int> st; st.insert(0);
	for(auto [to, d]: g[x]) {
		if(vis[to]) continue;
		vec.clear();
		dfs(to, x, d);
		for(int i=1; i<=m; ++i)
			for(int e: vec)
				if(st.count(k[i]-e)) ans[i]=1;
		for(int e: vec) st.insert(e);
	}
	for(auto [to, d]: g[x]) {
		if(vis[to]) continue;
		tot=siz[to], rt=0;
		find(to, 0);
		divide(rt);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<n; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		g[x].push_back({y, z});
		g[y].push_back({x, z});
	}
	for(int i=1; i<=m; ++i) scanf("%d", &k[i]);
	tot=n; rt=0;
	find(1, 0);
	divide(rt);
	for(int i=1; i<=m; ++i) {
		if(ans[i]) printf("AYE\n");
		else printf("NAY\n");
	}
}
