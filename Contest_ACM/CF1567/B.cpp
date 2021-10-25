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
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, a, b, w[300005];

int main()
{
    for(int i=1; i<=3e5; ++i) w[i]=w[i-1]^i;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &a, &b);
        if((b^w[a-1])==a) printf("%d\n", a+2);
        else if(b^w[a-1]) printf("%d\n", a+1);
        else printf("%d\n", a);
    }
    return 0;
}