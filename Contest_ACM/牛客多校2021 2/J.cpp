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
#define MAXM 10000005
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int cnt, pri[MAXM], vis[MAXM];
int T, n, m, k, a[MAXN], num[MAXN];
LL P, phi, comb[MAXN][33];
__int128 ans;

void init(int lim)
{
    for(int i=2; i<=lim; ++i) {
        if(!vis[i]) pri[++cnt]=i;
        for(int j=1; j<=cnt && pri[j]*i<=lim; ++j) {
            vis[i*pri[j]]=1;
            if(i%pri[j]==0) break;
        }
    }
}

LL Phi(LL n)
{
    LL num=n;
    for(int i=1; i<=cnt; ++i)
        if(n%pri[i]==0) {
            num=num/pri[i]*(pri[i]-1);
            while(n%pri[i]==0) n/=pri[i];
        }
    if(n>1) num=num/n*(n-1);
    return num;
}

LL ksm(__int128 x, LL y)
{
    __int128 num=1;
    while(y) {
        if(y&1) num=num*x%P;
        x=x*x%P, y>>=1;
    }
    return num;
}

int main()
{
    init(1e7);
    scanf("%d", &T);
    while(T--) {
        ans=1; m=0;
        memset(num, 0, sizeof(num));
        scanf("%d%d%lld", &n, &k, &P);
        phi=Phi(P);
        comb[0][0]=1;
        for(int i=1; i<=n; ++i) {
            comb[i][0]=1;
            for(int j=1; j<=k; ++j) {
                comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
                if(comb[i][j]>=phi) comb[i][j]-=phi;
            }
        }
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            m=max(a[i], m);
            num[a[i]]++;
        }
        for(int i=1; pri[i]<=m; ++i)
            for(LL j=pri[i]; j<=m; j*=pri[i]) {
                int tmp=0;
                for(int k=j; k<=m; k+=j) tmp+=num[k];
                ans=ans*ksm(pri[i], comb[tmp][k])%P;
            }
        printf("%lld\n", (LL)ans);
    }
    return 0;
}