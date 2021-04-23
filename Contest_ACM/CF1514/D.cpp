#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 300005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
#define ls (root<<1)
#define rs (root<<1|1)
#define mid ((l+r)/2)
using namespace std;

int n, q, a[MAXN], t[MAXN<<2];

vector<int> vec[MAXN];

void build(int root, int l, int r)
{
    if(l==r) {
        t[root]=a[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid+1, r);
    int t1=upper_bound(vec[t[ls]].begin(), vec[t[ls]].end(), r)-vec[t[ls]].begin();
    int t2=upper_bound(vec[t[ls]].begin(), vec[t[ls]].end(), l-1)-vec[t[ls]].begin();
    int t3=upper_bound(vec[t[rs]].begin(), vec[t[rs]].end(), r)-vec[t[rs]].begin();
    int t4=upper_bound(vec[t[rs]].begin(), vec[t[rs]].end(), l-1)-vec[t[rs]].begin();
    if(t1-t2>=t3-t4) t[root]=t[ls];
    else t[root]=t[rs];
}

int query(int root, int l, int r, int x, int y)
{
    if(l>y || r<x) return 0;
    if(l>=x && r<=y) {
        int t1=upper_bound(vec[t[root]].begin(), vec[t[root]].end(), y)-vec[t[root]].begin();
        int t2=upper_bound(vec[t[root]].begin(), vec[t[root]].end(), x-1)-vec[t[root]].begin();
        //printf("%d %d %d %d\n", x, y, t[root], t1-t2);
        return t1-t2;
    }
    return max(query(ls, l, mid, x, y), query(rs, mid+1, r, x, y));
}

int main()
{
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        vec[a[i]].PB(i);
    }
    build(1, 1, n);
    while(q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        int temp=query(1, 1, n, l, r), len=r-l+1;
        printf("%d\n", max(0, temp*2-len-1)+1);
    }
    return 0;
}