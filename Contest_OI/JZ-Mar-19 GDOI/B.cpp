#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 4000005
#define P 1000000007
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define FUCK printf("FUCK\n");
using namespace std;

inline int add(int x, int y) {return x+y>=P?x+y-P:x+y;}
inline int sub(int x, int y) {return x>=y?x-y:x-y+P;}

char QWQ[]={'A', 'C', 'G', 'T'};
int n, m, k, tot, last, root[MAXN], vis[MAXN], id[MAXN];
LL f[MAXN];
char s[MAXN];

struct Sta {int fa, len, nxt[4];} a[MAXN];
vector<char> t;

void insert(int ch, int Id)
{
    int np=++tot, p=last;
    a[np].len=a[p].len+1, id[np]=Id;
    for(; p && !a[p].nxt[ch]; p=a[p].fa) a[p].nxt[ch]=np;
    if(!p) a[np].fa=root[Id];
    else
    {
        int q=a[p].nxt[ch];
        if(a[p].len+1==a[q].len) a[np].fa=q;
        else
        {
            int nq=++tot;
            a[nq].len=a[p].len+1, id[nq]=Id;
            memcpy(a[nq].nxt, a[q].nxt, sizeof(a[nq].nxt));
            a[nq].fa=a[q].fa;
            for(; p && a[p].nxt[ch]==q; p=a[p].fa) a[p].nxt[ch]=nq;
            a[np].fa=a[q].fa=nq;
        }
    }
    last=np;
}

void dfs(int x, int Id)
{
    if(vis[x]) return;
    vis[x]=1;
    for(rint i=0; i<4; ++i)
    {
        if(!a[x].nxt[i])
            for(rint j=Id+1; j<=n; ++j)
                if(a[root[j]].nxt[i])
                {
                    a[x].nxt[i]=a[root[j]].nxt[i];
                    break;
                }
        if(a[x].nxt[i]) dfs(a[x].nxt[i], id[a[x].nxt[i]]);
    }
}

void cal(int x, int op)
{
    if(op)
    {
        for(rint i=0; i<t.size(); ++i) putchar(t[i]);
        putchar('\n');
    }
    f[x]=1;
    for(rint i=0; i<4; ++i)
    {
        if(!a[x].nxt[i]) continue;
        if(op) t.push_back(QWQ[i]);
        if(op || !f[a[x].nxt[i]]) cal(a[x].nxt[i], op);
        if(op) t.pop_back();
        f[x]=add(f[x], f[a[x].nxt[i]]);
    }
}
int main()
{
    freopen("copy.in", "r", stdin);
    freopen("copy.out", "w", stdout);
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i)
    {
        scanf("%s", s+1);
        m=strlen(s+1);
        root[i]=last=++tot;
        for(rint j=1; j<=m; ++j)
        {
            if(s[j]=='A') insert(0, i);
            if(s[j]=='C') insert(1, i);
            if(s[j]=='G') insert(2, i);
            if(s[j]=='T') insert(3, i);
        }
    }
    scanf("%d", &k);
    dfs(1, 1);
    cal(1, k);
    printf("%lld\n", f[1]);
    return 0;
}