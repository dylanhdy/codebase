#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM 10000005
#define P
#define INF 0x3f3f3f3f
using namespace std;
 
int n, ans, a[MAXN], vis[MAXM], num[MAXM], f[MAXM];
 
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        num[a[i]]++;
    }
    for(int i=2; i<=10000000; ++i)
    {
        if(!num[i]) continue;
        f[i]+=num[i];
        ans=max(ans, f[i]);
        for(int j=i; j<=10000000; j+=i) f[j]=max(f[j], f[i]);
    }
    printf("%d\n", ans+num[1]);
    return 0;
}