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
#define MAXN 200005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, ans[MAXN], val[MAXN];
int cnt, pri[MAXN], vis[MAXN], mu[MAXN];

vector<int> g[MAXN];

void init(int lim)
{
    mu[1]=1;
    for(int i=2; i<=lim; ++i) {
        if(!vis[i]) pri[++cnt]=i, mu[i]=-1;
        for(int j=1; j<=cnt && pri[j]*i<=lim; ++j) {
            vis[pri[j]*i]=1;
            if(i%pri[j]==0) {
                mu[i*pri[j]]=0;
                break;
            }
            mu[pri[j]*i]=-mu[i];
        }
    }
}

int ksm(int x, int y)
{
    int num=1;
    while(y) {
        if(y&1) num=1LL*num*x%P;
        x=1LL*x*x%P, y>>=1;
    }
    return num;
}

bool dfs(int x, int fa, int k)
{
    val[x]=0;
    int flag=1, num=0;
    for(int to: g[x])
        if(to!=fa) {
            if(!dfs(to, x, k)) flag=0;
            if(!val[to]) num++;
        }
    if(num%k==0) val[x]=0;
    else if((num+1)%k==0) val[x]=1;
    else flag=0;
    return flag;
}

int main()
{
    scanf("%d", &T);
    init(1e5);
    while(T--) {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            ans[i]=0;
            g[i].clear();
        }
        for(int i=1; i<n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x].PB(y), g[y].PB(x);
        }
        
        for(int i=1; i*i<=(n-1); ++i)
            if((n-1)%i==0) {
                ans[i]=dfs(1, 0, i);
                if(i*i!=n-1) ans[(n-1)/i]=dfs(1, 0, (n-1)/i);
            }
        ans[1]=ksm(2, n-1);
        for(int i=1; i<=n; ++i) {
            for(int j=2; j*i<=n; ++j)
                ans[i]=(ans[i]+mu[j]*ans[i*j]+P)%P;
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
/*
1
5
1 2
2 3
2 4
2 5
*/