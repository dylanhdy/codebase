#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <set>
#define MAXN 305
#define MAXM 100000
#define P 998244353
#define INF 0x3f3f3f3f
#define FUCK printf("FUCK\n");
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, t[MAXN];
char s[MAXN][MAXN];

vector<int> ans[MAXN];

struct Trie
{
    int tot, t[MAXM*10][26], f[MAXM*10];

    void init()
    {
        for(rint i=1; i<=tot; ++i)
        {
            f[i]=0;
            for(rint j=0; j<26; ++j) t[i][j]=0;
        }
        tot=1;
    }

    int insert(int s[], int len)
    {
        int p=1;
        for(rint i=1; i<=len; ++i)
        {
            int ch=s[i];
            if(!t[p][ch]) t[p][ch]=++tot, f[tot]=p;
            p=t[p][ch];
        }
        return p;
    }

    void find(int x, vector<int> &ans)
    {
        if(x==1) {ans.clear(); return;}
        find(f[x], ans);
        for(rint i=0; i<26; ++i)
            if(t[f[x]][i]==x) ans.push_back(i);
    }
} trie;

namespace Dinic
{
    int cnt, T, S, head[MAXM*2], dep[MAXM*2], nxt[MAXM*2];

    struct Edge {int next, to, flow;} edge[MAXM*10];
    queue<int> q;

    void addedge(int from, int to, int flow)
    {
        edge[++cnt].next=head[from];
        edge[cnt].to=to;
        edge[cnt].flow=flow;
        head[from]=cnt;
    }

    void init()
    {
        cnt=1, T=2, S=1;
        memset(head, 0, sizeof(head));
    }

    bool bfs()
    {
        for(rint i=1; i<=n+trie.tot+2; ++i) dep[i]=0;
        while(!q.empty()) q.pop();
        dep[S]=1; q.push(S);
        while(!q.empty())
        {
            int x=q.front(); q.pop();
            for(int i=head[x]; i; i=edge[i].next)
            {
                int to=edge[i].to;
                if(dep[to] || edge[i].flow<=0) continue;
                dep[to]=dep[x]+1;
                q.push(to);
            }
        }
        return dep[T];
    }

    int dfs(int x, int flow)
    {
        if(x==T) return flow;
        int add=0;
        for(int i=head[x]; i; i=edge[i].next)
        {
            int to=edge[i].to;
            if(add>=flow) break;
            if(dep[to]!=dep[x]+1 || edge[i].flow<=0) continue;
            int f=dfs(to, min(edge[i].flow, flow-add));
            edge[i].flow-=f, edge[i^1].flow+=f;
            add+=f;
        }
        return add;
    }

    int find(int x)
    {
        for(rint i=head[x]; i; i=edge[i].next)
            if(!edge[i].flow && edge[i].to!=S) return edge[i].to-n-2;
        return 0;
    }

    int solve()
    {
        int maxflow=0;
        while(bfs()) maxflow+=dfs(S, INF);
        return maxflow;
    }
}

struct Seqam
{
    int root, tot, siz, fa[MAXN], nxt[MAXN][26], last[26];

    void init()
    {
        root=tot=1;
        for(rint i=0; i<26; ++i) last[i]=1;
    }

    void insert(int ch)
    {
        int np=++tot;
        fa[np]=last[ch];
        for(rint i=0; i<26; ++i)
            for(rint p=last[i]; p && !nxt[p][ch]; p=fa[p]) nxt[p][ch]=np;
        last[ch]=np;
    }

    void dfs(int x, int dep, int id, int lim)
    {
        if(dep!=1 && siz<=n+1)
        {
            int pos=trie.insert(t, dep-1); siz++;
            Dinic::addedge(id+2, pos+2+n, 1);
            Dinic::addedge(pos+2+n, id+2, 0);
        }
        if(dep==lim+1 || siz==n+2) return;
        for(rint i=0; i<26; ++i)
            if(nxt[x][i])
            {
                t[dep]=i;
                dfs(nxt[x][i], dep+1, id, lim);
            }
    }
} seqam[MAXN];

bool check(int lim)
{
    Dinic::init();
    trie.init();
    for(rint i=1; i<=n; ++i)
    {
        seqam[i].siz=0;
        seqam[i].dfs(1, 1, i, lim);
        Dinic::addedge(Dinic::S, i+2, 1);
        Dinic::addedge(i+2, Dinic::S, 0);
    }
    for(rint i=2; i<=trie.tot; ++i)
    {      
        Dinic::addedge(i+n+2, Dinic::T, 1);
        Dinic::addedge(Dinic::T, i+n+2, 0);
    }
    return Dinic::solve()==n;
}

int main()
{
    freopen("diff.in", "r", stdin);
    freopen("diff.out", "w", stdout);
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i)
    {
        scanf("%s", s[i]+1);
        seqam[i].init();
        m=strlen(s[i]+1);
        for(rint j=1; j<=m; ++j) seqam[i].insert(s[i][j]-'a');
    }
    int l=0, r=300, num=-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            num=mid, r=mid-1;
            for(rint i=1; i<=n; ++i) trie.find(Dinic::find(i+2), ans[i]);
        }
        else l=mid+1;
    }

    printf("%d\n", num);
    if(num!=-1)
        for(rint i=1; i<=n; ++i)
        {
            for(rint j=0; j<ans[i].size(); ++j) putchar(ans[i][j]+'a');
            putchar('\n');
        }
    return 0;
}