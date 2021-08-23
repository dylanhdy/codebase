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

int T, w, h, a1, a2, b1, b2, x, y;

int main()
{
    scanf("%d", &T);
    while(T--) {
        int ans=INF;
        scanf("%d%d", &w, &h);
        scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
        scanf("%d%d", &x, &y);
        double a3=(a1+a2)/2.0, b3=(b1+b2)/2.0;
        double l1=(a2-a1)/2.0, l2=(b2-b1)/2.0;
        if(a2+x-a1<=w) ans=min(ans, max(0, a2+x-w));
        if (-a1+x<=w-a2) ans=min(ans, max(0, -a1+x));
        if (b2+y<=b1+h) ans=min(ans, max(0, b2+y-h));
        if (-b1+y<=h-b2) ans=min(ans, max(0, -b1+y));
        if(ans==INF) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}