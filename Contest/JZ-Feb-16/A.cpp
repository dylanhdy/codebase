#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

LL n, ans=1, cnt;
int num[10000];

void divide()
{
    for(LL i=2; i*i<=n; ++i)
    {
        if(n%i) continue;
        cnt++;
        while(n%i==0) n/=i, num[cnt]++;
    }
    if(n!=1) num[++cnt]=1;
}

int main()
{
    scanf("%lld", &n);
    divide();
    for(rint i=1; i<=cnt; ++i) ans=ans*(num[i]*2+1);
    printf("%lld\n", (ans+1)/2);
    return 0;
}
