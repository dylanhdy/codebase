#include <bits/stdc++.h>
using namespace std;

int n;
long double ans, l[25], w[25], f[1200000];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%Lf", &l[i]);
	for(int i=0; i<n; ++i) scanf("%Lf", &w[i]);
	for(int sta=1; sta<(1<<n); ++sta)
	{
		int sum=0;
		for(int i=0; i<n; ++i)
			if((sta>>i)&1) sum+=w[i];
		for(int i=0; i<n; ++i)
			if((sta>>i)&1)
			{
				long double len=f[sta^(1<<i)];
				int wei=sum-w[i];
				long double ans1=l[i]*wei/2/sum+l[i]/2;
				long double ans2=-l[i]*wei/2/sum+len+l[i]/2;
				f[sta]=max(f[sta], max(ans1, ans2));
				ans=max(ans, f[sta]);
			}
	}
	printf("%.10Lf", ans);
}