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
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int t, n;
LL val[100], x[500005], num[100];

vector<int> vec;

int main()
{
    val[0]=1;
    for(int i=1; i<60; ++i) val[i]=1LL*val[i-1]*2%P;
    scanf("%d", &t);
    while(t--)
    {
        LL ans=0;
        scanf("%d", &n);
        for(int i=0; i<60; ++i) num[i]=0;
        for(int i=1; i<=n; ++i)
        {
            scanf("%lld", &x[i]);
            for(int j=0; j<60; ++j)
                if((x[i]>>j)&1) num[j]++;
        }
        for(int i=1; i<=n; ++i)
        {
            LL temp1=0, temp2=0;
            for(int j=0; j<60; ++j)
                if((x[i]>>j)&1) temp1=(temp1+num[j]*val[j]%P)%P;
            for(int j=0; j<60; ++j)
                if((x[i]>>j)&1) temp2=(temp2+n*val[j]%P)%P;
                else temp2=(temp2+num[j]*val[j]%P)%P;
            ans=(ans+temp1*temp2%P)%P;
        }
        printf("%lld\n", ans);
    }
    return 0;
}