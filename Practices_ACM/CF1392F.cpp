#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 1000005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n;
LL sum, a[MAXN];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        LL temp;
        scanf("%lld", &temp);
        sum+=temp;
    }
    sum-=1LL*n*(n-1)/2;
    a[1]=sum/n;
    for(int i=2; i<=n; ++i) a[i]=a[i-1]+1;
    for(int i=1; i<=sum%n; ++i) a[i]++;
    for(int i=1; i<=n; ++i) printf("%lld ", a[i]);
    return 0;
}