#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#define LL long long
#define MAXN 100005
using namespace std;

int t, n;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", (n+1)/2+1);
    }
    return 0;
}