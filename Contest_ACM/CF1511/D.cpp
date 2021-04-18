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

int n, k;

void dfs(int res, int x, int y)
{
    if(!res) return;
    if(x==y) {
        printf("%c", 'a'+x-1);
        if(!(--res)) return;
        printf("%c", 'a'+x-1);
        if(!(--res)) return;
        if(x!=k-1) dfs(res, x, y+2);
        else {
            printf("%c", 'a'+k-1);
            if(!(--res)) return;
            for(int i=k; i>=2; --i) {
                printf("%c", 'a'+i-1);
                if(!(--res)) return;
            }
            dfs(res, 1, 1);
        }
    } else {
        printf("%c", 'a'+y-1);
        if(!(--res)) return;
        printf("%c", 'a'+x-1);
        if(!(--res)) return;
        if(y==k) dfs(res, x+1, x+1);
        else dfs(res, x, y+1);
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    if(k==1) {
        for(int i=1; i<=n; ++i) printf("a");
        return 0;
    }
    dfs(n, 1, 1);
    return 0;
}