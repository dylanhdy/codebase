#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;
 
int T, cnt, pri[100005], vis[100005];
LL p, q, ans;
 
void init()
{
    for(int i=2; i<=1e5; ++i)
    {
        if(!vis[i]) pri[++cnt]=i;
        for(int j=1; j<=cnt && i*pri[j]<=1e5; ++j)
        {
            vis[i*pri[j]]=1;
            if(i%pri[j]==0) break;
        }
    }
}
 
LL solve(int x)
{
    LL temp=p;
    while(temp%x==0) temp/=x;
    return temp; 
}
 
int main()
{
    init();
    scanf("%d", &T);
    while(T--)
    {
        ans=0;
        scanf("%lld%lld", &p, &q);
        if(p%q)
        {
            printf("%lld\n", p);
            continue;
        }
        for(int i=1; 1LL*pri[i]*pri[i]<=q; ++i)
            if(q%pri[i]==0)
            {
                LL temp=1;
                while(q%pri[i]==0) q/=pri[i], temp*=pri[i];
                ans=max(ans, solve(pri[i])*(temp/pri[i]));
            }
        if(q>1) ans=max(ans, solve(q));
        printf("%lld\n", ans);
    }   
    return 0;
}