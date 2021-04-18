#include <bits/stdc++.h>
#define eps 1e-6
#define MAXN 105
#define LL long long
using namespace std;

int n;
LL x[MAXN], y[MAXN];
double a, area;

struct Node {double len1, len2, sin;} node[MAXN]; 

double dis(int a, int b) {
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])); 
}

bool check(double mid) {
	double sum=0;
	for(int i=1; i<=n; ++i)
		sum+=node[i].len1/mid*node[i].len2/mid*node[i].sin/2;
	//printf("%lf %lf\n", mid, sum);
	return sum>=area;	
}

int main() {
	scanf("%lf%d", &a, &n);
	for(int i=1; i<=n; ++i) scanf("%lld%lld", &x[i], &y[i]);
	for(int i=1; i<=n; ++i) {
		node[i].len1=dis(i, i==n?1:i+1);
		node[i].len2=dis(i, i==1?n:i-1);
		LL dx1=x[i==n?1:i+1]-x[i], dx2=x[i==1?n:i-1]-x[i];
		LL dy1=y[i==n?1:i+1]-y[i], dy2=y[i==1?n:i-1]-y[i];
		node[i].sin=fabs(dx1*dy2-dx2*dy1)/node[i].len1/node[i].len2;		 
	}
	for(int i=2; i<n; ++i) {
		LL dx1=x[i]-x[1], dx2=x[i+1]-x[1];
		LL dy1=y[i]-y[1], dy2=y[i+1]-y[1];
		area+=fabs(dx1*dy2-dx2*dy1)/2.0;
	}
	area*=(1-a);
	double l=2, r=1e3;
	while((r-l)>eps) {
		double mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%lf\n", l);
}