#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 20000005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int cnt, inv, n, num[10], vis[MAXN], pri[MAXN];
char s[10];

int ksm(int x, int y)
{
    int num=1;
    while(y)
    {
        if(y&1) num=1LL*num*x%P;
        x=1LL*x*x%P, y>>=1;
    }
    return num;
}

void init()
{
    for(int i=2; i<=2e7; ++i)
    {
        if(!vis[i]) pri[++cnt]=i;
        for(int j=1; j<=cnt && pri[j]*i<=2e7; ++j)
        {
            vis[i*pri[j]]=1;
            if(i%pri[j]==0) break;
        }
    }
}

bool check(LL x)
{
    for(int i=1; i<=cnt; ++i)
    {
        if(1LL*pri[i]*pri[i]>x) return 0;
        if(x%pri[i]==0) return 1;
    }
    return 0;
}

int dfs(LL x)
{
    if(check(x)) return 0;
    int temp;
    for(int i=1; i<=n; ++i)
        temp=(temp+1LL*(dfs(x*10+num[i])+1)*inv%P)%P;
    return temp;
}

int main()
{
    init();
    scanf("%s", s+1);
    for(int i=1; i<=9; ++i)
        if(s[i]=='1') num[++n]=i;
    inv=ksm(n, P-2);
    printf("%d\n", dfs(0));
    return 0;
}