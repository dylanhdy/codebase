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

int n, T, a[1000];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=1; i<=2*n; ++i) scanf("%d", &a[i]);
        sort(a+1, a+n*2+1);
        printf("%d ", a[1]);
        for(int i=1; i<n; ++i) printf("%d %d ", a[i*2+1], a[i*2]);
        printf("%d\n", a[2*n]);
    }
    return 0;
}