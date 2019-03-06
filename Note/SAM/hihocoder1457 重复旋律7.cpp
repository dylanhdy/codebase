#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 1000005
#define P 1000000007
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, ans, tot=1, last=1, deg[MAXN*2];
char s[MAXN];

struct SAM {int fa, len, f, g, nxt[11];} a[MAXN*2];

queue<int> q;

void insert(int ch)
{
    int p=last, np=++tot;
    a[np].len=a[p].len+1;
    for(; p && !a[p].nxt[ch]; p=a[p].fa) a[p].nxt[ch]=np;
    if(!p) a[np].fa=1;
    else
    {
        int q=a[p].nxt[ch];
        if(a[p].len+1==a[q].len) a[np].fa=q;
        else
        {
            int nq=++tot;
            a[nq].len=a[p].len+1;
            a[nq].fa=a[q].fa;
            memcpy(a[nq].nxt, a[q].nxt, sizeof(a[q].nxt));
            for(; p && a[p].nxt[ch]==q; p=a[p].fa) a[p].nxt[ch]=nq;
            a[q].fa=a[np].fa=nq;
        }
    }
    last=np;
}

void topsort()
{
    for(rint i=1; i<=tot; ++i)
        for(rint j=0; j<=10; ++j) deg[a[i].nxt[j]]++;
    q.push(1);
    a[1].g=1;
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        for(rint i=0; i<=10; ++i)
        {
            int to=a[x].nxt[i];
            if(i<=9)
            {
                a[to].f=(a[to].f+1LL*i*a[x].g%P+1LL*10*a[x].f%P)%P;
                a[to].g=(a[x].g+a[to].g)%P;
            }
            deg[to]--;
            if(!deg[to]) q.push(to);           
        }
    }   
}

int main()
{
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i)
    {
        scanf("%s", s+1);
        m=strlen(s+1);
        for(rint j=1; j<=m; ++j) insert(s[j]-'0');
        insert(10);
    }
    topsort();
    for(rint i=1; i<=tot; ++i) ans=(ans+a[i].f)%P;
    printf("%d\n", ans);
    return 0;
}