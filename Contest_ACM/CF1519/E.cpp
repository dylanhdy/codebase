#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 4000005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
#define pll pair<LL, LL>
using namespace std;

int n, cnt, vis1[MAXN], vis2[MAXN];
LL a, b, c, d;

map<pll, int> mp;
vector<pll> g[MAXN], ans;

int dfs(int x, int fa)
{
    vis1[x]=1;
    for(int i=0; i<g[x].size(); ++i) {
        int to=g[x][i].first;
        if(!vis1[to]) dfs(to, x);
    }
    int from=0, last=0;
    for(int i=0; i<g[x].size(); ++i) {
        int to=g[x][i].first, id=g[x][i].second;
        if(to==fa) {
            from=id;
            continue;
        }
        if(!vis2[id]) {
            if(last) {
                vis2[last]=vis2[id]=1;
                ans.PB(MP(last, id));
                last=0;
            } else last=id;
        }
    }
    if(last && from) {
        vis2[last]=vis2[from]=1;
        ans.PB(MP(last, from));
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        LL up1=c*b, down1=(a+b)*d, gcd1=__gcd(up1, down1);
        pll p1=MP(up1/gcd1, down1/gcd1);
        if(!mp[p1]) mp[p1]=++cnt;
        LL up2=(c+d)*b, down2=a*d, gcd2=__gcd(up2, down2);
        pll p2=MP(up2/gcd2, down2/gcd2);
        if(!mp[p2]) mp[p2]=++cnt;
        //printf("%d %d %d %d %d!!\n", i, p1.first, p1.second, p2.first, p2.second);
        int x=mp[p1], y=mp[p2];
        g[x].PB(MP(y, i));
        g[y].PB(MP(x, i));
    }
    for(int i=1; i<=cnt; ++i)
        if(!vis1[i]) dfs(i, 0);
    printf("%d\n", ans.size());
    for(int i=0; i<ans.size(); ++i)
        printf("%lld %lld\n", ans[i].first, ans[i].second);
    return 0;
}