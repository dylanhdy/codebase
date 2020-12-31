#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 500005
#define MAXM
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int t, ans=1, n, m, f[MAXN], k[MAXN], x[MAXN][3];

vector<int> vec;

int find(int x)
{
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &k[i]);
        for(int j=1; j<=k[i]; ++j) scanf("%d", &x[i][j]);
        if(k[i]==1) x[i][2]=m+1;
    }
    for(int i=1; i<=m+1; ++i) f[i]=i;
    for(int i=1; i<=n; ++i)
    {
        int fx=find(x[i][1]), fy=find(x[i][2]);
        if(fx!=fy)
        {
            vec.PB(i);
            f[fx]=fy;
        }
    }
    for(int i=0; i<vec.size(); i++) ans=1LL*ans*2%P;
    printf("%d %d\n", ans, vec.size());
    for(int i=0; i<vec.size(); ++i) printf("%d ", vec[i]);
    return 0;
}