#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 5005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, ans=INF, t1, t2, p[MAXN], q[MAXN];
char s[MAXN], t[MAXN];

int solve(int x)
{
    int sum=0;
    for(rint i=1; i<x; ++i) sum+=p[i];
    for(rint i=1; i<=t2; ++i, ++x)
    {
        if(x<=0) sum+=q[i];
        else if(x<=t1) sum+=abs(p[x]-q[i]);
        else sum+=n-q[i];
    }
    for(rint i=max(x, 1); i<=t1; ++i) sum+=n-p[i];
    return sum;
}

int main()
{
    scanf("%d%s%s", &n, s+1, t+1);
    for(rint i=1; i<n; ++i)
        if(s[i]!=s[i+1]) p[++t1]=i;
    for(rint i=1; i<n; ++i)
        if(t[i]!=t[i+1]) q[++t2]=i;
    if(!t1 && !t2 && s[1]!=t[1]) {printf("%d\n", n); return 0;}
    int tag=(s[1]==t[1]);
    for(rint i=-t2-1; i<=t1+1; ++i)
        if((i+INF-tag)&1) ans=min(ans, solve(i));
    printf("%d\n", ans);
    return 0;
}
