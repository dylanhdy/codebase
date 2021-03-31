#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, k, ans, l, r, mid, deg[MAXN], vis[MAXN], f[MAXN];

vector<int> g[MAXN];
queue<int> q;

int dfs(int x, int fa)
{
    if(x!=1 && g[x].size()==1) {
        f[x]=max(1, mid);
        return mid==0;
    } 
    int val1=0, val2=INF, num=0;
    for(int i=0; i<g[x].size(); ++i) {
        int to=g[x][i];
        if(to==fa) continue;
        num+=dfs(to, x);
        val1=max(val1, f[to]-1);
        val2=min(val2, f[to]-1);
    }
    if(val2==0) num++, f[x]=mid*2+1;
    else if(val2+val1>2*mid) f[x]=val1;
    else f[x]=val2;
    return num;
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i=1; i<n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].PB(y);
        g[y].PB(x);
    }
    l=0, r=n;
    while(l<=r) {
        mid=(l+r)/2;
        if(dfs(1, 0)+(f[1]<=mid)<=k) ans=mid, r=mid-1;
        else l=mid+1;
    }
    printf("%d\n", ans);
    return 0;
}