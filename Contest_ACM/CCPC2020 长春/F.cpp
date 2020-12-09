#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, a[MAXN], siz[MAXN], id[MAXN];
LL ans;

struct State {int a[20][2];} sta;

map<int, State> mp[MAXN];
map<int, State>::iterator it;
vector<int> g[MAXN];

void dfs(int x, int fa)
{
    int maxson=0;
    siz[x]=1;
    for(int i=0; i<g[x].size(); ++i)
    {
        int to=g[x][i];
        if(to==fa) continue;
        dfs(to, x);
        siz[x]+=siz[to];
        if(siz[to]>siz[maxson]) maxson=to;
    }
    if(maxson) id[x]=id[maxson];
    for(int i=0; i<20; ++i) mp[id[x]][a[x]].a[i][(x>>i)&1]++;
    for(int i=0; i<g[x].size(); ++i)
    {
        int to=g[x][i];
        if(to==fa || to==maxson) continue;
        for(it=mp[id[to]].begin(); it!=mp[id[to]].end(); ++it)
        {
            int val=a[x]^it->first;
            if(mp[id[x]].find(val)==mp[id[x]].end()) continue;
            for(int j=0; j<20; ++j)
            {
                LL temp=0;
                temp+=1LL*mp[id[x]][val].a[j][0]*it->second.a[j][1];
                temp+=1LL*mp[id[x]][val].a[j][1]*it->second.a[j][0];
                ans+=(1LL<<j)*temp;
            }
        }
        for(it=mp[id[to]].begin(); it!=mp[id[to]].end(); ++it)
        {
            int val=it->first;
            for(int j=0; j<20; ++j)
            {
                mp[id[x]][val].a[j][0]+=it->second.a[j][0];
                mp[id[x]][val].a[j][1]+=it->second.a[j][1];
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        id[i]=i;
    }
    for(int i=1; i<n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].PB(y);
        g[y].PB(x);
    }
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}