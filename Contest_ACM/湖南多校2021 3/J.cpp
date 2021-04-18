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

LL n, m, a[MAXN], f[2], h[2][2], g[2][2], c[2][2];

void mul(LL a[2][2], LL b[2][2])
{
    memset(c, 0, sizeof(c));
    for(int i=0; i<=1; ++i)
        for(int j=0; j<=1; ++j)
            for(int k=0; k<=1; ++k)
                c[i][j]=(c[i][j]+a[i][k]*b[k][j]%P)%P;
    memcpy(a, c, sizeof(c));
}

void ksm(LL x)
{
    h[0][0]=1; h[0][1]=0;
    h[1][0]=0; h[1][1]=1;
    while(x) {
        if(x&1) mul(h, g);
        mul(g, g); x>>=1;
    }
}

void solve(LL x)
{
    g[0][0]=0; g[0][1]=1;
    g[1][0]=1; g[1][1]=1;
    ksm(x);
    LL t0=f[0], t1=f[1];
    f[0]=(t0*h[0][0]%P+t1*h[0][1]%P)%P;
    f[1]=(t0*h[1][0]%P+t1*h[1][1]%P)%P;
}

int main()
{
    scanf("%lld%lld", &n, &m);
    for(int i=1; i<=m; ++i) scanf("%lld", &a[i]);
    sort(a+1, a+m+1);
    m=unique(a+1, a+m+1)-a-1;
    if(n==a[m]) {
        printf("0\n");
        return 0;
    }
    f[0]=0; f[1]=1;
    for(int i=1; i<=m; ++i) {
        solve(a[i]-a[i-1]-1);
        swap(f[0], f[1]);
    }
    solve(n-a[m]-1);
    printf("%lld\n", f[1]);
    return 0;
}