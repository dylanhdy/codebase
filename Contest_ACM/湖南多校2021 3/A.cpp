#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
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

int n, vis[10], f[MAXN][2];
LL s[MAXN], e[MAXN];

int mex(int v1, int v2) {
    vis[0]=vis[1]=vis[2]=0;
    vis[v1]=1;
    vis[v2]=1;
    for(int i=0; i<=2; ++i)
        if(!vis[i]) return i;
}

int solve(LL s, LL e, int sg1, int sg2)
{
    LL temp=e/2;
    if(s<=e && s>temp) {
        if(s&1) return sg1;
        else return sg2;
    }
    if(temp&1) {
        int val=mex(sg2, sg2);
        return solve(s, temp, val, mex(sg2, val));
    } else {
        int val=mex(sg1, sg2);
        return solve(s, temp, mex(sg2, val), val);
    }
}

void dfs(int x)
{
    int sg1=(solve(s[x], e[x], !(e[x]&1), e[x]&1)>0);
    int sg2=(solve(s[x], e[x], 1, 1)>0);
    //printf("%lld %lld %d %d\n", s[x], e[x], sg1, sg2);
    int val1, val2;
    if(x>1) dfs(x-1);
    f[x][0]=(sg1&f[x-1][1])|((!sg1)&f[x-1][0]);
    f[x][1]=(sg2&f[x-1][1])|((!sg2)&f[x-1][0]);
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%lld%lld", &s[i], &e[i]);
    f[0][0]=0;
    f[0][1]=1;
    dfs(n);
    printf("%d %d\n", f[n][0], f[n][1]);
    return 0;
}