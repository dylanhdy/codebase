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
using namespace std;

int t, n, k, h[200005];

bool check()
{
    int l=h[1], r=h[1];
    for(int i=1; i<n; ++i)
    {
        //printf("%d %d %d\n", i, l, r);
        if(h[i]>r || l>h[i]+k-1) return false;
        l=max(h[i+1], l-k+1);
        r=min(h[i+1]+k-1, r+k-1);
    }
    return (l<=h[n] && r>=h[n]);
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        for(int i=1; i<=n; ++i) scanf("%d", &h[i]);
        if(check()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}