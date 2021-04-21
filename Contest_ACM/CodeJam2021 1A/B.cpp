#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 105
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, m, p[MAXN];
LL ans, sum, num[MAXN];

LL f(LL x)
{
    LL val=0;
    for(int i=1; i<=m; ++i) {
        int temp=0;
        while(temp<num[i] && x%p[i]==0) {
            temp++;
            x/=p[i];
            val+=p[i];
        }
    }
    if(x==1) return val;
    else return 0;
}

int main()
{
    scanf("%d", &T);
    for(int qwq=1; qwq<=T; ++qwq) {
        sum=ans=0;
        scanf("%d", &m);
        for(int i=1; i<=m; ++i) {
            scanf("%d%lld", &p[i], &num[i]);
            sum+=num[i]*p[i];
        }
        for(int i=1; i<=min((LL)30000, sum-1); ++i)
            if(f(sum-i)==i) {
                ans=sum-i;
                break;
            }
        printf("Case #%d: %lld\n", qwq, ans);
    }
    return 0;
}