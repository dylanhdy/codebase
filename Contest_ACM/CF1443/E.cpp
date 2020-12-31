#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, q, base, a[MAXN], vis[MAXN];
LL b[MAXN], num[MAXN], fac[20];

void dfs(int pos, LL res)
{
    while(vis[a[pos]]) a[pos]++; 
    if(pos==n) return;
    int up=(num[pos]+res)/fac[n-pos];
    num[pos]=(num[pos]+res)%fac[n-pos];
    for(int i=1; i<=up; ++i)
    {
        a[pos]++;
        while(vis[a[pos]]) a[pos]++;
    }
    vis[a[pos]]=1;
    if(up)
        for(int i=pos+1; i<=n; ++i)
        {
            a[i]=base;
            num[i]=0;
            res=num[pos];
        }
    dfs(pos+1, res);
}

int main()
{
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i)
    {
        a[i]=i;
        b[i]=b[i-1]+a[i];
    }
    fac[1]=1;
    for(int i=2; i<=15; ++i) fac[i]=fac[i-1]*i;
    base=max(1, n-15);
    while(q--)
    {
        int op, x, y;
        scanf("%d", &op);
        if(op==1)
        {
            scanf("%d%d", &x, &y);
            printf("%lld\n", b[y]-b[x-1]);
        }
        else
        {
            scanf("%d", &x);
            for(int i=base; i<=n; ++i) vis[i]=0;
            dfs(base, x);
            for(int i=base; i<=n; ++i) b[i]=b[i-1]+a[i];
            //for(int i=1; i<=n; ++i) printf("%d ", a[i]);
            //printf("\n");
        }
    }
}