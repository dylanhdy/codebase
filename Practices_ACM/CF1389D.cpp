#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#define rint register int
#define LL long long
#define MAXN 
using namespace std;

LL t, n, k, l1, r1, l2, r2;

int main()
{
    scanf("%lld", &t);
    for(rint i=1; i<=t; ++i)
    {
        LL ans=0, temp=0;
        scanf("%lld%lld%lld%lld%lld%lld", &n, &k, &l1, &r1, &l2, &r2);
        LL len1=r1-l1, len2=r2-l2;
        if(l1==r1 && l2==r2 && l1==l2)
        {
            printf("%lld\n", k*2);
            continue;
        }
        if(r1>l2 && l1<r2)
        {
            if((r1>=r2 && l1<=l2) || (r1<=r2 && l1>=l2)) temp=min(r1-l1, r2-l2);
            else temp=min(r1-l2, r2-l1);
            if(temp*n>=k) ans=0;
            else if((len1+len2-temp)*n>=k) ans=k-temp*n;
            else ans=(len1+len2-temp*2)*n+(k-(len1+len2-temp)*n)*2;
        }
        else
        {
            temp=max(l2-r1, l1-r2);
            LL cost=temp*2+len1+len2, val=temp+len1+len2, num=k/val;
            if(num>=n) ans=(k-n*val)*2+n*cost;
            else if(num==0) ans=temp+(k-num*val);
            else ans=cost*num+min((k-num*val)*2, temp+(k-num*val));
        }
        printf("%lld\n", ans);
    }
    return 0;
}