#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int T, n;

int gcd(int x, int y)
{
    return y?gcd(y, x%y):x;
}

bool check(int x)
{
    int a, b, c;
    if(x%3==1) a=x/3-1, b=x/3, c=x/3+2;
    if(x%3==2) a=x/3-1, b=x/3+1, c=x/3+2;
    return gcd(b, a)==1 && gcd(c, b)==1 && gcd(c, a)==1;
}

int main()
{
    scanf("%d", &T);
    for(int i=1; i<=T; ++i)
    {
        scanf("%d", &n);
        if(n%2) printf("Case #%d: 1\n", i);
        else if(n==6) printf("Case #%d: -1\n", i);
        else if(n%4==0) printf("Case #%d: 2\n", i);
        else if(n%3==0) printf("Case #%d: 2\n", i);
        else if(check(n)) printf("Case #%d: 3\n", i);
        else printf("Case #%d: 4\n", i);
    }
    return 0;
}