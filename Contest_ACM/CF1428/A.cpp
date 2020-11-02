#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int t, x1, x2, z1, z2;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d%d", &x1, &z1, &x2, &z2);
        if(x1==x2 && z1==z2) printf("0\n");
        else if(x1==x2 || z1==z2) printf("%d\n", abs(x1-x2)+abs(z1-z2));
        else printf("%d\n", abs(x1-x2)+abs(z1-z2)+2);
    }
    return 0;
}