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

int t, a, b, c;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &a, &b, &c);
        int d=a+b+c;
        if(d%9) printf("NO\n");
        else if(a<d/9 || b<d/9 || c<d/9) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}