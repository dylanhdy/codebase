#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 100005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, q, cnt, root, A[MAXN], siz[MAXN], son[MAXN], vis[MAXN], head[MAXN], ans[MAXN][2];

struct Edge {int next, to;} edge[MAXN*2];
struct Node
{
    int root, son, dis;
    Node(int _root=0, int _son=0, int _dis=0)
    {
        root=_root, son=_son, dis=_dis;
    }
} a[MAXN][20];

vector<int> sumval[MAXN], sumid[MAXN];

inline int add(int x, int y) {return x+y>P?x+y-P:x+y;}
inline int sub(int x, int y) {return x<y?x-y+P:x-y;}

void addedge(int from, int to)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    head[from]=cnt;
}

void find(int x, int fa, int all)
{
    siz[x]=1, son[x]=0;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa || vis[to]) continue;
        find(to, x, all);
        siz[x]+=siz[to], son[x]=max(son[x], siz[to]);
    }
    son[x]=max(son[x], all-siz[x]);
    if(son[x]<son[root]) root=x;
}

void dfs(int x, int fa, int dis, int son, int lev)
{
    a[x][lev]=Node(root, son, dis);
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa || vis[to]) continue;
        dfs(to, x, dis+1, son, lev); 
    }
}

void divide(int x, int lev, int all)
{
    vis[x]=1;
    int id=0;
    a[x][lev]=Node(root, ++id, 0);
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(!vis[to]) dfs(to, x, 1, ++id, lev);
    }
    sumval[x].resize(id+1), sumid[x].resize(id+1);
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(vis[to]) continue;
        root=0;
        int temp=siz[to]>siz[x]?all-siz[x]:siz[to];
        find(to, x, temp);
        divide(root, lev+1, temp);
    }
}

int main()
{
    freopen("sumsumsum.in", "r", stdin);
    freopen("sumsumsum.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for(rint i=1, x, y; i<n; ++i)
    {
        scanf("%d%d", &x, &y);
        addedge(x, y);
        addedge(y, x);
    }
    for(rint i=1; i<=n; ++i) scanf("%d", &A[i]);
    son[root=0]=INF;
    find(1, 0, n);
    divide(root, 1, n);
    for(rint i=1; i<=n; ++i)
    {
        for(rint j=1, x=A[i]; a[x][j].root; ++j)
        {
            int root=a[x][j].root, son=a[x][j].son, dis=a[x][j].dis;
            //printf("%d %d %d %d %lld!!!!!!!\n", x, root, son, sub(sumval[root][0], sumval[root][son]), 1LL*sub(sumid[root][0], sumid[root][son])*dis%P);
            ans[i][0]=add(ans[i][0], sub(sumval[root][0], sumval[root][son]));
            ans[i][0]=add(ans[i][0], 1LL*sub(sumid[root][0], sumid[root][son])*dis%P);
            sumval[root][0]=add(sumval[root][0], 1LL*dis*i%P);
            sumval[root][son]=add(sumval[root][son], 1LL*dis*i%P);
            sumid[root][0]=add(sumid[root][0], i);
            sumid[root][son]=add(sumid[root][son], i);
        }
        ans[i][1]=ans[i-1][1];
        ans[i][0]=add(ans[i-1][0], ans[i][0]);
        //printf("%d ", ans[i][1]);
        ans[i][1]=add(ans[i][1], ans[i][0]);
        //printf("%d %d\n", ans[i][1], ans[i][0]);
    }
    for(rint i=1, x; i<=q; ++i)
    {
        scanf("%d", &x);
        printf("%d\n", ans[x][1]);
    }
    return 0;
}