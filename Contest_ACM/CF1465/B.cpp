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

int t;
LL n;

bool check(LL x)
{
    LL temp=x;
    while(temp)
    {
        int num=temp%10;
        if(num && x%num) return false;
        temp/=10;
    }
    return true;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);
        while(check(n)==0) n++;
        printf("%lld\n", n);
    }
    return 0;
}