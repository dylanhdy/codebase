#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 300005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int q, a[MAXN], c[MAXN], f[MAXN][20];

int find(int x)
{
    int pos=x;
    for(int j=18; j>=0; --j)
        if(a[f[pos][j]]) pos=f[pos][j];
    return pos;
}

int main()
{
    scanf("%d%d%d", &q, &a[0], &c[0]);
    for(int i=1; i<=q; ++i) {
        int op, x, w, v;
        LL ans;
        scanf("%d", &op);
        if(op==1) {
            scanf("%d%d%d", &f[i][0], &a[i], &c[i]);
            for(int j=1; j<=18; ++j) f[i][j]=f[f[i][j-1]][j-1];
        } else {
            scanf("%d%d", &x, &w);
            ans=v=0;
            while(v<w) {
                int fa=find(x);
                int tmp=min(w-v, a[fa]);
                ans+=1LL*tmp*c[fa];
                v+=tmp; a[fa]-=tmp;
                if(!a[x]) break;
            }
            printf("%d %lld\n", v, ans);
            fflush(stdout);
        }
    }
    return 0;
}