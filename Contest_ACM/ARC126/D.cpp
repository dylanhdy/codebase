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
#define MAXN 205
#define MAXM 65540
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, k, a[MAXN], f[2][MAXM][2], siz[MAXM], val[MAXM][16];

int main()
{
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    for(int i=0; i<k; ++i)
        for(int sta=0; sta<(1<<k); ++sta) {
            if((sta>>i)&1) siz[sta]++;
            else {
                for(int j=i+1; j<k; ++j)
                    if((sta>>j)&1) val[sta][i]++;
            }
        }
    memset(f, 0x3f, sizeof(f));
    f[0][0][0]=0;
    for(int i=1; i<=n; ++i) {
        int np=(i&1), lp=(1^(i&1));
        for(int sta=0; sta<(1<<k); ++sta) {
            f[np][sta][0]=f[lp][sta][0]+siz[sta];
            if((sta>>a[i])&1) {
                int lsta=sta^(1<<a[i]);
                f[np][sta][0]=min(f[np][sta][0], f[lp][lsta][0]+val[lsta][a[i]]);
            }
            f[np][sta][1]=min(f[np][sta][0], f[lp][sta][1]+k-siz[sta]);
            if((sta>>a[i])&1) {
                int lsta=sta^(1<<a[i]);
                f[np][sta][1]=min(f[np][sta][1], f[lp][lsta][1]+val[lsta][a[i]]);
            }
            //if(f[np][sta][0]<INF) printf("%d %d %d\n", i, sta, f[np][sta][0]);
        }
    }
    printf("%d\n", f[n&1][(1<<k)-1][1]);
    return 0;
}