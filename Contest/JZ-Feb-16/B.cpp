#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 205
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, L, len, ans[MAXN];
char s[MAXN][MAXN], t[MAXN*2], r[MAXN];

bool comp(int i, int j, int l)
{
    for(rint k=0; k<l; ++k)
        if(s[i][j+k]!=r[k]) return false;
    return true;
}

bool check(int m, int x, int y)
{
    //printf("%d %d %d!!!!\n", m, x, y);
    for(rint i=0; i<m; ++i)
    {
        int nx=(i+x)%m, ny=y+(i+x)/m, l=0;
        ans[nx]=0;
        for(rint j=i; j<len; j+=m) r[l++]=t[j];
        for(rint j=0; j<n; ++j)
            if(comp(j, ny, l)) {ans[nx]=j+1; break;}
        if(!ans[nx]) return false;
        //printf("%d %d %d\n", nx, ny, ans[nx]);
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &L);
    for(rint i=0; i<n; ++i) scanf("%s", s[i]);
    scanf("%s", t);
    len=strlen(t);
    for(rint i=1; i<=len; ++i)
        for(rint j=0; j<i; ++j)
            for(rint k=0; k<L; ++k)
                if(check(i, j, k))
                {
                    printf("%d\n", i);
                    for(rint a=0; a<i; ++a) printf("%d ", ans[a]);
                    return 0;
                }
    printf("-1\n");
    return 0;
}
