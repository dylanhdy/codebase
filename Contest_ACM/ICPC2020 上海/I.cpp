#include <bits/stdc++.h>
#define LD long double
using namespace std;

const LD PI=acos(-1.0);

int n, m;
LD ans1, ans2;

int main()
{
	scanf("%d%d", &n, &m);
	if(m==1)
	{
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j) ans1+=abs(i-j);
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j) ans1+=i+j;
		printf("%.10Lf\n", ans1);
		return 0;
	}
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			for(int k=0; k<2*m; ++k)
			{
				LD w=PI*min(k, 2*m-k)/m;
				if(w<=2)
				{
					if(i>=j) ans1+=(i-j)+j*w;
					else ans1+=(j-i)+i*w;
				}
				else ans1+=(i+j);
			}
	ans2=1LL*(n+1)*n*m;
	printf("%.10Lf\n", ans1*m+ans2);
}