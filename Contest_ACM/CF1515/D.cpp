#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
#define pii pair<int, int>
using namespace std;

int T, n, l, r, ans, cnt, num1[MAXN], num2[MAXN];

int main()
{
    scanf("%d", &T);
    while(T--) {
        ans=0, cnt=0;
        scanf("%d%d%d", &n, &l, &r);
        for(int i=1; i<=n; ++i) num1[i]=num2[i]=0;
        for(int i=1, tmp; i<=l; ++i) {
            scanf("%d", &tmp);
            num1[tmp]++;
        }
        for(int i=1, tmp; i<=r; ++i) {
            scanf("%d", &tmp);
            if(num1[tmp]) num1[tmp]--, cnt++;
            else num2[tmp]++;
        }
        l-=cnt, r-=cnt;
        if(l>r) {
            for(int i=1; i<=n && l>r; ++i)
                while(num1[i]>=2 && l>r) l-=2, num1[i]-=2, ans++;
        } else {
            for(int i=1; i<=n && r>l; ++i)
                while(num2[i]>=2 && r>l) r-=2, num2[i]-=2, ans++;
        }
        ans+=max(l, r);
        printf("%d\n", ans);
    }
    return 0;
}