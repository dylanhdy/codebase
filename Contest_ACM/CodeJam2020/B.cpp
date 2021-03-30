#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 1005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, x, y, n, ans;
char s[MAXN];

int main()
{
    scanf("%d", &T);
    for(int Case=1; Case<=T; ++Case) {
        scanf("%d%d%s", &x, &y, s+1);
        n=strlen(s+1); ans=0;
        int last=-1;
        for(int i=1; i<=n; ++i) {
            if(s[i]=='J') {
                if(last==0) ans+=x;
                last=1;
            }
            if(s[i]=='C') {
                if(last==1) ans+=y;
                last=0;
            }
        }
        printf("Case #%d: %d\n", Case, ans);
    }
    return 0;
}