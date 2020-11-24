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
 
int t, n, fa[MAXN], vis[MAXN];
LL ans;
 
struct Node {int dep, id;} a[MAXN];
 
bool CMP(Node x, Node y)
{
    return x.dep>y.dep;
}
 
int main()
{
    scanf("%d", &t);
    for(int qwq=1; qwq<=t; ++qwq)
    {
        scanf("%d", &n);
        vis[1]=1, ans=0;
        a[1].dep=0, a[1].id=1;
        for(int i=2; i<=n; ++i)
        {
            vis[i]=0;
            scanf("%d", &fa[i]);
            a[i].dep=a[fa[i]].dep+1;
            a[i].id=i;
        }
        sort(a+1, a+n+1, CMP);
        for(int i=1; i<=n; ++i)
        {
            int x=a[i].id, val=0;
            while(!vis[x])
            {
                vis[x]=1;
                x=fa[x], val++;
            }
            ans+=min(val*2, a[i].dep);
        }
        printf("Case #%d: %lld\n", qwq, ans);
    }
    return 0;
}
