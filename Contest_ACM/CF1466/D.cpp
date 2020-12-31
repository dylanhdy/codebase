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

int t, n, deg[100005], w[100005];

vector<int> vec;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        LL ans=0;
        vec.clear();
        scanf("%d", &n);
        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &w[i]);
            ans+=w[i], deg[i]=0;
        }
        for(int i=1; i<n; ++i)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            deg[x]++, deg[y]++;
        }
        for(int i=1; i<=n; ++i)
            for(int j=2; j<=deg[i]; ++j) vec.PB(w[i]);
        sort(vec.begin(), vec.end());
        printf("%lld ", ans);
        for(int i=vec.size()-1; i>=0; --i)
        {
            ans+=vec[i];
            printf("%lld ", ans);
        }
        printf("\n");
    }
    return 0;
}