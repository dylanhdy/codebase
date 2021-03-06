#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, q, num, a[MAXN];

int main() {
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        if(a[i]) num++;
    }
    for(int i=1; i<=q; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if(x==1) {
            if(a[y]==0) num++;
            else num--;
            a[y]=1-a[y];
        }
        else {
            if(num>=y) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}