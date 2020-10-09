#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAXN 50
#define rint register int
#define LL long long
#define INF 
using namespace std;

LL a, b, ans, s[MAXN];

void init()
{
	s[2]=1;
	for(rint i=3; i<=45; ++i)
	{
		for(rint j=2; j<=i; ++j)
			if(i%j) {s[i]=s[j]+1; break;}
	}
}

LL gcd(LL x, LL y)
{
	return y?gcd(y, x%y):x;
}

int main()
{
	init();
	scanf("%lld%lld", &a, &b);
	LL lcm=1;
	for(rint i=2; i<=45; ++i)
	{
		ans+=(s[i]+1)*(b/lcm-(a-1)/lcm);
		lcm=lcm*i/gcd(lcm, i);
		ans-=(s[i]+1)*(b/lcm-(a-1)/lcm);
		if(lcm>b) break;	
	}
	printf("%lld\n", ans);
	return 0;
}
