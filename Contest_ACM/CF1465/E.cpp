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

int n, num[30];
LL t;
char s[MAXN];

bool dfs(int x, LL res)
{
    if(x==-1) return res==0;
    LL temp=1e18;
    for(int i=(num[x]&1); i<=num[x]; i+=2)
        temp=min(temp, abs((1LL<<x)*i-res));
    return dfs(x-1, temp);
}

int main()
{
    scanf("%d%lld", &n, &t);
    scanf("%s", s+1);
    t=t-(1<<(s[n]-'a'))+(1<<(s[n-1]-'a'));
    for(int i=1; i<n-1; ++i) num[s[i]-'a']++;
    if(dfs(25, abs(t))) printf("Yes\n");
    else printf("No\n");
    return 0;
}