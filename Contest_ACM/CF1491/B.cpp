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

int t, n, u, v, a[MAXN];

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &u, &v);
        int flag=0;
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            if(i>1) flag=max(flag, abs(a[i]-a[i-1]));
        }
        if(flag==0) printf("%d\n", min(u+v, 2*v));
        else if(flag==1) printf("%d\n", min(u, v));
        else printf("%d\n", 0);
    }
    return 0;
}