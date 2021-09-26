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

int T, a, b, c, m;

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d%d", &a, &b, &c, &m);
        int maxn=max(max(a, b), c), sum=a+b+c;
        int l=max(0, maxn*2-sum-1), r=sum-3;
        if(m>=l && m<=r) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}