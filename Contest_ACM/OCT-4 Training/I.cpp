#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
#define LL long long
#define LD long double
#define ULL unsigned long long
#define MAXN 100005
#define MAXM
#define P 1000000007
#define INF 0x3f3f3f3f
#define seed 19260817
using namespace std;

int n, a0, num[55], fac[MAXN], ifac[MAXN];
unordered_map<ULL, int> mp;


int dfs(int lim, int cnt)
{
    if(lim>=50 || cnt==n) return fac[n-cnt];
    ULL qwq=0;
    for(int i=1; i<=50; ++i) qwq=qwq*seed+num[i];
    if(mp[qwq]) return mp[qwq];
    int temp=0; 
    for(int i=1; i<=lim; ++i)
        if(num[i]>0)
        {
            num[i]--;
            temp=(temp+1LL*dfs(lim+i, cnt+1)*(num[i]+1)%P)%P;
            num[i]++;
        }
    mp[qwq]=temp;
    return temp;
}


int main()
{
    scanf("%d%d", &n, &a0);
    for(int i=1; i<=n; ++i)
    {
        int temp;
        scanf("%d", &temp);
        num[temp]++;
    }
    fac[0]=fac[1]=ifac[0]=ifac[1]=1;
    for(int i=2; i<=n; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=n; ++i)
    {
        fac[i]=1LL*fac[i-1]*i%P;
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
    }
    printf("%lld\n", 1LL*dfs(a0, num[0])*fac[n]%P*ifac[n-num[0]]%P);
    return 0;
}