#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 500005
#define P 998244353
#define INF 1e18
#define rint register int
#define LL long long
#define LD long double
#define ls (root<<1)
#define rs (root<<1|1)
#define mid ((l+r)>>1)
using namespace std;

int n, q, id, in[MAXN], out[MAXN];
LL val[MAXN*4], tag[MAXN*4], ans[MAXN], dis[MAXN];

struct Ask
{
    int l, r, id;
    Ask(int a=0, int b=0, int c=0)
    {
        l=a, r=b, id=c;
    }
};

vector< pair<int, int> > vec[MAXN];
vector<Ask> ask[MAXN];

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

void update(int root, int l, int r, int x, int y, LL k)
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

LL query(int root, int l, int r, int x, int y)
{
    if(l>y || r<x) return INF;
    if(l>=x && r<=y) return val[root];
    down(root, l, r);
    return min(query(ls, l, mid, x, y), query(rs, mid+1, r, x, y));
}

void dfs1(int x, int fa)
{
    in[x]=++id;
    if(!vec[x].size()) update(1, 1, n, id, id, dis[x]);
    else update(1, 1, n, id, id, INF);
    for(rint i=0; i<vec[x].size(); ++i)
    {
        int to=vec[x][i].first, d=vec[x][i].second;
        if(to==fa) continue;
        dis[to]=dis[x]+d;
        dfs1(to, x);
    }
    out[x]=id;
}

void dfs2(int x, int fa)
{
    for(rint i=0; i<ask[x].size(); ++i)
    {
        Ask now=ask[x][i];
        ans[now.id]=query(1, 1, n, now.l, now.r);
    }
    for(rint i=0; i<vec[x].size(); ++i)
    {
        int to=vec[x][i].first, d=vec[x][i].second;
        if(to==fa) continue;
        update(1, 1, n, in[to], out[to], -d);
        update(1, 1, n, 1, in[to]-1, d);
        update(1, 1, n, out[to]+1, n, d);
        dfs2(to, x);
        update(1, 1, n, in[to], out[to], d);
        update(1, 1, n, 1, in[to]-1, -d);
        update(1, 1, n, out[to]+1, n, -d);
    }
}

int main()
{
    scanf("%d%d", &n, &q);
    for(rint i=2, p, w; i<=n; ++i)
    {
        scanf("%d%d", &p, &w);
        vec[p].push_back(make_pair(i, w));
    }
    for(rint i=1; i<=n; ++i) sort(vec[i].begin(), vec[i].end());
    for(rint i=1; i<=q; ++i)
    {
        int x, l, r;
        scanf("%d%d%d", &x, &l, &r);
        ask[x].push_back(Ask(l, r, i));
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for(rint i=1; i<=q; ++i) printf("%lld\n", ans[i]);
    return 0;
}
