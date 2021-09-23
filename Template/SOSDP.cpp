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
#define MAXN 2000005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, f[MAXN], g[MAXN];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<1<<n; ++i) scanf("%d%d", &f[i], &g[i]);
    for(int i=0; i<n; ++i)
        for(int sta=0; sta<1<<n; ++sta) {
            if((sta>>i)&1) f[sta]+=f[sta^(1<<i)]; //子集和
            if(!((sta>>i)&1)) g[sta]+=g[sta^(1<<i)]; //母集和
        }
    return 0;
}