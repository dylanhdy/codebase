#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define eps 1e-7
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T;
double n, p1, v1, p2, v2;

bool check(double tim)
{
    if(tim*v1>=n-p1 && tim*v2>=p2) return true;
    double len1, len2;
    if(tim*v1<=p1) len1=0;
    else len1=max((p1+v1*tim)/2, v1*tim-p1);
    if(tim*v2<=n-p2) len2=0;
    else len2=max((n-p2+v2*tim)/2, v2*tim-(n-p2));
    return len1+len2>=n;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%lf%lf%lf%lf%lf", &n, &p1, &v1, &p2, &v2);
        if(p1>p2) swap(p1, p2), swap(v1, v2);
        double l=0, r=2e7;
        while(fabs(r-l)>eps) {
            double mid=(l+r)/2;
            if(check(mid)) r=mid;
            else l=mid;
        }
        printf("%lf\n", (l+r)/2);
    }
    return 0;
}