#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 600005
#define P 998244353
#define G 3
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define fuck printf("FUCK!!\n");
using namespace std;
 
int n, last=1, tot=1, pos1[MAXN], pos2[MAXN], b[MAXN], len[MAXN], f[MAXN][20];
LL ans;
char s[MAXN], t[MAXN];
 
struct A {int nxt[26], fa, len, val;} a[MAXN];
 
void insert(int ch, int id)
{
    int np=++tot, p=last;
    a[np].len=a[p].len+1, a[np].val=1;
    for(; p && !a[p].nxt[ch]; p=a[p].fa) a[p].nxt[ch]=np;
    if(!p) a[np].fa=1;
    else
    {
        int q=a[p].nxt[ch];
        if(a[q].len==a[p].len+1) a[np].fa=q;
        else
        {
            int nq=++tot;
            a[nq].len=a[p].len+1, a[nq].fa=a[q].fa;
            memcpy(a[nq].nxt, a[q].nxt, sizeof(a[nq].nxt));
            for(; p && a[p].nxt[ch]==q; p=a[p].fa) a[p].nxt[ch]=nq;
            a[np].fa=a[q].fa=nq;
        }
    }
    last=np, pos1[id]=np;
}
 
void update(int l, int r)
{
    int x=pos1[r];
    for(rint i=19; i>=0; --i)
        if(a[f[x][i]].len>=r-l+1) x=f[x][i];
    //printf("%d %d %d\n", l, r, a[x].val);
    ans=max(ans, 1LL*a[x].val*(r-l+1));
}
 
void init()
{
    for(rint i=1; i<=tot; ++i) f[i][0]=a[i].fa, b[a[i].len]++;
    for(rint i=1; i<=n; ++i) b[i]+=b[i-1];
    for(rint i=1; i<=tot; ++i) pos2[b[a[i].len]--]=i;
    for(rint i=tot; i>=1; --i) a[a[pos2[i]].fa].val+=a[pos2[i]].val;
    for(rint i=1; i<=19; ++i)
        for(rint j=1; j<=tot; ++j) f[j][i]=f[f[j][i-1]][i-1];
    t[1]='#', t[n*2+2]='@';
    for(rint i=1; i<=n; ++i) t[i*2]=s[i], t[i*2+1]='#';
}
 
void manacher()
{
    int mid=0, maxright=0;
    for(rint i=1; i<n*2+2; ++i)
    {
        if(i<maxright) len[i]=min(len[mid*2-i], maxright-i);
        else len[i]=1;
        if((i+len[i])&1) update((i-len[i]+1)/2, (i+len[i]-1)/2);
        while(t[i+len[i]]==t[i-len[i]])
        {
            if((i+len[i])&1) update((i-len[i]+1)/2, (i+len[i]-1)/2);
            len[i]++;
        }
        if(i+len[i]>maxright) maxright=i+len[i], mid=i;
    }
}
 
int main()
{
    scanf("%s", s+1);
    n=strlen(s+1);
    for(rint i=1; i<=n; ++i) insert(s[i]-'a', i);
    init();
    manacher();
    printf("%lld\n", ans);
    return 0;
}