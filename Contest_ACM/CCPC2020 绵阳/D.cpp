#include <bits/stdc++.h>
#define MAXN 100005
#define LL long long
using namespace std;
 
int n, t, ans, a[MAXN];
 
bool check(int lim)
{
	int res=lim;
	for(int i=1; i<=n; ++i)
	{
		if(a[i]<lim)
		{
			res-=(lim-a[i]);
			if(res<0) return 0;
		}
		if(a[i]>=lim) return 1;
	}
	return 1;
}
 
int main()
{
	scanf("%d", &t);
	for(int qwq=1; qwq<=t; ++qwq)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
		sort(a+1, a+n+1);
		LL l=0, r=2e9, ans=0;
		while(l<=r)
		{
			LL mid=(l+r)>>1;
			if(check(mid)) ans=mid, l=mid+1;
			else r=mid-1;
		}
		printf("Case #%d: %lld\n", qwq, ans+1);
	}
	return 0;
}