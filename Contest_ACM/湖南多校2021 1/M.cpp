#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 50005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 1e18
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, t, a[MAXN], vis[MAXN];
LL dis[MAXN];

struct Node {
    int id;
    LL dis;
    bool friend operator < (Node x, Node y) {
        return x.dis>y.dis;
    }
}node;

priority_queue<Node> q;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    m=a[1];
    for(int i=1; i<m; ++i) dis[i]=INF;
    q.push(Node{0, 0});
    while(!q.empty()) {
        int x=q.top().id; q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=2; i<=n; ++i) {
            int to=(x+a[i])%m;
            if(dis[to]>dis[x]+a[i])  {
                dis[to]=dis[x]+a[i];
                q.push(Node{to, dis[to]});
            }
        }
    }
    //for(int i=0; i<m; ++i) printf("%d %d\n", i, dis[i]);
    scanf("%d", &t);
    while(t--) {
        int temp;
        scanf("%d", &temp);
        if(dis[temp%m]<=temp) printf("TAK\n");
        else printf("NIE\n");
    }
    return 0;
}