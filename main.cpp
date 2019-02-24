#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 300005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, bit, ans=INF, tot=1, a[MAXN], bel[MAXN], t[MAXN*32][2];

void insert(int x, int id)
{
    int p=1;
    for(rint i=0; i<31; ++i)
    {
        int ch=((x>>i)&1);
        if(!t[p][ch]) t[p][ch]=++tot;
        p=t[p][ch];
    }
    if(!mp[p]) mp[p]=++s2;
    q[mp[p]].push_back(id);
    bel[id]=2;
    st2.insert(id);
}

int query(int x)
{
    int p=1, val=0;
    for(rint i=0; i<31; ++i)
    {
        int ch=((x>>i)&1);
        if(t[p][ch]) p=t[p][ch];
        else p=t[p][ch^1], val+=(1<<i);
    }
    return ans;
}

void add(int x, int id)
{
    int p=1, val=0;
    for(rint i=0; i<31; ++i)
    {
        int ch=((x>>i)&1);
        if(!t[p][ch^1]) p=t[p][ch], val+=(1<<i);
        else p=t[p][ch^1];
    }
    
}

int main()
{
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        for(rint j=0; j<31; ++j)
            if((a[i]>>j)&1) bit=max(bit, j);
    }
    for(rint i=1; i<=n; ++i)
        if((a[i]>>bit)&1) insert(a[i]^(1<<bit), i);
    for(rint i=1; i<=n; ++i)
        if((a[i]>>bit)&1==0) ans=min(ans, query(a[i]));
    for(rint i=1; i<=n; ++i)
        if((a[i]>>bit)&1==0) add(a[i], i);
    dfs(1);
    return 0;
}