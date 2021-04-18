#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, c;
vector<int> vec;

void solve(int x, int val)
{
    if(val<=n-x) {
        for(int i=x+val; i>=x; --i) vec.PB(i);
        for(int i=x+val+1; i<=n; ++i) vec.PB(i);
        return;
    }
    solve(x+1, val-(n-x));
    reverse(vec.begin(), vec.end());
    vec.PB(x);
}

int main()
{
    scanf("%d", &T);
    for(int Case=1; Case<=T; ++Case) {
        vec.clear();
        scanf("%d%d", &n, &c);
        if(c<n-1 || c>=(n+1)*n/2) {
            printf("Case #%d: IMPOSSIBLE\n", Case);
            continue;
        }
        solve(1, c-n+1);
        printf("Case #%d: ", Case);
        for(int i=0; i<vec.size(); ++i) printf("%d ", vec[i]);
        printf("\n");
    }
}