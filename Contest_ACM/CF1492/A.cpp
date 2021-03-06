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

int T;
LL p, ans, num[5];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%lld%lld%lld%lld", &p, &num[1], &num[2], &num[3]);
        ans=1e18;
        for(int i=1; i<=3; ++i) {
            if(p%num[i]==0) ans=0;
            else ans=min(ans, num[i]-p%num[i]);
        }
        printf("%lld\n", ans);
    } 
    return 0;
}