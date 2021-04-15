#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 1000005
#define MAXM
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, f[MAXN], g[MAXN], num[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i) {
        int temp;
        scanf("%d", &temp);
        num[temp]++;
    }
    g[0]=1;
    for(int i=1; i<=n+1; ++i) {
        num[i]+=num[i-1];
        if(num[i]==num[i-1]) {
            if(i-1>=num[i-1]) f[i]=g[i-1-num[i-1]];
            if(i>=num[i]) g[i-num[i]]=(g[i-num[i]]+f[i])%P;
        }
    }
    printf("%d\n", f[n+1]);
    return 0;
}