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

int t, n, ans, vis[1005], a[1005];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ans=0;
        for(int i=0; i<=50; ++i) vis[i]=0;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        for(int i=1; i<=n; ++i)
            for(int j=i+1; j<=n; ++j) vis[a[j]-a[i]]=1;
        for(int i=1; i<=50; ++i) ans+=vis[i];
        printf("%d\n", ans);
    }
    return 0;
}