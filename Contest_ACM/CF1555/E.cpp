#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define LD long double
#define MAXN 1000005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)/2)
using namespace std;

int n, m, t[MAXN*4], tag[MAXN*4];

struct A {int l, r, w;} a[MAXN];

bool CMP(A x, A y) {return x.w<y.w;}

void update(int rt, int l, int r, int x, int y, int k)
{
    if(l>y || r<x) return;
    if(l>=x && r<=y) {
        t[rt]+=k;
        tag[rt]+=k;
        return;
    }
    if(tag[rt]){
        t[ls]+=tag[rt], t[rs]+=tag[rt];
        tag[ls]+=tag[rt], tag[rs]+=tag[rt];
        tag[rt]=0;
    }
    update(ls, l, mid, x, y, k);
    update(rs, mid+1, r, x, y, k);
    t[rt]=min(t[ls], t[rs]);
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
        scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].w);
    sort(a+1, a+n+1, CMP);
    int ans=INF;
    for(int l=1, r=1; r<=n; r++) {
        update(1, 1, m-1, a[r].l, a[r].r-1, 1);
        if(t[1]>0) ans=min(ans, a[r].w-a[l].w);
        while(t[1]>0 && l<=r) {
            update(1, 1, m-1, a[l].l, a[l].r-1, -1);
            l++;
            if(t[1]>0) ans=min(ans, a[r].w-a[l].w);
        }
    }
    printf("%d\n", ans);
    return 0;
}