#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int t, n, a[MAXN], b[MAXN];
char s[MAXN];

bool check(int x)
{
    LL sum=0;
    for(int i=1; i<=n; ++i)
        if(a[i]>x) sum+=b[i];
    return sum<=x;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        for(int i=1; i<=n; ++i) scanf("%d", &b[i]);
        int l=0, r=1e9, ans=1e9;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(check(mid)) ans=mid, r=mid-1;
            else l=mid+1;
        }
        printf("%d\n", ans);
    }
    return 0;
}