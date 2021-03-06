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
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, m=1, flag=1, f[MAXN], siz[30][MAXN];
vector<int> vec[30], g[30][MAXN];

void dfs2(int x, int fa, int step1, int step2) {
    for(int i=0; i<g[step1][x].size(); ++i) {
        int to=g[step1][x][i];
        if(to==fa) continue;
        g[step2][x].PB(to);
        g[step2][to].PB(x);
        dfs2(to, x, step1, step2);
    }
}

bool dfs1(int x, int fa, int step) {
    siz[step][x]=1;
    //printf("??%d %d %d\n", x, fa, step);
    if(step==0 || step==1) return true;
    for(int i=0; i<g[step][x].size(); ++i) {
        int to=g[step][x][i];
        if(to==fa) continue;
        if(dfs1(to, x, step)) return true;
        siz[step][x]+=siz[step][to];
    }
    if(siz[step][x]==f[step-2]) {
        dfs2(x, fa, step, step-2);
        dfs2(fa, x, step, step-1);
        vec[step-2].PB(x);
        vec[step-1].PB(fa);
        return true;
    }
    if(siz[step][x]==f[step-1]) {
        dfs2(x, fa, step, step-1);
        dfs2(fa, x, step, step-2);
        vec[step-1].PB(x);
        vec[step-2].PB(fa);
        return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    f[0]=f[1]=1;
    for(int i=2; f[i-1]+f[i-2]<=n; ++i) {
        f[i]=f[i-1]+f[i-2];
        m=i;
    }
    //printf("%d\n", m);
    if(f[m]!=n) {
        printf("NO\n");
        return 0;
    }
    for(int i=1; i<n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[m][x].PB(y);
        g[m][y].PB(x);
    }
    vec[m].PB(1);
    for(int i=m; i>=0; --i)
        for(int j=0; j<vec[i].size(); ++j)
            if(!dfs1(vec[i][j], 0, i)) flag=0;
    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}
/*
8
1 2
1 3
3 4
4 5
1 6
6 7
7 8
*/