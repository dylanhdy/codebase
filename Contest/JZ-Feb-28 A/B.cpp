#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 100005
#define P 1000000009
#define BASE 1000000007
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int a[4], b[4], dep1, dep2, ans, temp;

struct Sta
{
    int x, y, z;
    Sta(int a=0, int b=0, int c=0)
    {
        x=a, y=b, z=c;
    }
    bool friend operator != (Sta a, Sta b)
    {
        return a.x!=b.x || a.y!=b.y || a.z!=b.z;
    }
} ta, tb;

Sta solve(Sta a, int step, int lim)
{
    int x=a.x, y=a.y, z=a.z;
    temp=step;
    if(y-x==z-y || step==lim) return Sta(x, y, z);
    if(y-x>z-y)
    {   
        int k=min(lim-step, (y-x-1)/(z-y));
        step+=k;
        return solve(Sta(x, y-k*(z-y), z-k*(z-y)), step, lim);
    }
    else
    {
        int k=min(lim-step, (z-y-1)/(y-x));
        step+=k;
        return solve(Sta(x+k*(y-x), y+k*(y-x), z), step, lim);
    }
}

int main()
{
    scanf("%d%d%d%d%d%d", &a[1], &a[2], &a[3], &b[1], &b[2], &b[3]);
    sort(a+1, a+4);
    sort(b+1, b+4);
    ta=Sta(a[1], a[2], a[3]);
    Sta fa=solve(ta, 0, INF);
    dep1=temp;
    tb=Sta(b[1], b[2], b[3]);
    Sta fb=solve(tb, 0, INF);
    dep2=temp;
    if(fa!=fb) {printf("NO\n"); return 0;}

    if(dep1<dep2) swap(dep1, dep2), swap(ta, tb);
    if(dep1!=dep2) ta=solve(ta, 0, dep1-dep2);
    int l=0, r=dep2;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(solve(ta, 0, mid)!=solve(tb, 0, mid)) l=mid+1;
        else ans=mid, r=mid-1;
    }
    printf("YES\n%d\n", ans*2+dep1-dep2);
}