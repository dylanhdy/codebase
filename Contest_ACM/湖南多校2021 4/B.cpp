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

int n, ans=1, pre, fac[MAXN], ifac[MAXN], f[MAXN];
map<int, int> mp;

int comb(int x, int y)
{
    return 1LL*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

void init()
{
    fac[0]=fac[1]=ifac[0]=ifac[1]=1;
    for(int i=2; i<=n; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=n; ++i) {
        ifac[i]=1LL*ifac[i]*ifac[i-1]%P;
        fac[i]=1LL*i*fac[i-1]%P;
    }
    f[1]=1;
    for(int i=2; i<=n; ++i) f[i]=1LL*f[i-1]*comb(i, 2)%P;
}

int main()
{
    scanf("%d", &n);
    init();
    for(int i=1, temp; i<=n; ++i) {
        scanf("%d", &temp);
        mp[temp]++;
    }
    for(auto e: mp) {
        int val=e.second;
        pre+=val;
        int temp=0;
        if(val==pre) temp=1;
        else 
            for(int i=1; i<=val; ++i)
                temp=(temp+1LL*i*comb(pre-i-1, val-i)%P)%P;
        ans=1LL*ans*temp%P*f[val]%P;
    }
    printf("%d\n", ans);
    return 0;
}