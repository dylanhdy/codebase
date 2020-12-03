#include <bits/stdc++.h>
#define MAXN 2005
using namespace std;

int n, m, ans, f[MAXN][MAXN];
char s[MAXN], t[MAXN];

int main()
{
	while(scanf("%s%s", s+1, t+1)!=EOF)
	{
		n=strlen(s+1), m=strlen(t+1), ans=0;
		for(int i=1; i<=n+1; ++i)
			for(int j=1; j<=m+1; ++j)
			{
				f[i][j]=max(f[i-1][j], f[i][j-1]);
				if(i>1 && j>1 && s[i-1]==t[j-1]) f[i][j]=max(f[i][j], f[i-1][j-1]+1);
				ans=max(ans, f[i][j]*2+m-j+1);
				if(i<=n && j<=m && s[i]<t[j]) ans=max(ans, f[i][j]*2+n+m-i-j+2);
			}
		for(int i=1; i<=n+1; ++i)
			for(int j=1; j<=m+1; ++j) f[i][j]=0;
		printf("%d\n", ans);
	}
	return 0;
}