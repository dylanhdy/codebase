#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
using namespace std;

int t;
LL m, d, w;

LL gcd(LL x, LL y)
{
    return y==0?x:gcd(y, x%y);
}

int main()
{
    scanf("%d", &t);
    for(rint i=1; i<=t; ++i)
    {
        scanf("%lld%lld%lld", &m, &d, &w);
        LL lim=min(m, d), step=w/gcd(d-1, w);
        LL temp=lim/step, res=lim-step*temp;
        printf("%lld\n", (temp-1)*temp/2*step+res*temp);
    }
    return 0;
}