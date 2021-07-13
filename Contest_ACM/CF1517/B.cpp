#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 105
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, m, vis[MAXN][MAXN], b[MAXN][MAXN];

struct A {int x, y, val;};

vector<A> vec;

bool CMP(A x, A y)
{
    return x.val<y.val;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        memset(vis, 0, sizeof(vis));
        vec.clear();
        int p=1;
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j) {
                scanf("%d", &b[i][j]);
                vec.PB(A{i, j, b[i][j]});
            }
        sort(vec.begin(), vec.end(), CMP);
        for(int i=0; i<m; ++i) vis[vec[i].x][vec[i].y]=1;
        for(int i=1; i<=n; ++i) {
            vector<int> v1, v2;
            for(int j=1; j<=m; ++j) {
                if(vis[i][j]) v1.PB(b[i][j]);
                else v2.PB(b[i][j]);
            }
            for(int j=1; j<p; ++j) b[i][j]=v2[j-1];
            for(int j=p; j<p+v1.size(); ++j) b[i][j]=v1[j-p];
            p+=v1.size();
            for(int j=p; j<=m; ++j) b[i][j]=v2[j-v1.size()-1];
        }
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) printf("%d ", b[i][j]);
            printf("\n");
        }
    }
    return 0;
}