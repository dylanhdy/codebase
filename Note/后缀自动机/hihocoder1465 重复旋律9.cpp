#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

LL k, val;

struct SAM
{
    int n, tot=1, last=1, sg[MAXN*2], vis[MAXN*2][27];
    LL f[MAXN*2][27];
    __int128_t all[MAXN*2], g[MAXN*2], h[MAXN*2];
    char s[MAXN];

    struct Node {int fa, len, next[27];} a[MAXN*2];

    void init()
    {
        scanf("%s", s+1);
        n=strlen(s+1);
        for(int i=1; i<=n; ++i) insert(s[i]-'a');
    }

    void insert(int ch)
    {
        int cur=++tot, pos=last;
        a[cur].len=a[last].len+1;
        for(; pos && !a[pos].next[ch]; pos=a[pos].fa) a[pos].next[ch]=cur;
        if(!pos) a[cur].fa=1;
        else
        {
            int x=a[pos].next[ch];
            if(a[pos].len+1==a[x].len) a[cur].fa=x;
            else
            {
                int y=++tot;
                a[y]=a[x];
                a[y].len=a[pos].len+1;
                for(; pos && a[pos].next[ch]==x; pos=a[pos].fa) a[pos].next[ch]=y;
                a[x].fa=a[cur].fa=y;
            }
        }
        last=cur;
    }

    void dfs1(int x)
    {
        if(all[x]) return;
        for(int i=0; i<26; ++i)
        {
            int to=a[x].next[i];
            if(!to) continue;
            dfs1(to);
            vis[x][sg[to]]=1;
            for(int j=0; j<=26; ++j) f[x][j]+=f[to][j];
            all[x]+=all[to];
        }
        for(int i=0; i<=26; ++i)
            if(!vis[x][i])
            {
                sg[x]=i;
                break;
            }
        all[x]++;
        f[x][sg[x]]++;
    }

    void dfs2(int x)
    {
        val=sg[x];
        if(h[x]>=k) return;
        k-=h[x];
        for(int i=0; i<26; ++i)
        {
            int to=a[x].next[i];
            if(!to) continue;
            if(k>g[to]) k-=g[to];
            else
            {
                printf("%c", 'a'+i);
                dfs2(to);
                break;
            }
        }
    }
} sam1, sam2;

int main()
{
    scanf("%lld", &k);
    sam1.init(), sam2.init();
    sam1.dfs1(1), sam2.dfs1(1);
    for(int i=1; i<=sam1.tot; ++i)
    {
        for(int j=0; j<=26; ++j)
            sam1.g[i]+=sam1.f[i][j]*(sam2.all[1]-sam2.f[1][j]);
        sam1.h[i]=sam2.all[1]-sam2.f[1][sam1.sg[i]];
    }
    if(sam1.g[1]<k)
    {
        printf("NO\n");
        return 0;
    }
    sam1.dfs2(1);
    printf("\n");
    for(int i=1; i<=sam2.tot; ++i)
    {
        sam2.g[i]=sam2.all[i]-sam2.f[i][val];
        sam2.h[i]=(val!=sam2.sg[i]);
    }
    sam2.dfs2(1);
    printf("\n");
    return 0;
}