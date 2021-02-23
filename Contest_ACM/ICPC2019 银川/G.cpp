#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define ls (root<<1)
#define rs (root<<1|1)
#define mid ((l+r)>>1)
using namespace std;

const int num[4]={2, 3, 5, 7};

int n, q, x, y, z;
char op[10];

struct Segtree
{
    int val[MAXN<<2], tag[MAXN<<2];

    void up(int root)
    {
        val[root]=max(val[ls], val[rs]);
    }

    void down(int root)
    {
        if(!tag[root]) return;
        val[ls]+=tag[root];
        val[rs]+=tag[root];
        tag[ls]+=tag[root];
        tag[rs]+=tag[root];
        tag[root]=0;
    }

    void update(int root, int l, int r, int x, int y, int k)
    {
        if(l>y || r<x) return;
        if(l>=x && r<=y)
        {
            tag[root]+=k;
            val[root]+=k;
            return;
        }
        down(root);
        update(ls, l, mid, x, y, k);
        update(rs, mid+1, r, x, y, k);
        up(root);
    }

    int query(int root, int l, int r, int x, int y)
    {
        if(l>y || r<x) return 0;
        if(l>=x && r<=y) return val[root];
        down(root);
        return max(query(ls, l, mid, x, y), query(rs, mid+1, r, x, y));
    }
} t[4];

int main()
{
    scanf("%d%d", &n, &q);
    for(int i=1; i<=q; ++i)
    {
        scanf("%s", op);
        if(op[1]=='U')
        {
            scanf("%d%d%d", &x, &y, &z);
            for(int j=0; j<4; ++j)
            {
                int k=0;
                while(z%num[j]==0) z/=num[j], k++;
                if(k) t[j].update(1, 1, n, x, y, k);
            }
        }
        else
        {
            int ans=0;
            scanf("%d%d", &x, &y);
            for(int j=0; j<4; ++j)
                ans=max(ans, t[j].query(1, 1, n, x, y));
            printf("ANSWER %d\n", ans);
        }
    }
    return 0;
}