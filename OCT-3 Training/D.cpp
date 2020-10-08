#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 1005
#define Pi acos(-1)
using namespace std;
 
int t;
double ans, a, b, r, d;
 
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf", &a, &b, &r, &d);
        d=d/180*Pi;
        if(atan(b/(a+r))<d) ans=sqrt((a+r)*(a+r)+b*b)-r;
        else ans=(a+r)*cos(d)+b*sin(d)-r;
        printf("%.12lf\n", ans);
    }
    return 0;
}