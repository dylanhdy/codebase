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

int T, n, a[MAXN], pos[MAXN], vis[MAXN];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        int r=n+1;
        for(int i=1; i<=n; ++i) vis[i]=0;
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            pos[a[i]]=i;
        }
        for(int i=n; i>=1; --i) {
            if(vis[i]) continue;
            for(int j=pos[i]; j<r; ++j) {
                vis[a[j]]=1;
                printf("%d ", a[j]);
            }
            r=pos[i];
        }
        printf("\n");
    } 
    return 0;
}