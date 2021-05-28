#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

char ch[]={'U', 'R', 'D', 'L'};

int t, n, mx, my, flag, num[10], p[10];
char s[MAXN];

bool check() {
	int x=0, y=0;
	if(x==mx && y==my) return false;
	for(int i=0; i<4; ++i)
		for(int j=1; j<=num[p[i]]; ++j) {
			if(p[i]==0) y++;
			if(p[i]==1) x++;
			if(p[i]==2) y--;
			if(p[i]==3) x--;
			if(x==mx && y==my) return false;
		}
	return true;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		flag=num[0]=num[1]=num[2]=num[3]=0;
		scanf("%d%d%s", &mx, &my, s+1);
		n=strlen(s+1);
		for(int i=1; i<=n; ++i) {
			if(s[i]=='U') num[0]++;
			if(s[i]=='R') num[1]++;
			if(s[i]=='D') num[2]++;
			if(s[i]=='L') num[3]++;
		}
		for(int i=0; i<4; ++i) p[i]=i;
		do {
			int x=0, y=0;
			if(check()) {
				flag=1;
				for(int i=0; i<4; ++i)
					for(int j=1; j<=num[p[i]]; ++j)
						printf("%c", ch[p[i]]);
				printf("\n");
				break;
			}
		} while(next_permutation(p, p+4));
		if(!flag) printf("Impossible\n");
	}
	return 0;
}