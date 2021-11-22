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
#define MAXN
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int T, n, a[100005];

int main()
{
    scanf("%d", &T);
    while(T--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if(x==y) printf("%d\n", x);
        if(x<y) printf("%d\n", (y/x)*x+(y%x)/2);
        if(y<x) printf("%d\n", y+x);
    }
    return 0;
}