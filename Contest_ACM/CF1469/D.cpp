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

int t, n, k, a[200005];

int main()
{
    a[1]=2, a[2]=2;
    for(int i=3; i<=8; ++i) a[i]=a[i-1]*a[i-2];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n==3)
        {
            printf("2\n3 2\n3 2\n");
            continue;
        }
        if(n==4)
        {
            printf("3\n3 4\n4 2\n4 2\n");
            continue;
        }
        int x=0;
        while(a[x]<n) x++;
        printf("%d\n", n+5);
        for(int i=2; i<n; ++i)
            if(i!=a[x-1] && i!=a[x-2]) printf("%d %d\n", i, n);
        printf("%d %d\n%d %d\n", n, a[x-1], n, a[x-1]);
        for(int i=1; i<=7; ++i)
        {
            if(i&1) printf("%d %d\n", a[x-1], a[x-2]);
            else printf("%d %d\n", a[x-2], a[x-1]);
        }
    }
}