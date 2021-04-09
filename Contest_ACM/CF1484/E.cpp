#include <cstdio>
#include <algorithm>
#include <stack>
#define LL long long
#define LD long double
#define MAXN 300005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 1e18
#define dbg(a...) fprintf(stderr, a)
#define mid ((l+r)>>1)
#define ls (root<<1)
#define rs (root<<1|1)
using namespace std;

int n, h[MAXN], b[MAXN];
LL t[MAXN<<2], tag[MAXN<<2], f[MAXN];

stack<int> stah, stap, stab;

void down(int root)
{
    tag[ls]+=tag[root];
    tag[rs]+=tag[root];
    t[ls]+=tag[root];
    t[rs]+=tag[root];
    tag[root]=0;
}

void update(int root, int l, int r, int x, int y, LL k)
{
    if(l>y || r<x) return;
    if(l>=x && r<=y) {
        tag[root]+=k;
        t[root]+=k;
        return;
    }
    down(root);
    update(ls, l, mid, x, y, k);
    update(rs, mid+1, r, x, y, k);
    t[root]=max(t[ls], t[rs]);
}

LL query(int root, int l, int r, int x, int y)
{
    if(l>y || r<x) return -INF;
    if(l>=x && r<=y) return t[root];
    down(root);
    return max(query(ls, l, mid, x, y), query(rs, mid+1, r, x, y));
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &h[i]);
    for(int i=1; i<=n; ++i) scanf("%d", &b[i]);
    for(int i=1; i<=n; ++i) {
        int last=i;
        while(!stah.empty() && stah.top()>h[i]) {
            update(1, 1, n, stap.top(), last-1, b[i]-stab.top());
            last=stap.top();
            stah.pop(); stap.pop(); stab.pop();
        }
        stah.push(h[i]);
        stap.push(last);
        stab.push(b[i]);
        update(1, 1, n, i, i, b[i]);
        f[i]=query(1, 1, n, 1, i);
        update(1, 1, n, i+1, i+1, f[i]);
    }
    printf("%lld\n", f[n]);
    return 0;
}