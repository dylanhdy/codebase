#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

struct SAM
{
    int len, fa;
    map<int, int> nxt;
} a[MAXN*2];

int T, n, tot, last, top, num[MAXN], id[MAXN];
LL ans, pre[MAXN];

void insert(int ch)
{
    int cur=++tot, p=last;
    a[cur].len=a[last].len+1;
    for(; p && !a[p].nxt[ch]; p=a[p].fa) a[p].nxt[ch]=cur;
    if(!p) a[cur].fa=1;
    else
    {
        int x=a[p].nxt[ch];
        if(a[p].len+1==a[x].len) a[cur].fa=x;
        else
        {
            int y=++tot;
            a[y]=a[x];
            a[y].len=a[p].len+1;
            for(; p && a[p].nxt[ch]==x; p=a[p].fa) a[p].nxt[ch]=y;
            a[x].fa=a[cur].fa=y;
        }
    }
    last=cur;
}

void init()
{
    for(int i=1; i<=tot; ++i) a[i].nxt.clear();
    tot=last=1;
    ans=top=0;
}

LL update(int x)
{
    int l=1, r=top, pos=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(id[mid]>=x) pos=mid, r=mid-1;
        else l=mid+1;
    }
    return pre[pos-1]+1LL*(x-id[pos-1])*num[pos];
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d", &n);
        for(int i=1, ch; i<=n; ++i)
        {
            scanf("%d", &ch);
            insert(ch);
            while(top && num[top]<=ch) top--;
            LL temp=pre[top]+1LL*(i-id[top])*ch;
            top++;
            num[top]=ch, id[top]=i, pre[top]=temp;
            ans+=update(i-a[a[last].fa].len);
        }
        printf("%lld\n", ans);
    }
    return 0;
}