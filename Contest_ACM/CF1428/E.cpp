#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, k, a[MAXN];
LL ans;

struct QWQ
{
    int num, cnt;
    LL val, sum;
    bool friend operator < (QWQ x, QWQ y)
    {
        return x.val<y.val;
    }
} temp;

priority_queue<QWQ> q;

inline LL cal(int x, int y, int z)
{
    LL ans1=1LL*x*(x-1)/2*(z+1)*(z+1);
    LL ans2=1LL*y*(y-1)/2*z*z;
    LL ans3=1LL*x*y*z*(z+1);
    return ans1+ans2+ans3;
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        ans+=1LL*a[i]*a[i];
        temp.num=a[i], temp.cnt=2, temp.sum=0;
        int x=a[i]%2, y=2-a[i]%2, z=a[i]/2;
        temp.val=cal(x, y, z);
        q.push(temp);
    }
    for(int i=n+1; i<=k; ++i)
    {
        temp=q.top(); q.pop();
        LL val=temp.val, sum=temp.sum+val;
        int cnt=temp.cnt+1, num=temp.num;
        ans-=val*2;
        int x=num%cnt, y=cnt-num%cnt, z=num/cnt;
        temp.cnt=cnt, temp.sum=sum, temp.val=cal(x, y, z)-sum;
        q.push(temp);
    }
    printf("%lld\n", ans);
    return 0;
}