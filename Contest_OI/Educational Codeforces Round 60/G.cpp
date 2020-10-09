#pragma G++ optimize("-O2")
#pragma G++ optimize("-Ofast")
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 1000005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define il inline
#define pii pair<int, int>
#define ls (root<<1)
#define rs (root<<1|1)
#define mid ((l+r)>>1)
using namespace std;

il void read(int &x)
{
    x=0; char ch=getchar();
    while(ch<'0' || ch>'9') ch=getchar();
    while(ch>='0' && ch<='9') x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
}

int n, q, l[MAXN], r[MAXN], nxt[MAXN], pre[MAXN], v1[MAXN<<2];
LL ans[MAXN], v2[MAXN<<2];

struct A {int id, num;} p[MAXN];

set<int> st;
set<int>::iterator it;
vector<pii> vl[MAXN], vr[MAXN];

il bool CMP(A x, A y) {return x.num>y.num;}

il void down(int root)
{
    v1[ls]+=v1[root];
    v1[rs]+=v1[root];
    v2[ls]+=v2[root];
    v2[rs]+=v2[root];
    v1[root]=v2[root]=0;
}

void update(int root, int l, int r, int x, int y, int k1, int k2)
{
    if(l>y || r<x) return;
    if(l>=x && r<=y)
    {
        v1[root]+=k1, v2[root]+=k2;
        return;
    }
    down(root);
    update(ls, l, mid, x, y, k1, k2);
    update(rs, mid+1, r, x, y, k1, k2);
}

LL query(int root, int l, int r, int x)
{
    if(l==r) return 1LL*v1[root]*x+v2[root];
    down(root);
    if(x<=mid) return query(ls, l, mid, x);
    else return query(rs, mid+1, r, x);
}

int main()
{
    read(n); read(q);
    for(rint i=1; i<=n; ++i) read(p[i].num), p[i].id=i;
    sort(p+1, p+n+1, CMP);
    st.insert(0), st.insert(n+1);
    for(rint i=1; i<=n; ++i)
    {
        it=st.lower_bound(p[i].id);
        nxt[p[i].id]=*it;
        it--;
        pre[p[i].id]=*it;
        st.insert(p[i].id);
    }
    for(rint i=1; i<=q; ++i) read(l[i]);
    for(rint i=1; i<=q; ++i)
    {
        read(r[i]);
        vl[l[i]-1].push_back(make_pair(r[i], i));
        vr[r[i]].push_back(make_pair(l[i], i));
    }
    //for(rint i=1; i<=n; ++i) printf("%d %d %d!!!\n", i, pre[i], nxt[i]);
    for(rint i=1; i<=n; ++i)
    {
        if(pre[i]>=1) update(1, 1, n, 1, pre[i], 0, pre[i]);
        if(nxt[i]<=n) update(1, 1, n, nxt[i], n, 0, nxt[i]-1);
        update(1, 1, n, pre[i]+1, nxt[i]-1, 1, 0);
        for(rint j=0; j<vl[i].size(); ++j)
        {
            LL t1=query(1, 1, n, vl[i][j].first);
            LL t2=query(1, 1, n, i);
            //printf("1:%d %d %d %lld %lld!!!\n", i, vl[i][j].first, vl[i][j].second, t1, t2);
            ans[vl[i][j].second]-=(t1-t2);
        }
        for(rint j=0; j<vr[i].size(); ++j)
        {
            LL t1=query(1, 1, n, i);
            LL t2=query(1, 1, n, vr[i][j].first-1);
            ans[vr[i][j].second]+=(t1-t2);
            //printf("2:%d %d %d %lld %lld!!!\n", i, vr[i][j].first, vr[i][j].second, t1, t2);
        }
    }
    for(rint i=1; i<=q; ++i) printf("%lld ", ans[i]);
    return 0;
}
