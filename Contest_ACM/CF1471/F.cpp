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
using namespace std;

int T, n, m, num, vis[MAXN], tag[MAXN];

vector<int> vec, g[MAXN];
queue<int> q;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        vec.clear();
        num=0;
        for(int i=1; i<=n; ++i) {
            g[i].clear();
            vis[i]=tag[i]=0;
        }
        for(int i=1; i<=m; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x].PB(y);
            g[y].PB(x);
        }
        q.push(1);
        vis[1]=1;
        while(!q.empty()) {
            int x=q.front(); q.pop();
            num++;
            int flag=1;
            for(int i=0; i<g[x].size(); ++i) {
                int to=g[x][i];
                if(tag[to]) flag=0;
                if(!vis[to]) {
                    q.push(to);
                    vis[to]=1;
                }
            }
            if(flag) {
                tag[x]=1;
                vec.PB(x);
            }
        }
        if(num!=n) printf("NO\n");
        else {
            printf("YES\n%d\n", vec.size());
            for(int i=0; i<vec.size(); ++i) printf("%d ", vec[i]);
            printf("\n");
        }
    }
    return 0;
}