#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#define rint register int
#define LL long long
#define MAXN 
using namespace std;

int t, n, k, l1, r1, l2, r2, len1, len2;

int main()
{
    scanf("%d", &t);
    for(rint i=1; i<=t; ++i)
    {
        LL ans=0, temp=0;
        scanf("%d%d%d%d%d%d", &n, &k, &l1, &r1, &l2, &r2);
        len1=r1-l1, len2=r2-l2;
        if(r1>l2 && l1<r2)
        {
            if((r1>=r2 && l1<=l2) || (r1<=r2 && l1>=l2)) temp=min(r1-l1, r2-l2);
            else temp=min(r1-l2, r2-l1);
            if(temp*n>=k) ans=0;
            else if((len1+len2-temp)*n>=k) ans=k-temp*n;
            else ans=(len1+len2-temp*2)*n+2*(k-(len1+len2-temp)*n);
        }
        else
        {
            if(l2>=r1) temp=l2-r1;
            else temp=l1-r2;
            LL cost=temp*2+len1+len2, val=temp+len1+len2, num=k/val;
            if(num>n) ans=2*(k-n*val)+n*cost;
            else ans=cost*num+min((k-num*val)*2, temp+(k-num*val));
        }
        printf("%lld\n", ans);
    }
    return 0;
}