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

int T, n, m, flag, a[MAXN], k[MAXN], num[MAXN], ans[MAXN];

vector<int> vec[MAXN];

bool CMP(int x, int y)
{
    return vec[x].size()<vec[y].size();
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        flag=1;
        for(int i=1; i<=n; ++i) num[i]=0;
        for(int i=1; i<=m; ++i) {
            ans[i]=0;
            vec[i].clear();
        }
        for(int i=1; i<=m; ++i) {
            scanf("%d", &k[i]);
            for(int j=1; j<=k[i]; ++j) {
                int temp;
                scanf("%d", &temp);
                vec[i].PB(temp);
            }
        }
        for(int i=1; i<=m; ++i) a[i]=i;
        sort(a+1, a+m+1, CMP);
        for(int i=1; i<=m; ++i) {
            for(int j=0; j<vec[a[i]].size(); ++j)
                if(num[vec[a[i]][j]]<(m+1)/2) {
                    num[vec[a[i]][j]]++;
                    ans[a[i]]=vec[a[i]][j];
                    break;
                }
            if(!ans[a[i]]) {
                flag=0;
                break;
            }
        }
        if(!flag) printf("NO\n");
        else {
            printf("YES\n");
            for(int i=1; i<=m; ++i) printf("%d ", ans[i]);
            printf("\n");
        }
    }
    return 0;
}