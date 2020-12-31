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
#define BASE 19260817
#define PB push_back
#define INF 0x3f3f3f3f
#define ULL unsigned long long
using namespace std;

int n, k, res, t, ans, a[1000005];
char s[1000005];

map<ULL, int> mp;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ans=-1;
        mp.clear();
        scanf("%d%d", &n, &k);
        scanf("%s", s+1);
        ULL val=0, base=1;
        for(int i=1; i<=n; ++i) a[i]='1'-s[i];
        for(int i=1; i<=k; ++i)
        {
            val=val*BASE+a[i];
            if(i>1) base*=BASE;
        }
        //printf("%llu\n", val);
        mp[val]=1;
        for(int i=2; i+k-1<=n; ++i)
        {
            val=(val-a[i-1]*base)*BASE+a[i+k-1];
            mp[val]=1;
            //printf("%llu\n", val);
        }
        res=max(k-30, 0), k=min(k, 30);
        for(int sta=0; sta<=min(n, (1<<k)-1); ++sta)
        {
            ULL temp=0;
            for(int i=k-1; i>=0; --i) temp=temp*BASE+((sta>>i)&1);
            if(!mp[temp]) {ans=sta; break;}
        }
        if(ans==-1) printf("NO\n");
        else
        {
            printf("YES\n");
            for(int i=1; i<=res; ++i) printf("0");
            for(int i=k-1; i>=0; --i) printf("%d", (ans>>i)&1);
            printf("\n");
        }
    }
    return 0;
}