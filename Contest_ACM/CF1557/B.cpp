#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
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

int T, n, k, a[100005], b[100005];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &k);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            b[i]=a[i];
        }
        sort(b+1, b+n+1);
        int num=n;
        for(int i=1; i<=n; ++i) {
            a[i]=lower_bound(b+1, b+n+1, a[i])-b;
            if(i>1 && a[i]==a[i-1]+1) num--;
        }

        if(num<=k) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}