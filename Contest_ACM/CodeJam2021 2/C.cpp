#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, rt, a[MAXN], fac[MAXN], ifac[MAXN], siz[MAXN], tag[MAXN];

vector<int> v[MAXN], g[MAXN];

void init()
{
    ifac[0]=ifac[1]=fac[0]=fac[1]=1;
    for(int i=2; i<=1e5; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=1e5; ++i) {
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
        fac[i]=1LL*fac[i-1]*i%P;
    }
}

int comb(int x, int y)
{
    return 1LL*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

int dfs(int x)
{
    int num=1;
    siz[x]=1;
    for(int i=0; i<g[x].size(); ++i) {
        int tmp=dfs(g[x][i]);
        siz[x]+=siz[g[x][i]];
        num=1LL*num*tmp%P*comb(siz[x]-1, siz[g[x][i]])%P;
    }
    return num;
}

int main()
{
    init();
    scanf("%d", &T);
    for(int Case=1; Case<=T; ++Case) {
        int maxn=0, flag=0;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            tag[i]=siz[i]=0;
            v[i].clear();
            g[i].clear();
        }
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            if(a[i]>maxn+1) flag=1;
            maxn=max(a[i], maxn);
            v[a[i]].PB(i);
        }
        if(flag) {
            printf("Case #%d: 0\n", Case);
            continue;
        }
        rt=v[1].back();
        for(int i=1; i<=n; ++i) {
            v[i].PB(n+1);
            for(int j=0, k=-1; j<v[i].size()-1; ++j) {
                if(j && !tag[v[i][j-1]]) g[v[i][j]].PB(v[i][j-1]);
                //printf("%d %d %d??\n", i, j, k);
                while(k+1<v[i+1].size() && v[i][j+1]>v[i+1][k+1]) k++;
                if(k!=-1 && v[i+1][k]>v[i][j]) {
                    g[v[i][j]].PB(v[i+1][k]);
                    tag[v[i+1][k]]=1;
                }
            }
        }
        //for(int i=1; i<=n; ++i)
        //    for(int j=0; j<g[i].size(); ++j) printf("%d %d\n", i, g[i][j]);
        printf("Case #%d: %d\n", Case, dfs(rt));
    }
    return 0;
}

/*
3
40
1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2 1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2
40
1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2 1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2
40
1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2 1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2
*/