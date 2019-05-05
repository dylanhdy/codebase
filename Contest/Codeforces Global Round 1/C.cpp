#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 100005
#define P 1000000007
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define ls (root<<1)
#define rs (root<<1|1)
#define mid ((l+r)>>1)
using namespace std;

int n, q, a[30];

void init()
{
    for(rint i=1; i<=25; ++i) a[i]=a[i-1]<<1|1;
}

int solve(int x)
{
    for(rint i=2; i*i<=x; ++i)
    {
        if(x%i) continue;
        return x/i;
    }
    return 1;
}

int main()
{
    init();
    //for(rint i=1; i<=25; ++i) printf("%d\n", a[i]);
    scanf("%d", &q);
    while(q--)
    {
        int x;
        scanf("%d", &x);
        for(rint i=1; i<=25; ++i)
        {
            if(a[i]==x)
            {
                if(i&1) printf("%d\n", solve(x));
                else printf("%d\n", a[i]/3);
                break;
            }
            if(x>a[i-1] && x<a[i]) {printf("%d\n", a[i]); break;}
        }
    }
    return 0;
}
