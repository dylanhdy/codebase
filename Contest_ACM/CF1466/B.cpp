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

int t, n,  vis[1005], a[100005];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        int ans=0, last=0;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &a[i]);
            //printf("%d %d\n", last, a[i]);
            if(a[i]>last) last=a[i], ans++;
            else if(a[i]==last) last++, ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}