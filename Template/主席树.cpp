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
#define MAXM
#define mid ((l+r)>>1)
#define INF 0x3f3f3f3f
using namespace std;

int n, m, tot, rk[MAXN], root[MAXN];

struct Node {int ls, rs, val;} t[MAXN*40];
struct A {int id, num;} a[MAXN];

bool CMP(A x, A y) {return x.num<y.num;}

void update(int &rt1, int rt2, int l, int r, int x)
{
    rt1=++tot;
    t[rt1]=t[rt2], t[rt1].val++;
    if(l==r) return;
    if(x<=mid) update(t[rt1].ls, t[rt2].ls, l, mid, x);
    else update(t[rt1].rs, t[rt2].rs, mid+1, r, x);
}

int query(int rt1, int rt2, int l, int r, int k)
{
    if(l==r) return l;
    int temp=t[t[rt2].ls].val-t[t[rt1].ls].val;
    if(temp>=k) return query(t[rt1].ls, t[rt2].ls, l, mid, k);
    else return query(t[rt1].rs, t[rt2].rs, mid+1, r, k-temp);
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i].num);
        a[i].id=i;
    }
    sort(a+1, a+n+1, CMP);
    for(int i=1; i<=n; i++) rk[a[i].id]=i;
    for(int i=1; i<=n; i++) update(root[i], root[i-1], 1, n, rk[i]);
    for(int i=1; i<=m; i++)
    {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        printf("%d\n", a[query(root[x-1], root[y], 1, n, k)].num);
    }
}