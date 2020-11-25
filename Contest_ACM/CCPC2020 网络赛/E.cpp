#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#define LL long long
#define LD long double
#define MAXN 40005
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, t, cnt, pri[MAXN], vis[MAXN];

void sieve(int lim)
{
    for(int i=2; i<=lim; ++i)
    {
        if(!vis[i]) pri[++cnt]=i;
        for(int j=1; j<=cnt && pri[j]*i<=lim; ++j)
        {
            vis[i*pri[j]]=1;
            if(i%pri[j]==0) break;
        }
    }
}

int work(int x)
{
    int val=0;
    if(x%2==0) val++;
    while(x%2==0) x/=2;
    for(int i=2; i<=cnt && pri[i]*pri[i]<=x; ++i)
        while(x%pri[i]==0) x/=pri[i], val++;
    if(x>1) val++;
    return val;
}

int main()
{
    sieve(40000);
    scanf("%d", &t);
    while(t--)
    {
        int ans=0;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i)
        {
            int temp;
            scanf("%d", &temp);
            ans^=work(temp);
        }
        if(ans) printf("W\n");
        else printf("L\n");
    }
    return 0;
}