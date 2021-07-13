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
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n;
char s[200005];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s+1);
        n=strlen(s+1);
        int col=-1, cnt1=0, cnt2=0;
        LL ans=0;
        for(int i=1; i<=n; ++i) {
            if(s[i]=='?') {
                cnt1++, cnt2++;
                if(col>=0) col^=1;
            } else {
                if(s[i]=='1') {
                    if(col==-1 || col==0) col=1, cnt2++;
                    else cnt2=cnt1+1;
                } else {
                    if(col==-1 || col==1) col=0, cnt2++;
                    else cnt2=cnt1+1;
                }
                cnt1=0;
            }
            //printf("%d %d??\n", i, cnt2);
            ans+=cnt2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}