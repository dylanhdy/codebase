#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;

int t;
LL l, r;

int main()
{
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        scanf("%lld%lld", &l, &r);
        if(l*2<=r) printf("%lld %lld\n", l, l*2);
        else printf("-1 -1\n");
    }
    return 0;
}