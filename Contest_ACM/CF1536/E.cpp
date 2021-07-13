#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 2005
#define MAXM
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, m, num, ans;
char mp[MAXN][MAXN];

int main()
{
    scanf("%d", &T);
    while(T--) {
        ans=1, num=0;
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; ++i) {
            scanf("%s", mp[i]+1);
            for(int j=1; j<=m; ++j) num+=(mp[i][j]=='#');
        }
        for(int i=1; i<=num; ++i) ans=ans*2%P;
        printf("%d\n", ans-(n*m==num));
    }
    return 0;
}