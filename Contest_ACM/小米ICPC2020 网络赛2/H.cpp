#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM 1005
#define P
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
using namespace std;

int n, m, pnt;
LL ans, f[1005];

struct A {int w, v;} a[MAXN];

bool CMP(A x, A y)
{
    return 1.0*x.v/x.w>1.0*y.v/y.w;
}

int main()
{
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        pnt=ans=0;
        for(int i=1; i<=n; ++i) scanf("%d%d", &a[i].w, &a[i].v);
        sort(a+1, a+n+1, CMP);
        for(int i=1; i<=n && m>=1000; ++i)
        {
            ans+=a[i].v, m-=a[i].w;
            pnt=i;
        }
        for(int i=0; i<=m; ++i) f[i]=0;
        for(int i=pnt+1; i<=n; ++i)
            for(int j=m; j>=a[i].w; --j) f[j]=max(f[j], f[j-a[i].w]+a[i].v);
        printf("%lld\n", f[m]+ans);
    }
}