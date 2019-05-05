#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define LL long long
#define MAXN 600005
#define INF 300000
using namespace std;

int n, m, k, cnt, ans[MAXN];
LL p[MAXN], t[MAXN];

struct Act {int id, op, x, y; LL z;} a[MAXN], lq[MAXN],  rq[MAXN];

vector<int> vec[MAXN];

void add(int x, LL y)
{
    for(; x<=m+1; x+=(x&-x)) t[x]+=y;
}

LL ask(int x)
{
    LL sum=0;
    for(; x; x-=(x&-x)) sum+=t[x];
    return sum;
}

void solve(int lval, int rval, int l, int r)
{
    if(l>r) return ;
    if(lval==rval)
    {
        for(int i=l; i<=r; i++)
            if(a[i].op==0) ans[a[i].id]=lval;
        return;
    }
    int mid=(lval+rval)>>1, lt=0, rt=0;
    for(int i=l; i<=r; i++)
    {
        if(a[i].op==1)
        {
            if(a[i].id<=mid)
            {
                if(a[i].x<=a[i].y) add(a[i].x, a[i].z), add(a[i].y+1, -a[i].z);
                else add(1, a[i].z), add(a[i].y+1, -a[i].z), add(a[i].x, a[i].z);
                lq[++lt]=a[i];
            }
            else rq[++rt]=a[i];
        }
        else
        {
            LL num=0;
            for(int j=0; j<vec[a[i].id].size(); j++)
            {
                num+=ask(vec[a[i].id][j]);
                if(num>a[i].z) break;
            }
            if(num>=a[i].z) lq[++lt]=a[i];
            else a[i].z-=num, rq[++rt]=a[i];
        }
    }
    for(int i=l; i<=r; i++)
        if(a[i].op==1 && a[i].id<=mid)
        {
            if(a[i].x<=a[i].y) add(a[i].x, -a[i].z), add(a[i].y+1, a[i].z);
            else add(1, -a[i].z), add(a[i].y+1, a[i].z), add(a[i].x, -a[i].z);
        }

    for(int i=1; i<=lt; i++) a[l+i-1]=lq[i];
    for(int i=1; i<=rt; i++) a[l+i+lt-1]=rq[i];
    solve(lval, mid, l, l+lt-1);
    solve(mid+1, rval, l+lt, r);
}


int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++)
    {
        int temp;
        scanf("%d", &temp);
        vec[temp].push_back(i);
    }
    for(int i=1; i<=n; i++) scanf("%lld", &p[i]);
    scanf("%d", &k);
    for(int i=1; i<=k; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[++cnt].id=i; a[cnt].x=x; a[cnt].y=y; a[cnt].z=z, a[cnt].op=1;
    }
    for(int i=1; i<=n; i++) a[++cnt].id=i, a[cnt].z=p[i], a[cnt].op=0;
    solve(1, k+1, 1, cnt);
    for(int i=1; i<=n; i++)
    {
        if(ans[i]!=k+1) printf("%d\n", ans[i]);
        else printf("NIE\n");
    }
}
