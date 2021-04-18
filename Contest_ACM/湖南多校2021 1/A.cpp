#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 20005
#define MAXM 70005
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, t, nump, taxi, p[20], vis[MAXN], dis[MAXN][20], g[MAXM][20], f[MAXM][20];

struct Node {
    int id, dis;
    bool friend operator < (Node x, Node y) {
        return x.dis>y.dis;
    }
};

priority_queue<Node> q;
vector<int> g1[MAXN], g2[MAXN];

void dijskra(int s, int id)
{
    memset(dis[id], 0x3f, sizeof(dis[id]));
    memset(vis, 0, sizeof(vis));
    dis[id][s]=0;
    q.push(Node{s, 0});
    while(!q.empty()) {
        int x=q.top().id; q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=0; i<g1[x].size(); ++i) {
            int to=g1[x][i];
            if(dis[id][to]>dis[id][x]+g2[x][i]) {
                dis[id][to]=dis[id][x]+g2[x][i];
                q.push(Node{to, dis[id][to]});
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d%d", &n, &nump, &m, &t, &taxi);
    for(int i=1; i<=nump; ++i) {
        int temp;
        scanf("%d%d", &p[i], &temp);
        t-=temp;
    }
    for(int i=1; i<=m; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g1[x].PB(y); g2[x].PB(z);
        g1[y].PB(x); g2[y].PB(z);
    }
    for(int i=0; i<=nump; ++i) dijskra(p[i], i);
    memset(f, 0x3f, sizeof(f));
    f[1][0]=0;
    for(int sta=1; sta<(1<<(nump+1)); ++sta) {
        for(int j=0; j<=nump; ++j) {
            if(!((sta>>j)&1) || f[sta][j]==INF) continue;
            for(int k=0; k<=nump; ++k) {
                if((sta>>k)&1) continue;
                int nsta=(sta|(1<<k));
                if(f[nsta][k]==f[sta][j]+dis[j][p[k]])
                    g[nsta][k]=max(g[nsta][k], max(g[sta][j], dis[j][p[k]]));
                if(f[nsta][k]>f[sta][j]+dis[j][p[k]]) {
                    f[nsta][k]=f[sta][j]+dis[j][p[k]];
                    g[nsta][k]=max(g[sta][j], dis[j][p[k]]);
                }
                /*
                if(f[lsta][k]+dis[k][p[j]]==f[sta][j])
                    g[sta][j]=max(g[sta][j], max(g[lsta][k], dis[k][p[j]]));
                if(f[lsta][k]+dis[k][p[j]]<f[sta][j]) {
                    g[sta][j]=max(g[lsta][k], dis[k][p[j]]);
                    f[sta][j]=f[lsta][k]+dis[k][p[j]];
                }*/
            }
        }
    }

    int tsta=(1<<(nump+1))-1;
    for(int i=1; i<=nump; ++i) {
        f[tsta][i]+=dis[i][0];
        g[tsta][i]=max(g[tsta][i], dis[i][0]);
    }
    for(int i=1; i<=nump; ++i)
        if(f[tsta][i]<=t) {
            printf("possible without taxi");
            return 0;
        }
    for(int i=1; i<=nump; ++i)
        if(f[tsta][i]-g[tsta][i]+taxi<=t) {
            printf("possible with taxi");
            return 0;
        }
    printf("impossible");
    return 0;
}