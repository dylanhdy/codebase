#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define rint register int
#define MAXN 500005
#define INF 0x3f3f3f3f
#define mid ((l+r)>>1)
#define ls (root<<1)
#define rs (root<<1|1)
using namespace std;
 
int n, tot=1, last=1, deg[MAXN*2];
char s[MAXN];
 
struct A {int len, fa, nxt[26];} a[MAXN*2];
 
void insert(int ch)
{
    int np=++tot, p=last;
    a[np].len=a[p].len+1;
    for(; p && !a[p].nxt[ch]; p=a[p].fa) a[p].nxt[ch]=np;
    if(!p) a[np].fa=1;
    else
    {
        int q=a[p].nxt[ch];
        if(a[q].len==a[p].len+1) a[np].fa=q;
        else
        {
            int nq=++tot;
            a[nq].len=a[p].len+1;
            a[nq].fa=a[q].fa;
            memcpy(a[nq].nxt, a[q].nxt, sizeof(a[q].nxt));
            for(; p && a[p].nxt[ch]==q; p=a[p].fa) a[p].nxt[ch]=nq;
            a[np].fa=a[q].fa=nq;
        }
    }
    last=np;
}
 
struct Segtree
{
    int tag[MAXN*4];
     
    inline void down(int root)
    {
        tag[ls]=min(tag[ls], tag[root]);
        tag[rs]=min(tag[rs], tag[root]);
        tag[root]=INF;
    }
 
    void build(int root, int l, int r)
    {
        tag[root]=INF;
        if(l==r || r==0) return;
        build(ls, l, mid);
        build(rs, mid+1, r);
    }
 
    void update(int root, int l, int r, int x, int y, int k)
    {
        if(l>y || r<x) return;
        if(l>=x && r<=y)
        {
            tag[root]=min(tag[root], k);
            return;
        }
        down(root);
        update(ls, l, mid, x, y, k);
        update(rs, mid+1, r, x, y, k);
    }
 
    int query(int root, int l, int r, int x)
    {
        if(l==r) return tag[root];
        down(root);
        if(x<=mid) return query(ls, l, mid, x);
        else return query(rs, mid+1, r, x);
    }
} t1, t2;
 
int main()
{
    scanf("%s", s+1);
    n=strlen(s+1);
    for(rint i=1; i<=n; ++i) insert(s[i]-'a');
    for(rint i=1; i<=tot; ++i) deg[a[i].fa]++;
    t1.build(1, 1, n), t2.build(1, 1, n);
    for(rint i=1; i<=tot; ++i)
        if(!deg[i])
        {
            t1.update(1, 1, n, a[i].len-a[a[i].fa].len+1, a[i].len,  a[a[i].fa].len+1);
            t2.update(1, 1, n, 1, a[i].len-a[a[i].fa].len, a[i].len+1);
        }
    for(rint i=1; i<=n; ++i) printf("%d\n", min(t1.query(1, 1, n, i), t2.query(1, 1, n, i)-i));
}
