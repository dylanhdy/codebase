#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
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

constexpr int LIM=500;

int n, m, q, val[MAXN], lim[MAXN], tag[MAXN], ans[MAXN];

vector<int> g[MAXN], h[MAXN];
vector<vector<int> > vec[MAXN];

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for(int i=1; i<=m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].PB(y), g[y].PB(x);
    }
    for(int i=1; i<=n; ++i)
        if(g[i].size()>LIM) {
            vec[i].resize(10005);
            for(int e: g[i]) h[e].PB(i);
        }
    for(int i=1; i<=q; ++i) {
        int u, w;
        scanf("%d%d", &u, &w);
        val[u]+=w;
        int flag=1;
        if(g[u].size()<=LIM) {
            for(int e: g[u]) {
                if(val[u]<=val[e]) flag=0;
                if(val[u]>=val[e] && tag[e]) {
                    ans[e]+=i-tag[e];
                    tag[e]=0;
                }
            }
            for(int e: h[u]) {
                vec[e][val[u]].PB(u);
                lim[e]=max(lim[e], val[u]);
            }
            if(flag && !tag[u]) tag[u]=i;
        } else {
            for(int e: h[u]) {
                if(val[u]<=val[e]) flag=0;
                if(val[u]>=val[e] && tag[e]) {
                    ans[e]+=i-tag[e];
                    tag[e]=0;
                }
            }
            for(int j=val[u]-w+1; j<=val[u]; ++j)
                for(int e: vec[u][j])
                    if(tag[e] && val[e]<=val[u]) {
                        ans[e]+=i-tag[e];
                        tag[e]=0;
                    }
            if(flag && val[u]>lim[u] && !tag[u]) tag[u]=i;
        }
    }
    for(int i=1; i<=n; ++i)
        if(tag[i]) ans[i]+=q-tag[i];
    for(int i=1; i<=n; ++i) printf("%d\n", ans[i]);
    return 0;
}