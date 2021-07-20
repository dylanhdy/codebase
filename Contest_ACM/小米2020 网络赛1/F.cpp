#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int k, L, R;
LL ans, l, r, sum;

struct A {int num, l, r;} a[MAXN];

bool check(LL ans)
{
    LL suml=0, res1=L, res2=0;
    for(int i=1; i<=k; ++i)
    {
        suml+=a[i].l;
        res1-=a[i].l;
    }
    if(suml>R) return false;
    for(int i=1; i<=k; ++i)
    {
        LL num1=(a[i].num-ans*a[i].l)/ans, num2=(a[i].num-ans*a[i].l)%ans;
        if(num1>=a[i].r-a[i].l) res1-=(a[i].r-a[i].l);
        else
        {
            res1-=num1;
            if(res2>=num2) res2-=num2;
            else res1--, res2+=ans-num2;
        }
    }
    return res1<=0;
}

int main()
{
    scanf("%d%d%d", &k, &L, &R);
    for(int i=1; i<=k; ++i)
    {
        scanf("%d", &a[i].num);
        sum+=a[i].num;
    }
    l=1, r=sum/L;
    for(int i=1; i<=k; ++i)
    {
        scanf("%d%d", &a[i].l, &a[i].r);
        if(a[i].l) r=min(r, 1LL*a[i].num/a[i].l);
    }
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(check(mid)) ans=mid, l=mid+1;
        else r=mid-1;
    }
    printf("%lld\n", ans);
    return 0;
}