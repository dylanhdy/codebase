#include <bits/stdc++.h>
#define MAXN 100005
#define LL long long
using namespace std;
 
int a, b, c, d;
LL ans;
 
int main()
{
    scanf("%d%d%d%d", &a, &b, &c, &d);
    for(int i=0; i<=a+b; ++i)
    {
        int num1, num2;
        if(i<=min(a, b)) num1=i+1;
        else if(i<=max(a, b)) num1=min(a, b)+1;
        else num1=(a+b-i+1);
        num2=max(0, min(d-i, c)+1);
        ans+=1LL*num1*num2;
    }
    printf("%lld\n", ans);
}