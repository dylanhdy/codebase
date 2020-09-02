#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 200005
#define INF 0x3f3f3f3f;
using namespace std;

int n, t, a[MAXN];
LL k;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%lld", &n, &k);
        int maxn=-INF;
        int minn=INF;
        for(rint i=1; i<=n; ++i)
        {
            scanf("%d", &a[i]);
            maxn=max(a[i], maxn);
            minn=min(a[i], minn);
        }
        if(k%2==0)
            for(rint i=1; i<=n; ++i) printf("%d ", a[i]-=minn);
        else
            for(rint i=1; i<=n; ++i) printf("%d ", maxn-a[i]);
        printf("\n");
    }
    return 0;
}
