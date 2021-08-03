#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, tot=1, ans, l[MAXN], r[MAXN], t[MAXN*50][2], f[MAXN*50], g[MAXN*50], w[MAXN];

vector<int> u[MAXN], v[MAXN];

void update(int x, int k, int op)
{
    int p1=1, p2=1;
    for(int i=29; i>=0; --i) {
        int ch=((x>>i)&1);
        if((k>>i)&1) {
            if(!t[p2][ch]) t[p2][ch]=++tot;
            if(op==0) f[t[p2][ch]]++;
            else g[t[p2][ch]]|=1;
            if(!t[p2][ch^1]) t[p2][ch^1]=++tot;
            p2=t[p2][ch^1];
        } else {
            if(!t[p2][ch]) t[p2][ch]=++tot;
            p2=t[p2][ch];
        }
        //if(!t[p1][ch]) t[p1][ch]=++tot;
        //p1=t[p1][ch];
    }
    if(op==0) f[p2]++;
    else g[p2]|=1;
}

void dfs(int x, int fa)
{
    for(int i=0; i<u[x].size(); ++i) {
        int to=u[x][i];
        if(to==fa) continue;
        w[to]=w[x]^v[x][i];
        dfs(to, x);
    }
}

void cal(int rt, int dep)
{
    if(t[rt][0]) {
        f[t[rt][0]]+=f[rt];
        if(!g[t[rt][0]]) cal(t[rt][0], dep-1);
    }
    if(t[rt][1]) {
        f[t[rt][1]]+=f[rt];
        if(!g[t[rt][1]]) cal(t[rt][1], dep-1);
    }
    if(f[rt]==n) {
        if(!t[rt][0] && !t[rt][1]) ans+=(1<<dep);
        else if(!t[rt][0]) ans+=(1<<(dep-1));
        else if(!t[rt][1]) ans+=(1<<(dep-1));
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d%d", &l[i], &r[i]);
    for(int i=1; i<n; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        u[x].PB(y), u[y].PB(x);
        v[x].PB(z), v[y].PB(z);
    }
    dfs(1, 0);
    for(int i=1; i<=n; ++i) {
        update(w[i], r[i], 0);
        if(l[i]>0) update(w[i], l[i]-1, 1);
        //for(int i=1; i<=tot; ++i) printf("%d %d??\n", i, g[i]);
        //printf("!!\n");
    }
    //for(int i=1; i<=tot; ++i) printf("%d %d %d??\n", i, t[i][0], t[i][1]);
    cal(1, 30);
    printf("%d\n", ans);
    return 0;
}