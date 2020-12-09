#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 50005
#define MAXM 500005
#define P 1000000007
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;

int T, n, m, k, cnt, block, vis[MAXM], f[MAXN];
LL ans;

struct Edge {int x, y, w;} edge[MAXM];

bool CMP(Edge x, Edge y) {return x.w>y.w;}

int find(int x)
{
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        cnt=ans=0, block=n;
        for(int i=1; i<=m; ++i) vis[i]=0;
        for(int i=1; i<=n; ++i) f[i]=i;
        for(int i=1; i<=m; ++i)
        {
            int x, y, w, c;
            scanf("%d%d%d%d", &x, &y, &w, &c);
            if(!c)
            {
                int fx=find(x), fy=find(y);
                if(fx!=fy) f[fx]=fy, block--;
                ans+=w;
            }
            else edge[++cnt]={x, y, w};
        }
        sort(edge+1, edge+cnt+1, CMP);
        for(int i=1; i<=cnt && k; ++i)
        {
            int fx=find(edge[i].x), fy=find(edge[i].y);
            if(fx!=fy)
            {
                f[fx]=fy, block--;
                ans+=edge[i].w;
                vis[i]=1, k--;
            }
            if(block==1) break;
        }
        if(block>1) printf("-1\n");
        else
        {
            for(int i=1; i<=cnt && k; ++i)
                if(!vis[i])
                {
                    k--;
                    ans+=edge[i].w;
                }
            printf("%lld\n", ans);
        }
    }
}