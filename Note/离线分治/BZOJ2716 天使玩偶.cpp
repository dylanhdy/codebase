#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define MAXN 1000005
#define INF 0x3f3f3f3f
using namespace std;

int n, m, maxx, maxy, ans[MAXN], t[MAXN];

struct Ask {int x, y, op, id;} a[MAXN], b[MAXN], c[MAXN];

bool CMP (Ask a, Ask b)
{
    return a.x<b.x;
}

void add(int x, int y)
{
    for(; x<=maxy; x+=(x&-x)) t[x]=max(t[x], y);
}

void clr(int x)
{
    for(; x<=maxy; x+=(x&-x)) t[x]=-INF;
}

int sum(int x)
{
    int y=-INF;
    for(; x; x-=(x&-x)) y=max(y, t[x]);
    return y;
}

void cdq(int l, int r)
{
    if(l==r) return ;
    int mid=(l+r)>>1;
    cdq(l, mid); cdq(mid+1, r);
    int pnt=l;
    for(int i=mid+1; i<=r; i++)
    {
        if(b[i].op==1) continue;
        while(b[pnt].x<=b[i].x && pnt<=mid)
        {
            if(b[pnt].op==1) add(b[pnt].y, b[pnt].x+b[pnt].y);
            pnt++;
        }
        ans[b[i].id]=min(ans[b[i].id], b[i].x+b[i].y-sum(b[i].y));
    }
    for(int i=l; i<pnt; i++) if(b[i].op==1) clr(b[i].y);
    merge(b+l, b+mid+1, b+mid+1, b+r+1, c+l, CMP);
    for(int i=l; i<=r; i++) b[i]=c[i];
}


int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",  &a[i].x, &a[i].y);
        a[i].op=1; a[i].id=i; a[i].x++; a[i].y++;
        maxx=max(maxx, a[i].x); maxy=max(maxy, a[i].y);
    }
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d", &a[i+n].op, &a[i+n].x, &a[i+n].y);
        a[i+n].id=i+n; a[i+n].x++; a[i+n].y++;
        maxx=max(maxx, a[i+n].x); maxy=max(maxy, a[i+n].y);
    }
    memset(ans, 0x3f, sizeof(ans));
    memset(t, -0x3f, sizeof(t));
    for(int i=1; i<=n+m; i++) b[i]=a[i];
    cdq(1, n+m);
    for(int i=1; i<=n+m; i++) b[i]=a[i], b[i].x=maxx-b[i].x+1;
    cdq(1, n+m);
    for(int i=1; i<=n+m; i++) b[i]=a[i], b[i].y=maxy-b[i].y+1;
    cdq(1, n+m);
    for(int i=1; i<=n+m; i++) b[i]=a[i], b[i].x=maxx-a[i].x+1, b[i].y=maxy-b[i].y+1;
    cdq(1, n+m);
    for(int i=1; i<=n+m; i++) if(a[i].op==2) printf("%d\n", ans[i]);
}
