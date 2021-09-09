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
#define MAXN 300005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, a[MAXN];
LL pre[MAXN], ans1[MAXN], ans2[MAXN];

constexpr int lim(300000);

struct BIT {
    LL t[MAXN];

    void add(int x, int y)
    {
        for(; x<=lim; x+=(x&-x)) t[x]+=y;
    }

    LL ask(int x)
    {
        LL num=0;
        for(; x; x-=(x&-x)) num+=t[x];
        return num;
    }
} t1, t2;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=1; i<=n; ++i) {
        LL num=0;
        for(int j=1; j*a[i]<=lim; ++j)
            num+=j*(t1.ask(min(lim, (j+1)*a[i]-1))-t1.ask(j*a[i]-1));
        ans1[i]=ans1[i-1]+pre[i-1]-num*a[i];
        t1.add(a[i], 1);
    }
    for(int i=1; i<=n; ++i) {
        ans2[i]=ans2[i-1]+1LL*(i-1)*a[i]-t2.ask(a[i]);
        for(int j=1; j*a[i]<=3e5; ++j)
            t2.add(j*a[i], a[i]);
    }
    for(int i=1; i<=n; ++i) printf("%lld ", ans1[i]+ans2[i]);
    return 0;
}