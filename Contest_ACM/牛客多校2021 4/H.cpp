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
#define MAXN 1000005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, c, ans[MAXN], pw[MAXN], a[MAXN];

vector<int> sum[MAXN];

int gcd(int x, int y)
{
    return y?gcd(y, x%y):x;
}

int fpow(int x, int y)
{
    int num=1;
    while(y) {
        if(y&1) num=1LL*num*x%P;
        x=1LL*x*x%P, y>>=1;
    }
    return num;
}

void init()
{
    for(int i=1; i<=n; ++i) pw[i]=fpow(i, c);
    for(int i=1; i<=n; ++i) {
        sum[i].PB(0);
        for(int j=1; j*i<=n; ++j) {
            int tmp=(sum[i][j-1]+1LL*a[j*i]*pw[j])%P;
            sum[i].PB(tmp);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &c);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    init();
    for(int x=1; x<=n; ++x)
        for(int y=1; x*y<=n; ++y)
            if(gcd(x, y)==1) {
                int lim=min(n/x, n/y);
                ans[x*y]=(ans[x*y]+1LL*sum[x][lim]*pw[y])%P;
            }
    for(int i=1; i<=n; ++i) ans[i]^=ans[i-1];
    printf("%d\n", ans[n]);
    return 0;
}