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
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, k, ans, inv, ifac[20], fac[20], f[MAXN][20], g[MAXN][20], temp[20];

vector<int> t1[MAXN], t2[MAXN];

int ksm(int x, int y)
{
    int num=1;
    while(y) {
        if(y&1) num=1LL*x*num%P;
        x=1LL*x*x%P; y>>=1;
    }
    return num;
}

void init()
{
    inv=ksm(n, P-3);
    ifac[0]=ifac[1]=fac[0]=fac[1]=1;
    for(int i=2; i<=k; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=k; ++i) {
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
        fac[i]=1LL*fac[i-1]*i%P;
    }
}

int comb(int x, int y)
{
    return 1LL*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

void dfs1(int x, int fa)
{
    f[x][0]=1;
    for(int i=0; i<t1[x].size(); ++i) {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
        int to=t1[x][i];
        if(to==fa) continue;
        dfs1(to, x);
        for(int j=0; j<=k; ++j)
            for(int a=0; a<=j; ++a)
                f[x][j]=(f[x][j]+1LL*ksm(t2[x][i], j-a)*comb(j, a)%P*f[to][a]%P)%P;
    }
}

void dfs2(int x, int fa)
{
    g[x][0]=(g[x][0]+1)%P;
    for(int i=0; i<t1[x].size(); ++i) {
        int to=t1[x][i];  
        if(to==fa) continue;
        memset(temp, 0, sizeof(temp));
        temp[0]=1;
        for(int j=0; j<=k; ++j)
            for(int a=0; a<=j; ++a)
                temp[j]=(temp[j]+1LL*ksm(t2[x][i], j-a)*comb(j, a)%P*f[to][a]%P)%P;
        for(int j=0; j<=k; ++j)
            for(int a=0; a<=j; ++a) {
                int val=((f[x][a]+g[x][a]-temp[a])%P+P)%P;
                g[to][j]=(g[to][j]+1LL*ksm(t2[x][i], j-a)*comb(j, a)%P*val%P)%P;
            }
        dfs2(to, x);
    }
    ans=(1LL*inv*(f[x][k]+g[x][k])%P+ans)%P;
}

int main()
{
    scanf("%d%d", &n, &k);
    init();
    for(int i=1; i<n; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        t1[x].PB(y); t2[x].PB(z);
        t1[y].PB(x); t2[y].PB(z);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    printf("%d\n", ans);
    return 0;
}