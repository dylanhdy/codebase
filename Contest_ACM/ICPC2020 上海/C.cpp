#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, ans, x, y, f[35][2][2], g[35];

int dfs(int pos, int tag1, int tag2)
{
    if(pos==-1) return 1;
    if(f[pos][tag1][tag2]!=-1) return f[pos][tag1][tag2];
    int val1=0, val2=0, chx=((x>>pos)&1), chy=((y>>pos)&1);
    for(int i=0; i<=(!tag1 || chx); ++i)
        for(int j=0; j<=(!tag2 || chy); ++j) {
            if(i && j) continue;
            int tmp=dfs(pos-1, tag1 && i==chx, tag2 && j==chy);
            if(i+j==1) val2=(val2+1LL*tmp*(pos+1)%P)%P;
            val1=(val1+tmp)%P;
        }
    f[pos][tag1][tag2]=val1;
    if(!g[pos]) g[pos]=val2;
    //printf("%d %d %d %d??\n", pos, tag1, tag2, val2);
    return val1;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        ans=0;
        memset(f, -1, sizeof(f));
        memset(g, 0, sizeof(g));
        scanf("%d%d", &x, &y);
        dfs(31, 1, 1);
        for(int i=0; i<=31; ++i) ans=(ans+g[i])%P;
        printf("%d\n", ans);
    }
    return 0;
}