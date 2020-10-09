#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 200005
#define ls (root<<1)
#define rs (root<<1|1)
#define mid ((l+r)>>1)
using namespace std;

struct Segment {int l, r, col;} seg[MAXN];
struct Tree
{
    int val[MAXN*8], tag[MAXN*8];

    void up(int root)
    {
        val[root]=max(val[ls], val[rs]);
    }

    void down(int root, int l, int r)
    {
        if(!tag[root]) return;
        tag[ls]+=tag[root];
        tag[rs]+=tag[root];
        val[ls]+=tag[root];
        val[rs]+=tag[root];
        tag[root]=0;
    }

    void update(int root, int l, int r, int x, int y, int k)
    {
        if(l>y || r<x) return;
        if(l>=x && r<=y)
        {
            val[root]+=k;
            tag[root]+=k;
            return;
        }
        down(root, l, r);
        update(ls, l, mid, x, y, k);
        update(rs, mid+1, r, x, y, k);
        up(root);
    }

    int query(int root, int l, int r, int x, int y)
    {
        if(l>y || r<x) return 0;
        if(l>=x && r<=y) return val[root];
        down(root, l, r);
        return max(query(ls, l, mid, x, y), query(rs, mid+1, r, x, y));
    }
}t[2];

int n, cnt, temp[MAXN*2];

bool CMP(Segment x, Segment y)
{
    if(x.r==y.r) return x.l<y.l;
    else return x.r<y.r;
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d%d", &seg[i].l, &seg[i].r, &seg[i].col);
        temp[i]=seg[i].l, temp[i+n]=seg[i].r;
    }
    sort(temp+1, temp+2*n+1);
    cnt=unique(temp+1, temp+2*n+1)-temp-1;
    for(int i=1; i<=n; ++i)
    {
        seg[i].l=lower_bound(temp+1, temp+cnt+1, seg[i].l)-temp;
        seg[i].r=lower_bound(temp+1, temp+cnt+1, seg[i].r)-temp;
        seg[i].col--;
    }
    sort(seg+1, seg+n+1, CMP);
    for(int i=1, j=1; i<=seg[n].r; ++i)
    {
        if(i>1)
        {
            t[0].update(1, 1, cnt, i, i, t[1].query(1, 1, cnt, 1, i-1));
            t[1].update(1, 1, cnt, i, i, t[0].query(1, 1, cnt, 1, i-1));
        }
        while(seg[j].r==i)
        {
            t[seg[j].col].update(1, 1, cnt, 1, seg[j].l, 1);
            j++;
        }
    }
    printf("%d\n", max(t[0].query(1, 1, cnt, 1, cnt), t[1].query(1, 1, cnt, 1, cnt)));
    return 0;
}