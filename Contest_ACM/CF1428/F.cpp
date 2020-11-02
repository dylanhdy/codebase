#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 500005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, len, a[MAXN], num[MAXN];
LL add, ans;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%1d", &a[i]);
        if(a[i]==0)
        {
            len=0;
            num[0]++;
        }
        else
        {
            len++;
            if(len==1)
            {
                num[1]+=num[0]+1;
                add+=num[0]+1;
                num[0]=0;
            }
            else
            {
                num[len]+=num[len-1];
                add+=num[len-1]+len-1;
                num[len-1]=1;
            }
        }
        ans+=add;
    }
    printf("%lld\n", ans);
    return 0;
}