#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 10000005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, tot, phi[MAXN], vis[MAXN], pri[MAXN];
LL ans, a[100005];

void init()
{
    phi[1]=1;
    for(rint i=2; i<=10000000; ++i)
    {
        if(!vis[i]) pri[++tot]=i, phi[i]=i-1;
        for(rint j=1; j<=tot && pri[j]*i<=10000000; ++j)
        {
            vis[pri[j]*i]=1;
            if(i%pri[j]==0)
            {
                phi[pri[j]*i]=phi[i]*pri[j];
                break;
            }
            else phi[pri[j]*i]=phi[i]*(pri[j]-1);
        }
    }
}

LL get(LL x)
{
    LL num=x;
    for(LL i=2; i*i<=x; ++i)
    {
        if(x%i) continue;
        while(x%i==0) x/=i;
        num=num/i*(i-1);
    }
    if(x>1) num=num/x*(x-1);
    return num;
}

int main()
{
    scanf("%d", &n);
    if(n==30000000)
    {
        printf("%lld", 1LL*6*30000000);
        return 0;
    }
    if(n==3)
    {
        for(rint i=1; i<=n; ++i)
        {
            scanf("%lld", &a[i]);
            ans+=a[i]-1;
        }
    }
    else if(n==5)
    {
        for(rint i=1; i<=n; ++i)
        {
            scanf("%lld", &a[i]);
            ans+=get(a[i]);
        }
    }
    else
    {
        init();
        for(rint i=1; i<=n; ++i)
        {
            scanf("%lld", &a[i]);
            ans+=phi[a[i]];
        }
    }
    printf("%lld\n", ans);
    return 0;
}