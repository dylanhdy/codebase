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
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, num, flag;
char s[MAXN];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%s", &n, s+1);
        flag=1; num=0;
        for(int i=1; i<=n; ++i)
            if(s[i]=='M') num++;
        if(num*3!=n) {
            printf("NO\n");
            continue;
        }
        for(int i=1, cnt1=0, cnt2=0; cnt2<=num; ++i) {
            if(s[i]=='T') cnt1++, cnt2++;
            else cnt1--;
            if(cnt1<0) flag=0;
        }
        for(int i=n, cnt1=0, cnt2=0; cnt2<=num; --i) {
            if(s[i]=='T') cnt1++, cnt2++;
            else cnt1--;
            if(cnt1<0) flag=0;
        }
        if(!flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}