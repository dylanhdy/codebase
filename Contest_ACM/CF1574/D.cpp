#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#define LL unsigned long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
#define SEED 210011
using namespace std;

int n, m, c[11], b[11], a[11][MAXN];
map<LL, int> tag, vis;

struct Sta {
    int val, b[11];
    LL id;

    void cal()
    {
        val=id=0;
        for(int i=1; i<=n; ++i){
            val+=a[i][b[i]];
            id=id*SEED+b[i];
        }
    }

    bool friend operator < (Sta x, Sta y) {
        return x.val<y.val;
    }
};

priority_queue<Sta> q;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &c[i]);
        for(int j=1; j<=c[i]; ++j) scanf("%d", &a[i][j]);
    }
    scanf("%d", &m);
    for(int i=1; i<=m; ++i) {
        LL val=0;
        for(int j=1; j<=n; ++j) {
            scanf("%d", &b[j]);
            val=val*SEED+b[j];
        }
        tag[val]=1;
    }
    Sta tmp;
    for(int i=1; i<=n; ++i) tmp.b[i]=c[i];
    tmp.cal();
    q.push(tmp);
    while(!q.empty()) {
        LL val=q.top().id;
        for(int i=1; i<=n; ++i) tmp.b[i]=q.top().b[i];
        if(!tag[val]) {
            for(int i=1; i<=n; ++i) printf("%d ", tmp.b[i]);
            printf("\n");
            break;
        }
        q.pop();
        for(int i=1; i<=n; ++i) {
            tmp.b[i]--;
            tmp.cal();
            if(tmp.b[i] && !vis[tmp.id]) {
                vis[tmp.id]=1;
                q.push(tmp);
            }
            tmp.b[i]++;
        }
    }
    return 0;
}