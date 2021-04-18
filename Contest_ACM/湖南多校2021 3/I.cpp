#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 205
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, id, f[MAXN], deg[MAXN], dep[MAXN], vis[MAXN], dis[MAXN];
LL ans, maxn, cir=1;

queue<int> q;

LL gcd(LL x, LL y)
{
    if(!y) return x;
    return gcd(y, x%y);
}

void dfs(int x, int deep)
{
    vis[x]=1;
    if(vis[f[x]])
        cir=cir/gcd(cir, deep)*deep;
    else dfs(f[x], deep+1);
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &f[i]);
        deg[f[i]]++;
    }
    for(int i=1; i<=n; ++i)
        if(!deg[i]) {
            dep[i]=1;
            q.push(i);
        }
    while(!q.empty()) {
        int x=q.front(); q.pop();
        maxn=max(maxn, (LL)dep[x]);
        vis[x]=1;
        deg[f[x]]--;
        dep[f[x]]=max(dep[f[x]], dep[x]+1);
        if(!deg[f[x]]) q.push(f[x]);
    }
    for(int i=1; i<=n; ++i)
        if(!vis[i]) dfs(i, 1);
    //printf("%lld %lld\n", cir, maxn);
    if(!maxn) ans=cir;
    else ans=(maxn+cir-1)/cir*cir;
    printf("%lld\n", ans);
    return 0;
}