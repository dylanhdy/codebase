#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int t, n, a, b, f[MAXN][2];
char s[MAXN];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%s", &a, &b, s+1);
        n=strlen(s+1);
        for(int i=1; i<=n; ++i) f[i][0]=f[i][1]=0;
        for(int i=1; i<=n; ++i)
        {
            if(s[i]=='1')
            {
                f[i][1]=min(f[i-1][1], f[i-1][0]);
                f[i][0]=min(f[i-1][1], f[i-1][0])+a;
            }
            else
            {
                //f[i][0]=min(f[i-1][1]+a, f[i-1][0]);
                f[i][0]=f[i-1][0];
                f[i][1]=min(f[i-1][0], f[i-1][1])+b;   
            }
        }
        printf("%d\n", f[n][0]);
    }
    return 0;
}