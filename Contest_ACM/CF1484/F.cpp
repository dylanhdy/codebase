#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 605
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, q, ans, vis[MAXN], tag[MAXN*MAXN];
LL dis1[MAXN][MAXN], dis2[MAXN][MAXN];

struct Edge {int x, y, z;} e[MAXN*MAXN];

vector<pair<int, int> > vec[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    memset(dis1, 0x3f, sizeof(dis1));
    memset(dis2, 0x3f, sizeof(dis2));
    for(int i=1; i<=n; ++i) dis1[i][i]=0;
    for(int i=1; i<=m; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        dis1[x][y]=min(dis1[x][y], (LL)z);
        dis1[y][x]=min(dis1[y][x], (LL)z);
        e[i]=Edge{x, y, z};
    }
    scanf("%d", &q);
    for(int i=1; i<=q; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        vec[x].PB(MP(y, z));
    }
    for(int k=1; k<=n; ++k)
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                dis1[i][j]=min(dis1[i][j], dis1[i][k]+dis1[k][j]);
    for(int i=1; i<=n; ++i) {
        if(!vec[i].size()) continue;
        memset(vis, 0, sizeof(vis));
        for(int j=0; j<vec[i].size(); ++j)
            dis2[i][vec[i][j].first]=-vec[i][j].second;
        for(int j=1; j<=n; ++j) {
            LL pos=0, maxd=dis1[0][0];
            for(int k=1; k<=n; ++k)
                if(!vis[k] && dis2[i][k]<maxd) {
                    pos=k;
                    maxd=dis2[i][k];
                }
            vis[pos]=1;
            for(int k=1; k<=n; ++k)
                dis2[i][k]=min(dis2[i][k], dis2[i][pos]+dis1[pos][k]);
        }
        for(int j=1; j<=m; ++j) {
            if(dis1[i][e[j].x]+e[j].z+dis2[i][e[j].y]<=0) tag[j]=1;
            if(dis1[i][e[j].y]+e[j].z+dis2[i][e[j].x]<=0) tag[j]=1;
        }
    }
    for(int i=1; i<=m; ++i)
        if(tag[i]) ans++;
    printf("%d\n", ans);
    return 0;
}