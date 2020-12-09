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
#define P 998857459
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, m, k, last, fac[MAXN], a[MAXN], val[MAXN];

vector<pair<int, int> > vec;

int main()
{
    scanf("%d%d", &n, &m);
    fac[0]=1;
    for(int i=1; i<=2803; ++i) fac[i]=1LL*fac[i-1]*i%P;
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        int temp=(last+fac[a[i]])%P;
        if(a[i]<2803) vec.PB(MP(i, temp));
        last=temp;
    }
    for(int i=0; i<vec.size(); ++i)
        for(int j=i; j<vec.size(); ++j)
        {
            int len=vec[j].first-vec[i].first+1;
            int temp=(vec[j].second-(i?vec[i-1].second:0)+P)%P;
            val[len]=max(val[len], temp);
        }
    for(int i=1; i<=n; ++i) val[i]=max(val[i], val[i-1]);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d", &k);
        int l=1, r=n, ans=-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(val[mid]>=k) ans=mid, r=mid-1;
            else l=mid+1;
        }
        printf("%d\n", ans);
    }
    return 0;
}