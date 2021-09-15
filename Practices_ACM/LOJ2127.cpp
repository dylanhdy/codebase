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
#define MAXN 1050000
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n;
double ans, f[MAXN];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<1<<n; ++i) scanf("%lf", &f[i]);
    for(int i=0; i<n; ++i)
        for(int sta=0; sta<1<<n; ++sta)
            if((sta>>i)&1) f[sta]+=f[sta^(1<<i)];
    int all=(1<<n)-1;
    for(int sta=1; sta<1<<n; ++sta) {
        if(f[all^sta]==1) {
            printf("INF");
            return 0;
        }
        int cnt=__builtin_popcount(all^sta);
        if((n-cnt)&1) ans+=1/(1-f[all^sta]);
        else ans-=1/(1-f[all^sta]);
    }
    printf("%.10lf", ans);
    return 0;
}