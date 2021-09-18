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
#define MAXN 2500
#define MAXM
#define P 2333
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define sz(x) (int)x.size()
#define dbg(a...) fprintf(stderr, a)
using namespace std;

using vi=vector<int>;

int T, f[20], comb[MAXN][MAXN], sum[MAXN][MAXN];
LL n, k;
vi a, b;

void init(int lim)
{
    comb[0][0]=1;
    for(int i=1; i<=lim; ++i) {
        comb[i][0]=1;
        for(int j=1; j<=i; ++j) comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%P;
    }
    for(int i=0; i<=lim; ++i) {
        sum[i][0]=1;
        for(int j=1; j<=lim; ++j) sum[i][j]=(sum[i][j-1]+comb[i][j])%P;
    }
}

int dfs(int x, int tag)
{
    if(x==-1) return 1;
    if(tag) return (sum[b[x]][a[x]-1]*dfs(x-1, 0)+comb[b[x]][a[x]]*dfs(x-1, 1))%P;
    if(f[x]==-1) f[x]=sum[b[x]][P-1]*dfs(x-1, 0)%P;
    return f[x];
}

int main()
{
    scanf("%d", &T);
    init(P-1);
    while(T--) {
        a.clear(), b.clear();
        scanf("%lld%lld", &n, &k);
        k=min(k, n);
        while(n) b.PB(n%P), n/=P;
        while(k) a.PB(k%P), k/=P;
        while(sz(a)<sz(b)) a.PB(0);
        for(int i=0; i<sz(a); ++i) f[i]=-1;
        printf("%d\n", dfs(sz(a)-1, 1));
    }
    return 0;
}
/*
1
1000000000000000000 1000000
*/