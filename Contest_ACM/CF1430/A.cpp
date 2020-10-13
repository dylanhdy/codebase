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

int n, t, a, b, c;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        int a=0, b=0, c=0;
        scanf("%d", &n);
        c=n/7;
        n%=7;
        if(n==1) c--, a++, b++;
        if(n==2) c--, a+=3;
        if(n==3) a++;
        if(n==4) c--, a+=2, b++;
        if(n==5) b++;
        if(n==6) a+=2;
        if(c<0) printf("-1\n");
        else printf("%d %d %d\n", a, b, c);
    }   
    return 0;
}