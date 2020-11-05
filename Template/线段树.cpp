#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define ls (root<<1)
#define rs (root<<1|1)
#define mid ((l+r)>>1)
#define MAXN 100005
#define LL long long
using namespace std;

int n, m, val[MAXN*4], tag[MAXN*4];

void up(int root)
{
    val[root]=val[ls]+val[rs];
}

void down(int root, int l, int r)
{
    if(!tag[root]) return;
    tag[ls]+=tag[root];
    tag[rs]+=tag[root];
    val[ls]+=tag[root]*(mid-l+1);
    val[rs]+=tag[root]*(r-mid);
    tag[root]=0;
}

void build(int root, int l, int r)
{
    if(l==r)
    {
        scanf("%d", &val[root]);
        return ;
    }
    build(ls, l, mid);
    build(rs, mid+1, r);
    up(root);
}

void add(int root, int l, int r, int x, int y, int k)
{
    if(x>r || y<l) return;
    if(l>=x && r<=y)
    {
        val[root]+=k*(r-l+1);
        tag[root]+=k;
        return;
    }
    down(root, l, r);
    add(ls, l, mid, x, y, k);
    add(rs, mid+1, r, x, y, k);
    up(root);
}

int query(int root, int l, int r, int x, int y)
{
    if(l>y || r<x) return 0;
    if(l>=x && r<=y) return val[root];
    down(root, l, r);
    return query(ls, l, mid, x, y)+query(rs, mid+1, r, x, y);
}

int main()
{
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    for(int i=1; i<=m; ++i)
    {
        //add(1, 1, n, x, y, k) x~y 区间加 k
        //query(1, 1, n, x, y) x~y 区间和
    }
}