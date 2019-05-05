#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 400005
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define pii pair<int, int>
using namespace std;
 
int n, m, tot=1, last=1, num[MAXN], b[MAXN], pos[MAXN];
LL ans, pre[MAXN];
char s[MAXN], t[MAXN];
 
struct Node {int len, fa, val, nxt[26];} a[MAXN*2];
 
void insert(int ch)
{
    int nx=++tot, x=last;
    a[nx].len+=a[x].len+1;
    a[nx].val=1;
    for(; x && !a[x].nxt[ch]; x=a[x].fa) a[x].nxt[ch]=nx;
    if(!x) a[nx].fa=1;
    else
    {
        int y=a[x].nxt[ch];
        if(a[x].len+1==a[y].len) a[nx].fa=y;
        else
        {
            int ny=++tot;
            a[ny].len=a[x].len+1;
            memcpy(a[ny].nxt, a[y].nxt, sizeof(a[y].nxt));
            a[ny].fa=a[y].fa;
            for(; x && a[x].nxt[ch]==y; x=a[x].fa) a[x].nxt[ch]=ny;
            a[nx].fa=a[y].fa=ny;
        }
    }
    last=nx;
}
 
void topsort()
{
    for(rint i=1; i<=tot; ++i) b[a[i].len]++;
    for(rint i=1; i<=tot; ++i) b[i]+=b[i-1];
    for(rint i=1; i<=tot; ++i) pos[b[a[i].len]--]=i;
    for(rint i=tot; i>=1; --i) a[a[pos[i]].fa].val+=a[pos[i]].val;
    for(rint i=2; i<=tot; ++i)
    {
        int x=pos[i], fa=a[x].fa;
        pre[x]=pre[fa]+1LL*a[x].val*(a[x].len-a[fa].len);
    }
}
 
int main()
{
    scanf("%s%s", s+1, t+1);
    n=strlen(s+1), m=strlen(t+1);
    for(rint i=1; i<=n; ++i) insert(s[i]-'a');
    topsort();
    for(rint i=1, x=1, len=0; i<=m; ++i)
    {
        int ch=t[i]-'a';
        while(x && !a[x].nxt[ch]) x=a[x].fa, len=a[x].len;
        if(a[x].nxt[ch]) x=a[x].nxt[ch], len++;
        else x=1, len=0;
        ans+=1LL*a[x].val*(len-a[a[x].fa].len)+pre[a[x].fa];
    }
    printf("%lld\n", ans);
    return 0;
}