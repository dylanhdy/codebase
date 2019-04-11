#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 1000005
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define pii pair<int, int>
using namespace std;
 
int n, t, k, tot=1, last=1, num[MAXN], b[MAXN], pos[MAXN];
char s[MAXN];
 
struct Node {int len, fa, nxt[26]; LL siz, sum;} a[MAXN];
 
void insert(int ch)
{
    int nx=++tot, x=last;
    a[nx].len+=a[x].len+1;
    a[nx].siz=1;
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
    for(rint i=tot; i>=1; --i)
    {
        int x=pos[i];
        if(t) a[a[x].fa].siz+=a[x].siz;
        else a[x].siz=1;
    }
    a[1].siz=0;
    for(rint i=tot; i>=1; --i)
    {
        int x=pos[i];
        a[x].sum=a[x].siz;
        for(rint j=0; j<26; ++j) a[x].sum+=a[a[x].nxt[j]].sum;
    }
}
 
void dfs(int x, int k)
{
    for(rint i=0; i<26; ++i)
    {
        int to=a[x].nxt[i];
        if(!to) continue;
        //printf("%d %lld %c!!!!!\n", to, a[to].sum, 'a'+i);
        if(k>a[to].sum) k-=a[to].sum;
        else
        {
            printf("%c", 'a'+i);
            k-=a[to].siz;
            if(k) dfs(to, k);
            break;
        }
    }
}
 
int main()
{
    scanf("%s%d%d", s+1, &t, &k);
    n=strlen(s+1);
    for(rint i=1; i<=n; ++i) insert(s[i]-'a');
    topsort();
    if(a[1].sum<k) {printf("-1\n"); return 0;}
    dfs(1, k);
    return 0;
}