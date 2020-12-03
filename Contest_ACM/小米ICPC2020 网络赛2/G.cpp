#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define LD long double
#define SEED 19260817
#define MAXN 100005
#define MAXM
#define INF 0x3f3f3f3f
using namespace std;
 
int n, ans, a[MAXN*2];

map<ULL, int> mp;
 
int main()
{
    while(scanf("%d", &n)!=EOF)
    {
    	ans=0;
    	mp.clear();
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
		ULL val=0, val2=1;
		for(int i=1; i<n; ++i) val2=val2*SEED;
		for(int i=1; i<=n; ++i) val=val*SEED+a[i];
		for(int i=1; i<=n; ++i)
		{
			if(!mp[val])
			{
				ans++;
				mp[val]=1;
			}
			val=(val-a[i]*val2)*SEED+a[i];
		}
		val=0;
		reverse(a+1, a+n+1);
        for(int i=1; i<=n; ++i) val=val*SEED+a[i];
		for(int i=1; i<=n; ++i)
		{
			if(!mp[val])
			{
				ans++;
				mp[val]=1;
			}
			val=(val-a[i]*val2)*SEED+a[i];
		}
		printf("%d\n", ans);
    }
    return 0;
}