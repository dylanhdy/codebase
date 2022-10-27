#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#define ll long long
#define MAXN 200005
#define P 1000000007
using namespace std;

int LIM, INV2=500000004, INV6=166666668;
int cnt1, cnt2, vis[MAXN], pri[MAXN], g1[MAXN], g2[MAXN], h1[MAXN], h2[MAXN], id1[MAXN], id2[MAXN];
ll n, w[MAXN];

int add(int x, int y) {return x+y<P?x+y:x+y-P;}
int sub(int x, int y) {return x<y?x-y+P:x-y;}

void sieve(int lim)
{
    for(int i=2; i<=lim; ++i) {
        if(!vis[i]) {
            pri[++cnt1]=i;
            g1[cnt1]=(g1[cnt1-1]+i)%P;
            h1[cnt1]=(h1[cnt1-1]+1ll*i*i)%P;
        }
        for(int j=1; j<=cnt1 && pri[j]*i<=LIM; ++j) {
            vis[i*pri[j]]=1;
            if(i%pri[j]==0) break;
        }
    }
}

int cal(ll x, int y)
{
    if(pri[y]>=x) return 0;
    int id=(x<=LIM?id1[x]:id2[n/x]);
    int val=sub(sub(h2[id], g2[id]), sub(h1[y], g1[y]));
    for(int i=y+1; i<=cnt1; ++i) {
        ll tmp=pri[i];
        if(tmp*tmp>x) break;
        for(int k=1; tmp<=x; k++, tmp*=pri[i]) {
            ll tmp1=tmp%P; tmp1=tmp1*(tmp1-1)%P;
            val=(val+tmp1*(cal(x/tmp, i)+(k>1)))%P;
        }
    }
    return val;
}

int main()
{
    scanf("%lld", &n);
    LIM=sqrt(n);
    sieve(LIM);
    for(ll l=1, r; l<=n; l=r+1) {
        r=n/(n/l); w[++cnt2]=n/l;
        ll tmp=(n/l)%P;
        g2[cnt2]=sub(tmp*(tmp+1)%P*INV2%P, 1);
        h2[cnt2]=sub(tmp*(tmp+1)%P*(2*tmp+1)%P*INV6%P, 1);
        if(n/r<=LIM) id1[n/r]=cnt2;
        else id2[r]=cnt2;
    }
    for(int i=1; i<=cnt1; ++i) {
        ll tmp=pri[i];
        for(int j=1; j<=cnt2 && tmp*tmp<=w[j]; ++j) {
            ll id=w[j]/pri[i]; id=(id<=LIM?id1[id]:id2[n/id]);
            g2[j]=sub(g2[j], tmp*sub(g2[id], g1[i-1])%P);
            h2[j]=sub(h2[j], tmp*tmp%P*sub(h2[id], h1[i-1])%P);
        }
    }
    printf("%d\n", add(cal(n, 0), 1));
}