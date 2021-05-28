#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define eps 1e-5
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int T, n, m, p;

double f(LL x) {
	return (n*x+m)/(1-pow(1-1.0*p/10000, x));
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &m, &p);
		LL l=1, r=1e9;
		while(l<r) {
			LL mid1=l+(r-l)/3;
			LL mid2=r-(r-l)/3;
			if(f(mid1)>f(mid2)) l=mid1+1;
			else r=mid2-1;
		}
		printf("%lf\n", f(l));
	}
	return 0;
}