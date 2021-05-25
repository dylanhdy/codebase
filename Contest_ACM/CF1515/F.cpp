#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 300005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, f[MAXN];
LL sum, val, a[MAXN];

vector<pair<int, int> > *g[MAXN];
priority_queue<pair<LL, int> > q;

int find(int x)
{
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}

int main()
{
    scanf("%d%d%lld", &n, &m, &val);
    for(int i=1; i<=n; ++i) {
        scanf("%lld", &a[i]);
        q.push(MP(a[i], i));
        sum+=a[i];
        f[i]=i;
        g[i]=new vector<pair<int, int> >;
    }
    for(int i=1; i<=m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x]->PB(MP(y, i)), g[y]->PB(MP(x, i));
    }
    if(sum<1LL*val*(n-1)) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    while(!q.empty()) {
        int x=q.top().second; q.pop();
        if(find(x)!=x) continue;
        while(!g[x]->empty()) {
            int to=find(g[x]->back().first);
            int num=g[x]->back().second;
            g[x]->pop_back();
            if(to==x) continue;
            printf("%d\n", num);
            a[x]+=a[to]-val, f[to]=x;
            q.push(MP(a[x], x));
            if(g[to]->size()>g[x]->size()) {
                for(auto e: *g[x]) g[to]->PB(e);
                delete g[x];
                g[x]=g[to];
            } else {
                for(auto e: *g[to]) g[x]->PB(e);
            }
            break;
        }
    }
    return 0;
}