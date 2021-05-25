#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 10000005
#define MAXM
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, k, cnt, ans, pri[MAXN], vis[MAXN];

inline void add(int &x, int y) {x=(x+y<P?x+y:x+y-P);}

void init()
{
    for(int i=2; i<=m; ++i) {
        if(!vis[i]) pri[++cnt]=i;
        for(int j=1; j<=cnt && pri[j]*i<=m; ++j) {
            vis[pri[j]*i]=1;
            if(i%pri[j]==0) break;
        }
    }
}

int qpow(int x, int y, int p)
{
    int num=1;
    while(y) {
        if(y&1) num=1LL*num*x%p;
        x=1LL*x*x%p, y>>=1;
    }
    return num;
}

int exgcd(int a, int b, int &x, int &y)
{
    if(!b) {
        x=1, y=0;
        return a;
    }
    int d=exgcd(b, a%b, x, y), tx=x, ty=y;
    x=ty, y=(tx-a/b*ty);
    return d;
}

int getg(int x)
{
    vector<int> vec;
    int num=x-1;
    for(int i=1; pri[i]*pri[i]<=num; ++i)
        if(num%pri[i]==0) {
            vec.PB(pri[i]);
            while(!(num%pri[i])) num/=pri[i];
        }
    if(num>1) vec.PB(num);
    for(int i=2; i<x; ++i) {
        if(__gcd(x, i)!=1) continue;
        int flag=1;
        for(auto e: vec)
            if(qpow(i, (x-1)/e, x)==1) {
                flag=0;
                break;
            }
        if(flag) return i;
    }
    return 1;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    init();
    for(int i=1; i<=cnt; ++i) {
        int p=pri[i], g=getg(p), x, y; //a*k==(p-1)/2 mod p-1
        int d=exgcd(k, p-1, x, y);
        if((p-1)/2%d) continue;
        int b=(p-1)/d, a=(1LL*b/2*x%b+b)%b;
        //printf("%d %d %d %d\n", p, g, a, b);
        for(int j=a; j<(p-1); j+=b) {
            int num=n/p+(qpow(g, j, p)<=n%p);
            //printf("%d %d!!\n", j, num);
            add(ans, 1LL*p*num%P);
        }
    }
    // for(int j=1; j<=n; ++j)
    // for(int i=1; i<=cnt; ++i)
    //     if(((LL)pow(j, k)+1)%pri[i]==0) printf("%d!\n", pri[i]);
    printf("%d\n", ans);
    return 0;
}