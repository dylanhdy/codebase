#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int t, n, vis[1005], a[100005];
char s[100005];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        int ans=0;
        scanf("%s", s+1);
        n=strlen(s+1);
        for(int i=1; i<=n; ++i)
        {
            if(i>1 && s[i-1]==s[i]) s[i]=0;
            if(i>2 && s[i-2]==s[i]) s[i]=0;
            if(s[i]==0) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}