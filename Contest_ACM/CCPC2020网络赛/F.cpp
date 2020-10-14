#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 505
#define MAXM 2005
#define P
#define INF 0x3f3f3f3f
using namespace std;

int t, n, k[MAXN], a[MAXN][MAXM], b[MAXN][MAXM], c[MAXN][MAXM], d[MAXN][MAXM];
int id, tot, vis[MAXM], deg[MAXN];

vector<pair<int, int> > vec[MAXN];
queue<int> q;

bool check()
{
    if(vec[n].size()!=id*2) return false;
    for(int i=0; i<vec[n].size(); ++i)
    {
        int id=vec[n][i].first, val=vec[n][i].second;
        if(vis[id]==-1) vis[id]=val;
        else if(vis[id]!=val) return false;
    }
    return true;
}

int main()
{
    scanf("%d", &t);
    for(int qwq=1; qwq<=t; ++qwq)
    {
        scanf("%d", &n);
        id=0;
        memset(vis, -1, sizeof(vis));
        for(int i=1; i<=n; ++i)
        {
            deg[i]=0;
            vec[i].clear();
        }
        for(int i=1; i<n; ++i)
        {
            scanf("%d", &k[i]);
            tot+=k[i];
            for(int j=0; j<k[i]; ++j) scanf("%d%d%d%d", &c[i][j], &b[i][j], &d[i][j], &a[i][j]);
            scanf("%d%d%d", &c[i][k[i]], &b[i][k[i]], &d[i][k[i]]);
            for(int j=0; j<k[i]; ++j)
            {
                id++;
                vec[d[i][j]].push_back(make_pair(id, c[i][j]*a[i][j]+b[i][j]));
                vec[d[i][j+1]].push_back(make_pair(id, c[i][j+1]*a[i][j]+b[i][j+1]));
            }
            for(int j=0; j<=k[i]; ++j) deg[d[i][j]]++;
        }
        for(int i=1; i<=n; ++i)
            if(!deg[i]) q.push(i);
        while(!q.empty())
        {
            int x=q.front(); q.pop();
            for(int i=0; i<=k[x]; ++i)
            {
                deg[d[x][i]]--;
                if(!deg[d[x][i]]) q.push(d[x][i]);
            }
            for(int i=0; i<vec[x].size(); ++i)
            {
                int id=vec[x][i].first, val=vec[x][i].second;
                int pos=lower_bound(a[x], a[x]+k[x], val)-a[x];
                vec[d[x][pos]].push_back(make_pair(id, val*c[x][pos]+b[x][pos]));
            }
        }
        if(check()) printf("Case #%d: YES\n", qwq);
        else printf("Case #%d: NO\n", qwq);
    }
    return 0;
}