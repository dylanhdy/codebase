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

int n, last=1, tot=1, cnt, head[MAXN];
char s[MAXN];
double f[MAXN];

struct Edge {int next, to;} edge[MAXN];
struct Node {int len, fa, tag, nxt[26];} a[MAXN*2];

void addedge(int from, int to)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    head[from]=cnt;
}

void insert(int ch)
{
    int p=last, np=++tot;
    a[np].len=a[p].len+1;
    a[np].tag=1;
    for(; !a[p].nxt[ch]; p=a[p].fa) a[p].nxt[ch]=np;
    if(!p) a[np].fa=1;
    else
    {
        int q=a[p].nxt[ch];
        if(a[q].len==a[p].len+1) a[np].fa=q;
        else
        {
            int nq=++tot;
            a[nq].len=a[p].len+1;
            memcpy(a[nq].nxt, a[q].nxt, sizeof(a[q].nxt));
            a[nq].fa=a[q].fa;
            for(; p && a[p].nxt[ch]==q; p=a[p].fa) a[p].nxt[ch]=nq;
            a[np].fa=a[q].fa=nq;
        }
    }
    last=np;
}

void dfs(int x)
{
    if(a[x].tag)
    {
        f[x]=a[x].len-a[a[x].fa].len;
        return;
    }
    double temp=0;
    for(rint i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        dfs(to);
        temp+=1.0/f[to];
    }
    f[x]=1.0/temp+a[x].len-a[a[x].fa].len;
}

int main()
{
    freopen("second.in", "r", stdin);
    freopen("second.out", "w", stdout);
    scanf("%s", s+1);
    n=strlen(s+1);
    for(rint i=n; i>=1; --i) insert(s[i]-'a');
    for(rint i=2; i<=tot; ++i) addedge(a[i].fa, i);
    dfs(1);
    printf("%.6lf\n", f[1]);
    return 0;
}