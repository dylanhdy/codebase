#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define P 998244353
#define MAXN 2000005
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, k, sum, tot=1, last=1, deg[MAXN], ans[MAXN];
char s[MAXN];

struct Node {int len, fa, nxt[26]; LL val;} a[MAXN];

queue<int> q;

void insert(int ch)
{
    int cur=++tot, p=last;
    a[cur].len=a[p].len+1;
    a[cur].val=1;
    for(; p && !a[p].nxt[ch]; p=a[p].fa) a[p].nxt[ch]=cur;
    if(!p) a[cur].fa=1;
    else
    {
        int x=a[p].nxt[ch];
        if(a[x].len==a[p].len+1) a[cur].fa=x;
        else
        {
            int y=++tot;
            a[y].len=a[p].len+1;
            memcpy(a[y].nxt, a[x].nxt, sizeof(a[y].nxt));
            a[y].fa=a[x].fa;
            for(; p && a[p].nxt[ch]==x; p=a[p].fa) a[p].nxt[ch]=y;
            a[cur].fa=a[x].fa=y;
        }
    }
    last=cur;
}


int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", s+1);
    for(rint i=1; i<=n; ++i) insert(s[i]-'a');
    for(rint i=1; i<=tot; ++i) deg[a[i].fa]++;
    for(rint i=1; i<=tot; ++i)
        if(!deg[i]) q.push(i);
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        //printf("%d %d!!\n", x, a[x].fa);
        a[a[x].fa].val+=a[x].val;
        deg[a[x].fa]--;
        if(!deg[a[x].fa]) q.push(a[x].fa);
    }
    for(rint i=1; i<=tot; ++i)
    {
        ans[a[i].len]=(ans[a[i].len]+1LL*a[i].val*(a[i].val-1)/2%P)%P;
        ans[a[a[i].fa].len]=(ans[a[a[i].fa].len]-1LL*a[i].val*(a[i].val-1)/2%P+P)%P;
    }
    for(rint i=n; i>=1; --i)
    {
        ans[i]=(ans[i+1]+ans[i])%P;
        if(i<=k) sum=(sum+ans[i])%P;
    }
    printf("%d\n", sum);
    return 0;
}