#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, ans, e[MAXN][2], f[MAXN];

int find(int x)
{
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}

int main()
{
    scanf("%d%d", &m, &n);
    for(int i=1; i<=m; ++i) {
        int k, temp;
        scanf("%d", &k);
        for(int j=1; j<=k; ++j) {
            scanf("%d", &temp);
            if(!e[temp][0]) e[temp][0]=i;
            else e[temp][1]=i;
        }
    }
    for(int i=1; i<=m; ++i) f[i]=i;
    //for(int i=1; i<=m; ++i) printf("%d %d\n", e[i][0], e[i][1]);
    for(int i=1; i<=n; ++i) {
        int fx=find(e[i][0]), fy=find(e[i][1]);
        if(fx!=fy) {
            ans++;
            f[fx]=fy;
        }
    }
    printf("%d\n", ans);
    return 0;
}