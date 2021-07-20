#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 20
#define MAXM 1000005
#define P
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
using namespace std;

int n, m, vis[MAXM], g[MAXN];
LL f[MAXM];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x-1]|=(1<<(y-1));
        g[y-1]|=(1<<(x-1));
    } 
    f[0]=1;
    for(int sta=1; sta<(1<<n); ++sta)
    {
        for(int i=0; i<n; ++i)
            if((sta>>i)&1) vis[sta]|=g[i];
        for(int sub=sta; sub; sub=(sub-1)&sta)
        {
            int temp=(vis[sub]&sta);
            if((sub|temp)==sta && (sub&temp)==0) f[sta]+=f[sta^sub];
        }
    }
    printf("%lld\n", f[(1<<n)-1]);
    return 0;
}