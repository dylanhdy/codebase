#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 100005
using namespace std;

int n, m, k, ans[MAXN*2], t[MAXN*2];

struct A {int x, y, z, num, ans;} a[MAXN], b[MAXN], c[MAXN];

bool CMP1(A a, A b)
{
    if(a.x!=b.x) return a.x<b.x;
    if(a.y!=b.y) return a.y<b.y;
    return a.z<b.z;
}

bool CMP2(A a, A b)
{
    if(a.y!=b.y) return a.y<b.y;
    return a.z<b.z;
}

void add(int x, int y)
{
    for(; x<=k; x+=(x&-x)) t[x]+=y;
}

int sum(int x)
{
    int y=0;
    for(; x; x-=(x&-x)) y+=t[x];
    return y;
}

void cdq(int l, int r)
{
    if(l==r)  {b[l].ans+=b[l].num-1; return ;}
    int mid=(l+r)>>1;
    cdq(l, mid); cdq(mid+1, r);
    int pnt=l;
    for(int i=mid+1; i<=r; i++)
    {
        while(b[pnt].y<=b[i].y && pnt<=mid) add(b[pnt].z, b[pnt].num), pnt++;
        b[i].ans+=sum(b[i].z);
    }
    for(int i=l; i<pnt; i++) add(b[i].z, -b[i].num);
    merge(b+l, b+mid+1, b+mid+1, b+r+1, c+l, CMP2);
    for(int i=l; i<=r; i++) b[i]=c[i];
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z), a[i].ans=1;
    sort(a+1, a+n+1, CMP1);
    for(int i=1; i<=n; i++)
    {
        if(a[i].x==a[i-1].x && a[i].y==a[i-1].y && a[i].z==a[i-1].z) b[m].num++;
        else b[++m]=a[i], b[m].num=1;
    }
    cdq(1, m);
    sort(b+1, b+m+1, CMP1);
    for(int i=1; i<=m; i++) ans[b[i].ans]+=b[i].num;
    for(int i=1; i<=n; i++) printf("%d\n", ans[i]);
}
