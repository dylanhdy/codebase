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
#define MAXN 200005
#define LL long long
#define PB push_back
#define MP make_pair
#define INF 1e18
using namespace std;

int n, m, ans, a[MAXN];
LL val[MAXN*4], tag[MAXN*4];
vector<pair<int, int> > vec;

void up(int root)
{
    val[root]=min(val[ls], val[rs]);
}

void down(int root, int l, int r)
{
    tag[ls]+=tag[root];
    tag[rs]+=tag[root];
    val[ls]+=tag[root];
    val[rs]+=tag[root];
    tag[root]=0;
}

void add(int root, int l, int r, int x, int y, int k)
{
    if(x>r || y<l) return;
    if(l>=x && r<=y)
    {
        val[root]+=k;
        tag[root]+=k;
        return;
    }
    down(root, l, r);
    add(ls, l, mid, x, y, k);
    add(rs, mid+1, r, x, y, k);
    up(root);
}

LL query(int root, int l, int r, int x, int y)
{
    if(l>y || r<x) return INF;
    if(l>=x && r<=y) return val[root];
    down(root, l, r);
    return min(query(ls, l, mid, x, y), query(rs, mid+1, r, x, y));
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        if(a[i]>=0) m++, ans++;
        if(a[i]<0 && m) vec.PB(MP(-a[i], -m));
    }
    for(int i=1, j=0; i<=n; ++i)
        if(a[i]>=0) {
            j++;
            add(1, 1, m, j, m, a[i]);
        }
    sort(vec.begin(), vec.end());
    for(auto e: vec) {
        //printf("%d %d %d??\n", -e.second, e.first, query(1, 1, m, -e.second, m));
        if(query(1, 1, m, -e.second, m)>=e.first) {
            ans++;
            add(1, 1, m, -e.second, m, -e.first);
        }
    }
    printf("%d\n", ans);
}