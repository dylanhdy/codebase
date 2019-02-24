#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 300005
#define INF 1e9
using namespace std;

int n, m, cnt1, cnt2, num[MAXN], t[MAXN], ans[MAXN];


struct Act {int x, y, z, id;} a[MAXN], lq[MAXN], rq[MAXN];

void add(int x, int y)
{
    for(; x<=n; x+=(x&-x)) t[x]+=y;
}

int ask(int x)
{
    int sum=0;
    for(; x; x-=(x&-x)) sum+=t[x];
    return sum;
}

void solve(int lval, int rval, int l, int r)
{
    if(l>r) return ;
    if(lval==rval)
    {
        for(int i=l; i<=r; i++)
            if(a[i].id>0) ans[a[i].id]=lval;
        return ;
    }
    int mid=(lval+rval)>>1, lt=0, rt=0;
    for(int i=l; i<=r; i++)
    {
        if(a[i].id<=0)
        {
            if(a[i].y<=mid) add(a[i].x, a[i].z), lq[++lt]=a[i];
            else rq[++rt]=a[i];
        }
        else
        {
            int num=ask(a[i].y)-ask(a[i].x-1);
            if(num>=a[i].z) lq[++lt]=a[i];
            else a[i].z-=num, rq[++rt]=a[i];
        }
    }
    for(int i=l; i<=r; i++)
        if(a[i].id<=0 && a[i].y<=mid) add(a[i].x, -a[i].z);
    for(int i=1; i<=lt; i++) a[l+i-1]=lq[i];
    for(int i=1; i<=rt; i++) a[l+lt+i-1]=rq[i];
    solve(lval, mid, l, l+lt-1);
    solve(mid+1, rval, l+lt, r);
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &num[i]);
        a[++cnt1].id=0; a[cnt1].x=i; a[cnt1].y=num[i]; a[cnt1].z=1;
    }
    for(int i=1; i<=m; i++)
    {
        int x, y, z; char op[5];
        scanf("%s", op);
        if(op[0]=='Q')
        {
            scanf("%d%d%d", &x, &y, &z);
            a[++cnt1].id=++cnt2; a[cnt1].x=x; a[cnt1].y=y; a[cnt1].z=z;
        }
        if(op[0]=='C')
        {
            scanf("%d%d", &x, &y);
            a[++cnt1].id=-1; a[cnt1].x=x; a[cnt1].y=num[x]; a[cnt1].z=-1;
            a[++cnt1].id=0; a[cnt1].x=x; a[cnt1].y=y; a[cnt1].z=1;
            num[x]=y;
        }
    }
    solve(0, INF, 1, cnt1);
    for(int i=1; i<=cnt2; i++) printf("%d\n", ans[i]);
}
