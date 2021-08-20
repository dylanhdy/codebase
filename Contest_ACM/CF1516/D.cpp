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

int cnt, pri[MAXN], vis[MAXN];
int n, q, top, a[MAXN], g[MAXN][20], f[MAXN], pos[MAXN];

void init(int lim)
{
    for(int i=2; i<=lim; ++i) {
        if(!vis[i]) pri[++cnt]=i; // phi[i]=i-1, mu[i]=1;
        for(int j=1; j<=cnt && pri[j]*i<=lim; ++j) {
            vis[i*pri[j]]=1;
            if(i%pri[j]==0) break;
        }
    }
}

int main()
{
    init(1e5);
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        for(int j=1; pri[j]*pri[j]<=a[i]; ++j)
            if(a[i]%pri[j]==0) {
                f[i]=max(f[i], pos[pri[j]]);
                pos[pri[j]]=i;
                while(a[i]%pri[j]==0) a[i]/=pri[j];
            }
        if(a[i]>1) {
            f[i]=max(f[i], pos[a[i]]);
            pos[a[i]]=i;
        }
    }
    for(int i=1; i<=n; ++i) g[i][0]=max(g[i-1][0], f[i]);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=18; ++j) g[i][j]=g[g[i][j-1]][j-1];
    while(q--) {
        int l, r, ans=0;
        scanf("%d%d", &l, &r);
        for(int i=18; i>=0; --i)
            if(g[r][i]>=l) {
                ans+=(1<<i);
                r=g[r][i];
            }
        printf("%d\n", ans+1);
    }
    return 0;
}