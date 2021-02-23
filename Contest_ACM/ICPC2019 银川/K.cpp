#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#define LL long long
#define LD long double
#define MAXN 1005
#define MAXM 1000005
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, m, ans, d[MAXN], tx[MAXM], ty[MAXM], x[MAXN][MAXN], y[MAXN][MAXN], f[MAXN][MAXN];

stack<int> sta1, sta2;

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) {
            int temp;
            scanf("%d", &temp);
            tx[temp]=i;
            ty[temp]=j;
        }
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) {
            int temp;
            scanf("%d", &temp);
            x[i][j]=tx[temp];
            y[i][j]=ty[temp];
        }
    for(int i=1; i<=m; ++i) f[n][i]=1;
    for(int i=n-1; i>=1; --i)
        for(int j=1; j<=m; ++j) {
            if(y[i][j]==y[i+1][j] && x[i][j]+1==x[i+1][j]) f[i][j]=f[i+1][j]+1;
            else f[i][j]=1;
        }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            int l=j;
            if(j>1 && x[i][j]==x[i][j-1] && y[i][j]==y[i][j-1]+1)
                while(!sta1.empty() && f[i][j]<=sta1.top()) {
                    ans=max(ans, sta1.top()*(j-sta2.top()));
                    l=sta2.top();
                    sta1.pop();
                    sta2.pop();
                }
            else
                while(!sta1.empty()) {
                    ans=max(ans, sta1.top()*(j-sta2.top()));
                    sta1.pop();
                    sta2.pop();
                }
            sta1.push(f[i][j]);
            sta2.push(l);
        }
        while(!sta1.empty()) {
            ans=max(ans, sta1.top()*(m+1-sta2.top()));
            sta1.pop();
            sta2.pop();
        }
    }
    printf("%d\n", ans);
    return 0;
}