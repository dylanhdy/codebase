#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 150010
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define pil pair<int, LL>
using namespace std;

int n, Q, p, up, down, cnt, head[MAXN], w[MAXN];
int root, top, son[MAXN], f[MAXN], vis[MAXN];
LL ans;

struct Edge {int next, to, dis;} edge[MAXN*2];
struct Node
{
    int root, son, dis;
    Node(int a=0, int b=0, int c=0)
    {
        root=a, son=b, dis=c;
    }
} a[MAXN][22];

vector<pil> vec[MAXN][3];
pil q[MAXN];

void addedge(int from, int to, int dis)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].dis=dis;
    head[from]=cnt;
}

void find(int x, int fa, int siz)
{
    son[x]=1, f[x]=0;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa || vis[to]) continue;
        find(to, x, siz);
        son[x]+=son[to];
        f[x]=max(f[x], son[to]);
    }
    f[x]=max(f[x], siz-son[x]);
    if(root<0 || f[x]<f[root]) root=x;
}

void dfs(int x, int fa, int son, int dis, int d)
{
    a[x][d]=Node(root, son, dis);
    //printf("%d %d %d!\n", x, root, d);
    q[++top]=make_pair(w[x], dis);
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa || vis[to]) continue;
        dfs(to, x, son, dis+edge[i].dis, d);
    }
}

void divide(int x, int d, int siz)
{
    vis[x]=1;
    a[x][d].root=x;
    for(rint i=head[x], id=0; i; i=edge[i].next, id++)
    {
        int to=edge[i].to;
        if(vis[to]) continue;
        top=0;
        dfs(to, x, to, edge[i].dis, d);
        sort(q+1, q+top+1);
        for(rint i=1; i<=top; ++i) vec[x][id].push_back(q[i]);
    }
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(vis[to]) continue;
        root=-1;
        int temp=son[to]>son[x]?siz-son[x]:son[to];
        find(to, x, temp);
        divide(root, d+1, temp);
    }
}

pil ask(vector<pil> &a, int l, int r)
{
    int lpos, rpos;
    lpos=lower_bound(a.begin(), a.end(), pil(l-1, 1e18))-a.begin()-1;
    rpos=lower_bound(a.begin(), a.end(), pil(r, 1e18))-a.begin()-1;
    return make_pair(rpos-lpos, a[rpos].second-a[lpos].second);
}

LL solve(int x, int l, int r)
{
    LL ans=0;
    //printf("%d %d!!!\n", x, a[x][1].root);
    for(rint i=1; a[x][i].root; ++i)
    {
        int root=a[x][i].root, son=a[x][i].son, dis=a[x][i].dis;
        //printf("%d %d %d %d!!!\n", x, root, son, dis);
        for(rint j=head[root], id=0; j; j=edge[j].next, id++)
        {
            int to=edge[j].to;
            if(to==son) continue;
            pil temp=ask(vec[root][id], l, r);
            ans+=temp.second+1LL*dis*temp.first;
        }
        if(w[root]>=l && w[root]<=r) ans+=dis;
    }
    return ans;
}

int main()
{
    scanf("%d%d%d", &n, &Q, &p);
    for(rint i=1; i<=n; ++i) scanf("%d", &w[i]);
    for(rint i=1, x, y, z; i<n; ++i)
    {
        scanf("%d%d%d", &x, &y, &z);
        addedge(x, y, z);
        addedge(y, x, z);
    }
    root=-1;
    find(1, 0, n);
    divide(root, 1, n);
    for(rint i=1; i<=n; ++i)
        for(rint j=0; j<3; ++j)
        {
            vec[i][j].insert(vec[i][j].begin(), pil(-1, 0));
            for(rint k=1; k<vec[i][j].size(); ++k)
                vec[i][j][k].second+=vec[i][j][k-1].second;
        }
    while(Q--)
    {
        int x, a, b, l, r;
        scanf("%d%d%d", &x, &a, &b);
        l=min((a+ans)%p, (b+ans)%p);
        r=max((a+ans)%p, (b+ans)%p);
        ans=solve(x, l, r);
        printf("%lld\n", ans);
    }
    return 0;
}
