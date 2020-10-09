#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 200005
using namespace std;

int n, t, a[MAXN];

int main()
{
    scanf("%d", &t);
    for(rint i=1; i<=t; ++i)
    {
        scanf("%d", &n);
        int tag=1;
        for(rint j=1; j<=n; ++j) scanf("%d", &a[j]);
        for(rint j=2; j<=n; ++j)
            if(a[j]!=a[j-1]) tag=0;
        if(tag) printf("%d\n", n);
        else printf("1\n");
    }

    return 0;
}
