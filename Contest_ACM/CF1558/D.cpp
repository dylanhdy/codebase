#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <set>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
#define mid ((l+r)/2)
#define ls (rt<<1)
#define rs (rt<<1|1)
using namespace std;

int T, n, m, x[MAXN], y[MAXN], fac[MAXN*2], ifac[MAXN*2], t[MAXN*4];

void init(int lim)
{
    ifac[0]=ifac[1]=fac[0]=fac[1]=1;
    for(int i=2; i<=lim; i++) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=lim; i++) {
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
        fac[i]=1LL*fac[i-1]*i%P;
    }
}

int comb(int x, int y)
{
    if(y>x) return 0;
    return 1LL*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

void update(int rt, int l, int r, int x, int k)
{
    if(l==r) {
        t[rt]=k;
        return;
    }
    if(x<=mid) update(ls, l, mid, x, k);
    else update(rs, mid+1, r, x, k);
    t[rt]=t[ls]+t[rs];
}

int query(int rt, int l, int r, int x)
{
    if(l==r) return l;
    int val=mid-l+1-t[ls];
    if(x<=val) return query(ls, l, mid, x);
    else return query(rs, mid+1, r, x-val);
}

int main()
{
    init(4e5);
    scanf("%d", &T);
    while(T--) {
        set<int> st;
        vector<int> vec;
        scanf("%d%d", &n, &m);
        for(int i=1; i<=m; ++i) scanf("%d%d", &x[i], &y[i]);
        for(int i=m; i>=1; --i) {
            int pos=query(1, 1, n, y[i]);
            update(1, 1, n, pos, 1);
            st.insert(pos);
            st.erase(pos+1);
            vec.PB(pos);
        }
        printf("%d\n", comb(2*n-1-st.size(), n));
        for(int e: vec) update(1, 1, n, e, 0);
    }
    return 0;
}