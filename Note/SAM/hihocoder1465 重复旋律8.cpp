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

int n, m, tot=1, last=1, b[MAXN], id[MAXN*2], vis[MAXN];
LL ans;
char s[MAXN];

struct SAM {int fa, len, nxt[26]; LL val;} a[MAXN*2];

void insert(int ch)
{
    int p=last, np=++tot;
    a[np].len=a[p].len+1, a[np].val=1;
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
    for(rint i=1; i<=tot; ++i) b[a[i].len]++;
    for(rint i=1; i<=m; ++i) b[i]+=b[i-1];
    for(rint i=1; i<=tot; ++i) id[b[a[i].len]--]=i;
    for(rint i=tot; i>=2; --i)
    {
        int x=id[i];
        a[a[x].fa].val+=a[x].val;
    }
}

int main()
{
    scanf("%s", s+1);
    m=strlen(s+1);
    for(rint i=1; i<=m; ++i) insert(s[i]-'a');
    topsort();
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i)
    {
        ans=0;
        scanf("%s", s+1);
        m=strlen(s+1);
        for(rint j=m+1; j<=m*2; ++j) s[j]=s[j-m];
        for(rint j=1, p=1, len=0; j<=m*2; ++j)
        {
            int ch=s[j]-'a';
            while(p && !a[p].nxt[ch]) p=a[p].fa, len=a[p].len;
            if(a[p].nxt[ch]) p=a[p].nxt[ch], len++;
            else p=1, len=0;
            while(a[a[p].fa].len>=m) p=a[p].fa, len=a[p].len;
            if(len>=m && vis[p]!=i) vis[p]=i, ans+=a[p].val;
        }
        printf("%lld\n", ans);
    }
    return 0;
}