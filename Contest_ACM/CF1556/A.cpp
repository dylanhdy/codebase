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

int T, a, b;

int main()
{
    scanf("%d", &T);

    while(T--) {
        scanf("%d%d", &a, &b);
        if((a+b)&1) {
            printf("-1\n");
            continue;
        }
        if(a==b && a==0) printf("0\n");
        else if(a==b) printf("1\n");
        else printf("2\n");
    }
    return 0;
}