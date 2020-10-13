#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#define rint register int
#define LL long long
#define P 998244353
#define MAXN 10005
using namespace std;

int n, g, tot, pri[MAXN], vis[MAXN], a[MAXN], b[MAXN];

set<int> ans;
set<int>::iterator it;



bool check(int p)
{
	for(rint i=0; i<=p-1; ++i) b[i]=0;
	for(rint i=0; i<=n; ++i) b[i%(p-1)]=(b[i%(p-1)]+a[i])%p;
	for(rint i=0; i<=p-1; ++i)
		if(b[i]) return false;
	return true;
}

void init()
{
	for(rint i=2; i<=n; ++i)
	{
		if(!vis[i]) pri[++tot]=i;
		for(rint j=1; j<=tot && pri[j]*i<=n; ++j)
		{
			vis[pri[j]*i]=1;
			if(i%pri[j]==0) break;
		}
	}
}

int main()
{
	scanf("%d", &n);
	init();
	for(rint i=n; i>=0; --i)
	{
		scanf("%d", &a[i]);
		g=__gcd(abs(a[i]), g);
	}
	for(rint i=2; i*i<=g; ++i)
	{
		if(g%i) continue;
		ans.insert(i);
		while(g%i==0) g/=i;
	}
	if(g>1) ans.insert(g);
	for(rint i=1; i<=tot; ++i)
	{
		if(a[0]%pri[i]) continue;
		if(check(pri[i])) ans.insert(pri[i]);
	}
	for(it=ans.begin(); it!=ans.end(); ++it) printf("%d\n", *it);
}
