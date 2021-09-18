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
#define MAXN 2100000
#define MAXM
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
#define sz(x) (int)x.size()
using namespace std;

using vi=vector<int>;
constexpr int P=998244353;

inline int add(int x, int y) {return x+y<P?x+y:x+y-P;}
inline int sub(int x, int y) {return x>=y?x-y:x-y+P;}
inline int qpow(int x, int y=P-2)
{
    int num=1;
    for(; y; y>>=1, x=1LL*x*x%P)
        if(y&1) num=1LL*num*x%P;
    return num;
}

void fwt(vi &a, bool op)
{
    for(int n=sz(a), step=1; step<n; step*=2)
        for(int i=0; i<n; i+=2*step) for(int j=i; j<i+step; ++j) {
            int &u=a[j], &v=a[j+step];
            tie(u, v)=op?MP(v, sub(u, v)):MP(add(u, v), u);
        }
}

int n, m, p, vis[22], w[22], v[MAXN], iv[MAXN];
vi vec[22], f[22], g[22];

int dfs(int x, int sta)
{
    int cnt=1, deg=0;
    vis[x]=1;
    for(int to: vec[x])
        if((sta>>to)&1) {
            deg++;
            if(vis[to]) continue;
            int tmp=dfs(to, sta);
            if(tmp==-1) return -1;
            else cnt+=tmp;
        }
    return deg%2==0?cnt:-1;
}

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for(int i=1; i<=m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        vec[x-1].PB(y-1);
        vec[y-1].PB(x-1);
    }
    for(int i=0; i<n; ++i) scanf("%d", &w[i]);
    for(int i=0; i<=n; ++i) f[i].resize(1<<n), g[i].resize(1<<n);
    for(int sta=1; sta<1<<n; ++sta) {
        memset(vis, 0, sizeof(vis));
        int cnt=0;
        for(int i=0; i<n; ++i)
            if((sta>>i)&1) cnt++, v[sta]+=w[i];
        if(!p) v[sta]=1;
        else if(p==2) v[sta]=1LL*v[sta]*v[sta]%P;
        if(dfs(__builtin_ctz(sta), sta)==cnt) g[cnt][sta]=0;
        else g[cnt][sta]=v[sta];
        iv[sta]=qpow(v[sta]);
    }
    for(int i=0; i<=n; ++i) fwt(g[i], 0);
    for(int i=0; i<=n; ++i) {
        if(i==0) {
            f[0][0]=1;
            fwt(f[0], 0);
            for(int sta=0; sta<1<<n; ++sta) f[2][sta]=1LL*f[0][sta]*g[2][sta]%P;
            fwt(f[2], 1);
        } else {
            fwt(f[i], 1);
            for(int sta=0; sta<1<<n; ++sta) {
                //printf("%d %d %d\n", i, sta, f[i][sta]);
                if(__builtin_popcount(sta)==i) f[i][sta]=1LL*f[i][sta]*iv[sta]%P;
                else f[i][sta]=0;
            }
            fwt(f[i], 0);
        }
        for(int j=0; j<=n-i; ++j)
            for(int sta=0; sta<1<<n; ++sta)
                f[i+j][sta]=(f[i+j][sta]+1LL*f[i][sta]*g[j][sta])%P;

    }
    fwt(f[n], 1);
    printf("%d\n", f[n][(1<<n)-1]);
    return 0;
}