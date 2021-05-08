#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n;
LL ans, base[66];

void insert(LL *base, LL x)
{
    for(int i=60; i>=0; --i)
        if((x>>i)&1) {
            if(!base[i]) {
                base[i]=x;
                return;
            }
            x^=base[i];
        }
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        LL temp;
        scanf("%lld", &temp);
        insert(base, temp);
    }
    for(int i=60; i>=0; --i) ans=max(ans, ans^base[i]);
    printf("%lld\n", ans);
    return 0;
}