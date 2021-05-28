#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, col, id[105];
LL ans[105];

vector<int> g[105], v[2];

void dfs(int x, int fa, int col)
{
    v[col].PB(x);
    for(int i=0; i<g[x].size(); ++i) {
        int to=g[x][i];
        if(to!=fa) dfs(to, x, col^1);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].PB(y), g[y].PB(x);
    }
    dfs(1, 0, 0);
    if(v[0].size()>v[1].size()) col=1;
    else col=0;
    for(int i=0; i<v[col].size(); ++i) {
        id[v[col][i]]=i;
        ans[v[col][i]]=(1LL<<59)-1-(1LL<<i);
    }
    for(int i=0; i<v[col^1].size(); ++i) {
        int x=v[col^1][i];
        ans[x]=(1LL<<59);
        for(int j=0; j<g[x].size(); ++j) ans[x]|=(1LL<<id[g[x][j]]);
    }
    for(int i=1; i<=n; ++i) printf("%lld ", ans[i]);
    return 0;
}