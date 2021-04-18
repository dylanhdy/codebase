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

int T, a, b, c;

int num(LL x)
{
    int n=0;
    while(x) {
        x/=10;
        n++;
    }
    return n;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &a, &b, &c);
        LL val3=2;
        while(num(val3)<c) val3*=2;
        LL val1=val3, val2=val3;
        while(num(val1)<a) val1*=2;
        while(num(val2)<b) val2*=3;
        printf("%lld %lld\n", val1, val2);
    }
    return 0;
}