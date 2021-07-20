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
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;

int n;
char s[MAXN];

int check(int lim)
{
    int num1=0, num2=0, num3=0, num4=0;
    for(int i=1; i<=n; ++i)
    {
        if(s[i]=='2')
        {
            if(num1<lim) num1++;
            else if(num3<num2) num3++;
        }
        if(s[i]=='0')
        {
            if(num2<num1) num2++;
            else if(num4<num3) num4++;
        }
    }
    return num4==lim;
}

int main()
{
    while(scanf("%d%s", &n, s+1)!=EOF)
    {
        int l=0, r=n, ans;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid)) ans=mid, l=mid+1;
            else r=mid-1;
        }
        printf("%d\n", ans);
    }
    return 0;
}