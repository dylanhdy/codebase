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
#define MAXN 1005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, b[MAXN], vis[MAXN], ans[MAXN];

bool check(int x)
{
    if(x<0 || x>=n) return false;
    if(ans[x]==-1) return true;
    else return false;
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));
        memset(ans, -1, sizeof(ans));
        for(int i=0; i<n; ++i) scanf("%d", &b[i]);
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(vis[j]) continue;
                if(check(b[j]-i)) {
                    vis[j]=1;
                    ans[b[j]-i]=b[j];
                } else if(check(b[j]+i)) {
                    vis[j]=1;
                    ans[b[j]+i]=b[j];
                }
            }
        }
        double val=0;
        for(int i=0; i<n; ++i) val+=sqrt(abs(ans[i]-i));
        printf("%lf\n", val);
    }
    return 0;
}