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

int n, ans[505][505], a[505];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) ans[i][0]=1;
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        int x=i, y=i;
        ans[x][y]=a[i];
        for(int j=a[i]-1; j>=1; --j) {
            if(ans[x][y-1]) x++;
            else y--;
            ans[x][y]=a[i];
        }
    }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=i; ++j) printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}