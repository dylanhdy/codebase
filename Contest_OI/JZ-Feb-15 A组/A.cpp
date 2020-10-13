#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <string>
#define MAXN 3005
#define P 1000000007
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, fac[MAXN];
string s[MAXN];

int solve(int len, int l, int r)
{
    if(l==r) return 1;
    int last=l, cnt=0, ans=1;
    for(rint i=l+1; i<=r; ++i)
    {
        if(s[i][len]!=s[last][len])
        {
            ans=1LL*ans*solve(len+1, last, i-1)%P;
            last=i, cnt++;
        }
    }
    ans=1LL*ans*solve(len+1, last, r)%P;
    cnt++;
    return 1LL*ans*fac[cnt]%P;
}

int main()
{
    scanf("%d", &n);
    fac[0]=1;
    for(rint i=1; i<=n; ++i) fac[i]=1LL*fac[i-1]*i%P;
    for(rint i=1; i<=n; ++i) cin>>s[i];
    sort(s+1, s+n+1);
    printf("%d\n", solve(0, 1, n));
    return 0;
}
