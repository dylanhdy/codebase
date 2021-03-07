#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 200005
using namespace std;

int n, c[20][20];
LL ans;
double a[MAXN];

int main()
{
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i) scanf("%lf", &a[i]);
    for(rint i=1; i<=n; ++i)
    {
        int num2=0, num5=0;
        LL temp=a[i]*1000000000.0+0.5;
        while(temp%2==0 && num2<18) num2++, temp/=2;
        while(temp%5==0 && num5<18) num5++, temp/=5;
        for(rint j=0; j<=18; ++j)
            for(rint k=0; k<=18; ++k)
                if(j+num2>=18 && k+num5>=18) ans+=c[j][k];
        c[num2][num5]++;
    }
    printf("%lld\n", ans);
    return 0;
}

int n, c[20][20];
LL ans;
double a[MAXN];

int main()
{
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i) scanf("%lf", &a[i]);
    for(rint i=1; i<=n; ++i)
    {
        int num2=0, num5=0;
        LL temp=a[i]*1000000000.0+0.5;
        while(temp%2==0 && num2<18) num2++, temp/=2;
        while(temp%5==0 && num5<18) num5++, temp/=5;
        for(rint j=0; j<=18; ++j)
            for(rint k=0; k<=18; ++k)
                if(j+num2>=18 && k+num5>=18) ans+=c[j][k];
        c[num2][num5]++;
    }
    printf("%lld\n", ans);
    return 0;
}