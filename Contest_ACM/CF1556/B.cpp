#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
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

int T, n, a[MAXN];

vector<int> vec[2];

LL solve(int x)
{
    LL tmp=0;
    for(int i=1, j=0; i<=n; i+=2, j++)
        tmp+=abs(i-vec[x][j]);
    return tmp;
}

int main()
{
    scanf("%d", &T);

    while(T--) {
        vec[0].clear(), vec[1].clear();
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            if(a[i]&1) vec[1].PB(i);
            else vec[0].PB(i);
        }
        if(abs((int)vec[1].size()-(int)vec[0].size())>1) {
            printf("-1\n");
            continue;
        }
        LL ans;
        if(vec[1].size()>vec[0].size()) {
            ans=solve(1);
        }
        if(vec[1].size()==vec[0].size()) {
            ans=min(solve(0), solve(1));
        }
        if(vec[1].size()<vec[0].size()) {
            ans=solve(0);
        }
        printf("%lld\n", ans);
    }
    return 0;
}