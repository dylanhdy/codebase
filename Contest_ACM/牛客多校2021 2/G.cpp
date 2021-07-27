#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#define LL long long
#define LD long double
#define MAXN 5005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, k, ans, f[MAXN][MAXN], g[MAXN];

struct A {int l, r;} a[MAXN];

vector<A> vec1, vec2;
vector<int> sta1, sta2;

bool CMP1(A x, A y)
{
    if(x.r==y.r) return x.l>y.l;
    return x.r<y.r;
}

bool CMP2(A x, A y)
{
    return x.r-x.l>y.r-y.l;
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i) scanf("%d%d", &a[i].l, &a[i].r);
    sort(a+1, a+n+1, CMP1);
    for(int i=1; i<=n; ++i) {
        if(vec1.empty() || vec1.back().l<a[i].l) vec1.PB(a[i]);
        else vec2.PB(a[i]);
    }
    m=vec1.size();
    memset(f, -0x3f, sizeof(f));
    f[0][0]=0;
    for(int i=1; i<=k; ++i) {
        sta1.clear(), sta2.clear();
        for(int j=1, lim=0; j<=m; ++j) {
            f[i][j]=f[i-1][j-1]+vec1[j-1].r-vec1[j-1].l;
            while(lim<sta1.size() && sta2[lim]<=vec1[j-1].l) lim++;
            if(lim<sta1.size()) f[i][j]=max(f[i][j], sta1[lim]-vec1[j-1].l);

            while(sta1.size()>lim && sta1.back()<=f[i-1][j-1]+vec1[j-1].r)
                sta1.pop_back(), sta2.pop_back();
            sta1.PB(f[i-1][j-1]+vec1[j-1].r), sta2.PB(vec1[j-1].r);
            //printf("%d %d %d\n", i, j, f[i][j]);
        }
    }
    sort(vec2.begin(), vec2.end(), CMP2);
    ans=max(0, f[k][m]);
    for(int i=1; i<=min(k, (int)vec2.size()); ++i) {
        g[i]=g[i-1]+vec2[i-1].r-vec2[i-1].l;
        ans=max(ans, g[i]+f[k-i][m]);
    }
    printf("%d\n", ans);
    return 0;
}