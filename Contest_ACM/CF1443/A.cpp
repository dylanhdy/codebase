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

int t, n;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int ans=4*n;
        for(int i=1; i<=n; ++i)
        {
            printf("%d ", ans);
            ans-=2;
        }
        printf("\n");
    }
    return 0;
}