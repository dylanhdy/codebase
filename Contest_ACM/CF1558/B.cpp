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
#define MAXN 4000005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m;
LL pre[MAXN], f[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    f[n]=pre[n]=1;
    for(int i=n-1; i>=1; --i) {
        f[i]=pre[i+1];
        for(int j=2; j*i<=n; ++j) {
            f[i]=(f[i]+pre[i*j]-pre[min(n+1, (i+1)*j)])%m;
        }
        pre[i]=(pre[i+1]+f[i])%m;
    }
    printf("%lld\n", f[1]);
    return 0;
}