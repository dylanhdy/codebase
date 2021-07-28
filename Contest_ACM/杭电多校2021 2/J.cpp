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
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, b[100005], c[100005];
LL a, p;

LL qmul(LL x, LL y)
{
    LL res=x*y-(LL)((LD)x/p*y+0.5)*p;
    return res<0?res+p:res;
}

LL qpow(LL x, LL y)
{
    LL num=1;
    while(y) {
        if(y&1) num=qmul(num, x);
        x=qmul(x, x), y>>=1;
    }
    return num;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%lld%lld", &a, &p);
        if(qpow(a, (p-1)/2)==1) printf("0\n");
        else printf("1\n");
    }
    return 0;
}