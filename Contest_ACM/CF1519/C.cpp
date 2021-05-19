#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, m, u[MAXN], s[MAXN];
LL ans[MAXN];

vector<int> vec[MAXN];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            vec[i].clear();
            ans[i]=0;
        }
        for(int i=1; i<=n; ++i) scanf("%d", &u[i]);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &s[i]);
            vec[u[i]].PB(s[i]);
        }
        for(int i=1; i<=n; ++i) {
            sort(vec[i].begin(), vec[i].end());
            LL sum=0;
            for(int j=0; j<vec[i].size(); ++j) sum+=vec[i][j];
            for(int j=-1; j<(int)vec[i].size(); ++j) {
                if(j>=0) sum-=vec[i][j];
                int x=vec[i].size()-j-1;
                for(int k=1; k*k<=x; ++k)
                    if(x%k==0) {
                        if(k>j+1) ans[k]+=sum;
                        if(k*k!=x && x/k>j+1) ans[x/k]+=sum;
                    }
            }
        }
        for(int i=1; i<=n; ++i) printf("%lld ", ans[i]);
        printf("\n");
    }
    return 0;
}