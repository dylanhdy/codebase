#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 400005
#define MAXM 
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int t, n, ans1, ans2, cnt, a[MAXN], b[MAXN], vis[MAXN*2];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        ans2=n;
        ans1=cnt=0;
        for(int i=1; i<=2*n; ++i) vis[i]=0;
        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &a[i]);
            vis[a[i]]=1;
        }
        for(int i=1; i<=n*2; ++i)
            if(!vis[i]) b[++cnt]=i;
        for(int i=1, j=1; i<=n && j<=n; ++i)
        {
            while(b[j]<a[i] && j<=n) j++;
            if(j<=n) ans1++, j++;
        }
        for(int i=1, j=1; i<=n && j<=n; ++i)
        {
            if(a[i]>b[j]) j++, ans2--;
        }
        printf("%d\n", ans1-ans2+1);
    }   
    return 0;
}