#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define ls (root<<1)
#define rs (root<<1|1)
#define mid (l+r>>1)
#define MAXN 100005
#define LL long long

LL n, m, p, opt, x, y, k, sum[MAXN*4], atag[MAXN*4], mtag[MAXN*4];

void up(LL root)
{
    sum[root]=sum[ls]+sum[rs];
}

void down(LL root, LL l, LL r)
{
    mtag[ls]=(mtag[ls]*mtag[root])%p; 
    mtag[rs]=(mtag[rs]*mtag[root])%p;
    atag[ls]=(atag[ls]*mtag[root]+atag[root])%p;
    atag[rs]=(atag[rs]*mtag[root]+atag[root])%p;
    sum[ls]=(sum[ls]*mtag[root]+atag[root]*(mid-l+1))%p;
    sum[rs]=(sum[rs]*mtag[root]+atag[root]*(r-mid))%p;
    atag[root]=0; mtag[root]=1;
}

void build(LL root, LL l, LL r)
{
    atag[root]=0; mtag[root]=1;
    if(l==r)
    {
        scanf("%lld", &sum[root]);
        return ;
    }
    build(ls, l, mid);
    build(rs, mid+1, r);
    up(root);
}

void add(LL root, LL l, LL r, LL x, LL y, LL k)
{
    if(x>r || y<l) return;
    if(l>=x && r<=y)
    {
        sum[root]=(sum[root]+k*(r-l+1))%p;
        atag[root]=(k+atag[root])%p;
        return;
    }
    down(root, l, r);
    add(ls, l, mid, x, y, k);
    add(rs, mid+1, r, x, y, k);
    up(root);
}

void mul(LL root, LL l, LL r, LL x, LL y, LL k)
{
    if(x>r || y<l) return;
    if(l>=x && r<=y)
    {
        sum[root]=(sum[root]*k)%p;
        atag[root]=(atag[root]*k)%p;
        mtag[root]=(mtag[root]*k)%p;
        return;
    }
    down(root, l, r);
    mul(ls, l, mid, x, y, k);
    mul(rs, mid+1, r, x, y, k);
    up(root);
}

LL query(LL root, LL l, LL r, LL x, LL y)
{
    if(l>y || r<x) return 0;
    if(l>=x && r<=y) return sum[root];
    down(root, l, r);
    return (query(ls, l, mid, x, y)+query(rs, mid+1, r, x, y))%p;
}

int main()
{
    scanf("%lld%lld%lld", &n, &m, &p);
    build(1, 1, n);
    for(int i=1; i<=m; ++i)
    {
        //add(1, 1, n, x, y, k) x~y 区间加 k
        //mul(1, 1, n, x, y, k) x~y 区间乘 k
        //query(1, 1, n, x, y) x~y 区间和
    }
}