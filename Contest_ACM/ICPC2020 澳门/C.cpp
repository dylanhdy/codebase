#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#define LL long long
#define LD long double
#define MAXN 100004
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, tot, n, flag, ans[MAXN], w[MAXN], siz[MAXN*30], t[MAXN*30][2];

vector<int> vec[MAXN*30];

void insert(int x, int id)
{
    int p=1;
    for(int i=29; i>=0; --i) {
        int ch=((x>>i)&1);
        if(!t[p][ch]) t[p][ch]=++tot;
        vec[p].PB(id);
        p=t[p][ch];
    }
    vec[p].PB(id);
}

#define ls t[x][0]
#define rs t[x][1]
#define fi first
#define se second

bool CMP(pair<int,int> x, pair<int,int> y)
{
    return (w[x.fi]^w[x.se])<(w[y.fi]^w[y.se]);
}

void dfs(int x)
{
    if(!ls && !rs && vec[x].size()>2) {flag=0; return;}
    if(ls) {
        if(vec[ls].size()<=2)
            for(int i=0; i<vec[ls].size(); ++i) ans[vec[ls][i]]=i;
        else dfs(ls);
    }
    if(rs) {
        if(vec[rs].size()<=2)
            for(int i=0; i<vec[rs].size(); ++i) ans[vec[rs][i]]=i;
        else dfs(rs);
    }
    
    if(ls && rs && vec[ls].size()<=2 && vec[rs].size()<=2) {
        vector<pair<int,int>> vp;
        for(int el: vec[ls])
            for(int er: vec[rs]) vp.PB(MP(el, er));
        sort(vp.begin(), vp.end(), CMP);
        if(ans[vp[0].fi]==ans[vp[0].se])
            for(int er: vec[rs]) ans[er]^=1;
        for(auto pi :vp)
            if(ans[pi.fi]==ans[pi.se]) ans[0]=min(ans[0], w[pi.fi]^w[pi.se]);
    }
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        for(int i=1; i<=tot; ++i) {
            siz[i]=t[i][0]=t[i][1]=0;
            vec[i].clear();
        }
        flag=tot=1; ans[0]=(1<<30);

        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &w[i]);
            insert(w[i], i);
        }
        dfs(1);
        if(!flag) {
            printf("0\n");
            for(int i=1; i<=n; ++i) printf("1");
            printf("\n");
        } else {
            printf("%d\n", ans[0]);
            for(int i=1; i<=n; ++i) printf("%d", ans[i]+1);
            printf("\n");
        }
    }
    return 0;
}