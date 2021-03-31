#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM 5000005
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, a[MAXN];

vector<pair<int, int> > vec[MAXM];
vector<int> id[MAXM];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        id[a[i]].PB(i);
        if(id[a[i]].size()>=4) {
            printf("YES\n");
            printf("%d %d %d %d\n", id[a[i]][0], id[a[i]][1], id[a[i]][2], id[a[i]][3]);
            return 0;
        }
    }
    for(int i=1; i<=n; ++i)
        for(int j=i+1; j<=n; ++j) {
            int val=a[i]+a[j];
            for(int k=0; k<vec[val].size(); ++k) {
                int x=vec[val][k].first, y=vec[val][k].second;
                if(x!=i && y!=i && x!=j && y!=j) {
                    printf("YES\n");
                    printf("%d %d %d %d\n", x, y, i, j);
                    return 0;
                }
            }
            vec[val].PB(MP(i, j));
        }
    printf("NO\n");
    return 0;
}