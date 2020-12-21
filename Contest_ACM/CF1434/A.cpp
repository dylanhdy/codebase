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
#define PB push_back
#define MP make_pair
#define INF 0x3f3f3f3f
using namespace std;
 
int n, cnt, a[10], b[MAXN], f[MAXN];
pair<int, int> c[MAXN*6];
 
bool check(int lim)
{
    int num=0;
    for(int i=1; i<=n; ++i) f[i]=0;
    for(int l=1, r=1; r<=cnt; ++r)
    {
        while(c[l].first<c[r].first-lim)
        {
            f[c[l].second]--;
            if(!f[c[l].second]) num--;
            l++;
        }
        if(!f[c[r].second]) num++;
        f[c[r].second]++;
        if(num==n) return 1;
    }
    return 0;
}
 
int main()
{
    for(int i=1; i<=6; ++i) scanf("%d", &a[i]);
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &b[i]);
        for(int j=1; j<=6; ++j)
            if(b[i]>a[j]) c[++cnt]=MP(b[i]-a[j], i);
    }
    sort(c+1, c+cnt+1);
    int l=0, r=1e9, ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid, r=mid-1;
        else l=mid+1;
    }
    printf("%d\n", ans);
    return 0;
}