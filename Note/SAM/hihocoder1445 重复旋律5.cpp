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
using namespace std;

int n, tot=1, last=1;
LL ans;
char s[MAXN];

struct Node {int len, fa, next[26];} a[MAXN*2];

void insert(int ch)
{
    int cur=++tot, p=last;
    a[cur].len=a[last].len+1;
    for(; p && !a[p].next[ch]; p=a[p].fa) a[p].next[ch]=cur;
    if(!p) a[cur].fa=1, ans+=a[cur].len;
    else
    {
        int x=a[p].next[ch];
        if(a[p].len+1==a[x].len)
        {
            a[cur].fa=x;
            ans+=a[cur].len-a[x].len;
        }
        else
        {
            int y=++tot;
            a[y]=a[x];
            a[y].len=a[p].len+1;
            for(; p && a[p].next[ch]==x; p=a[p].fa) a[p].next[ch]=y;
            a[x].fa=a[cur].fa=y;
            ans+=a[cur].len-a[y].len;
        }
    }
    last=cur;
    //printf("%d %d !!!\n", cur, a[cur].len);
}

int main()
{
    scanf("%s", s+1);
    n=strlen(s+1);
    for(rint i=1; i<=n; ++i) insert(s[i]-'a');
    printf("%lld\n", ans);
    return 0;
}