#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P
#define INF 0x3f3f3f3f
#define ls (root<<1)
#define rs (root<<1|1)
#define mid ((l+r)>>1)
using namespace std;

int n, sta[26][MAXN], num[26], nxt[MAXN], tag[MAXN<<2];
LL ans;
char s[MAXN];

void down(int root, int l, int r)
{
    tag[ls]+=tag[root];
    tag[rs]+=tag[root];
    tag[root]=0;
}

void update(int root, int l, int r, int x, int y)
{
    if(l>y || r<x) return;
    if(l>=x && r<=y)
    {
        tag[root]++;
        return;
    }
    down(root, l, r);
    update(ls, l, mid, x, y);
    update(rs, mid+1, r, x, y);
}

int query(int root, int l, int r, int x)
{
    if(l==r) return tag[root];
    down(root, l, r);
    if(x<=mid) return query(ls, l, mid, x);
    else return query(rs, mid+1, r, x);
}

int main()
{
    scanf("%d", &n);
    scanf("%s", s+1);
    for(int i=1; i<=n; ++i)
    {
        int val=s[i]-'a';
        sta[val][++num[val]]=n-i+1;
    }
    for(int i=1; i<=n; ++i)
    {
        int val=s[i]-'a';
        nxt[sta[val][num[val]--]]=i;
    }
    for(int i=1; i<=n; ++i)
    {
        ans+=query(1, 1, n, nxt[i])+nxt[i]-i;
        update(1, 1, n, 1, nxt[i]-1);
    }
    printf("%lld\n", ans);
    return 0;
}