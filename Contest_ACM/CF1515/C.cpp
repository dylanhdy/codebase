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
#define pii pair<int, int>
using namespace std;

int T, n, m, x, ans[MAXN];
pair<int, int> a[MAXN];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &m, &x);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i].first);
            a[i].second=i;
        }
        sort(a+1, a+n+1);
        priority_queue<pii> q; 
        for(int i=1; i<=m; ++i) q.push(MP(0, i));
        for(int i=n; i>=1; --i) {
            int val=q.top().first, id=q.top().second;
            q.pop();
            ans[a[i].second]=id;
            q.push(MP(val-a[i].first, id));
        }
        printf("YES\n");
        for(int i=1; i<=n; ++i) printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}