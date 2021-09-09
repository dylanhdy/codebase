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
#define MAXN 10005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, k, va[5][5], vo[5][5], a[MAXN];
int main()
{
    scanf("%d%d", &n, &k);
    for(int i=1; i<=3; ++i)
        for(int j=i+1; j<=3; ++j) {
            printf("or %d %d\n", i, j);
            fflush(stdout);
            scanf("%d", &vo[i][j]);
            printf("and %d %d\n", i, j);
            fflush(stdout);
            scanf("%d", &va[i][j]);
        }
    int base=va[1][2]&va[1][3]&va[2][3];
    a[2]=(vo[1][2]&vo[2][3]^va[1][3])|base;
    a[1]=(vo[1][2]^a[2])|va[1][2];
    a[3]=(vo[2][3]^a[2])|va[2][3];
    for(int i=4; i<=n; ++i) {
        int vvo, vva;
        printf("or %d %d\n", i, i-1);
        fflush(stdout);
        scanf("%d", &vvo);
        printf("and %d %d\n", i, i-1);
        fflush(stdout);
        scanf("%d", &vva);
        a[i]=(vvo^a[i-1])|vva;
    }
    sort(a+1, a+n+1);
    printf("finish %d\n", a[k]);
    fflush(stdout);
    return 0;
}