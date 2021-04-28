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

int T, n, num[5][5], f[5][5][MAXN];
char s[5][MAXN];

void solve()
{
    for(int ch=0; ch<=1; ++ch) {
        for(int i=1; i<=3; ++i)
            for(int j=i+1; j<=3; ++j) {
                int siz1=num[i][ch], siz2=num[j][ch];
                if(min(siz1, siz2)<=n) continue;
                for(int k=1; k<=max(siz1, siz2); ++k) {
                    for(int a=1; a<=max(f[i][ch][k], f[j][ch][k]); ++a)
                        printf("%c", (ch^1)+'0');
                    if(k!=max(siz1, siz2)) printf("%c", ch+'0');
                }
                printf("\n");
                return;
            }
    }
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=1; i<=3; ++i) {
            scanf("%s", s[i]+1);
            for(int ch=0; ch<=1; ++ch) {
                for(int j=1; j<=2*n+2; ++j) f[i][ch][j]=0;
                int cnt1=0, cnt2=0;
                for(int j=1; j<=2*n; ++j) {
                    if(s[i][j]==ch+'0') {
                        f[i][ch][++cnt1]=cnt2;
                        cnt2=0;
                    } else cnt2++;
                }
                f[i][ch][++cnt1]=cnt2;
                num[i][ch]=cnt1;
            }
        }
        solve();
    }
    return 0;
}