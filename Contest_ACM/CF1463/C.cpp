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

int n, T;
LL t[MAXN], x[MAXN];

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%lld%lld", &t[i], &x[i]);
        t[n+1]=1e18;
        int pos=0, tar=0, ans=0;
        LL tim=0;
        for(int i=1; i<=n; ++i)
        {
            if(t[i]-tim>=abs(tar-pos))
            {
                tim=t[i], pos=tar;
                tar=x[i];
            }
            if(1LL*(x[i]-pos)*(x[i]-tar)<=0 && abs(x[i]-pos)>=t[i]-tim && abs(x[i]-pos)<=t[i+1]-tim)
                ans++;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}