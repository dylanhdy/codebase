#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 200005
#define P 998244353
using namespace std;

int t, m, p, q;

int ksm(int x, int y)
{
    int num=1;
    while(y)
    {
        if(y&1) num=1LL*num*x%P;
        y>>=1, x=1LL*x*x%P;
    }
    return num;
}

int gcd(int x, int y)
{
    return y?gcd(y, x%y):x;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &m, &p, &q);
        int a=gcd(100, p);
        int inv1=ksm(p, P-2), inv2=ksm(100/a, P-2);
        int num=1LL*q*inv1%P*(m+P-1LL*(p/a)*inv2%P)%P;
        printf("%d\n", (m-num+P)%P);
    }
    return 0;
}