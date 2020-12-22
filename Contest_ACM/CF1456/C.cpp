#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 500005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, k, pos, c[MAXN];
LL ans, add;

vector<int> vec;

int main()
{
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i) scanf("%d", &c[i]);
    sort(c+1, c+n+1, greater<int>());
    for(pos=1; pos<=n && add>=0; ++pos)
    {
        ans+=add;
        add+=c[pos];
    }
    if(add>=0)
    {
        printf("%lld\n", ans);
        return 0;
    }
    for(int i=n; i>=pos; --i) vec.PB(c[i]);
    vec.PB(add);
    for(int i=0; i<vec.size(); ++i) ans+=1LL*i/(k+1)*vec[i];
    printf("%lld\n", ans);
    return 0;
}