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

int n, ans=INF, a[MAXN], b[MAXN];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        b[i]=(b[i-1]^a[i]);
    }
    if(n>60)
    {
        printf("1\n");
        return 0;
    }
    for(int i=2; i<=n; ++i)
        for(int l=i-1; l>=1; --l)
            for(int r=i; r<=n; ++r)
                if((b[r]^b[i-1])<(b[l-1]^b[i-1])) ans=min(ans, r-l-1);
    if(ans==INF) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}