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

int t, n, a[100];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &a[i]);
            int temp=0;
            while((1LL<<temp)<=a[i]) temp++;
            printf("%d ", 1<<(temp-1));
        }
        printf("\n");
    }
    return 0;
}