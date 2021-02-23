#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 300005
#define MAXM 1000005
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int T, n, q, val, val0, val1, a[MAXN], num[MAXM];

int main() {
    scanf("%d", &T);
    while(T--) {
        val=val0=val1=0;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            for(int j=sqrt(a[i]); j>1; --j)
                if(a[i]%(j*j)==0) {
                    a[i]/=(j*j);
                    break;
                }
            num[a[i]]++;
        }
        for(int i=1; i<=n; ++i) {
            if(a[i]!=1 && num[a[i]]%2) val1=max(val1, num[a[i]]);
            else val0++;
            val=max(val, num[a[i]]);
        }
        //printf("%d %d %d?\n", num[1], val0, val1);
        scanf("%d", &q);
        for(int i=1; i<=q; ++i) {
            LL temp;
            scanf("%lld", &temp);
            if(temp) printf("%d\n", max(val0, val1));
            else printf("%d\n", val);
        }
        for(int i=1; i<=n; ++i) num[a[i]]--;
    }
    return 0;
}