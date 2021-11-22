#include <bits/stdc++.h>
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

inline int add(int x, int y) {return x+y<n?x+y:x+y-n;}
inline int sub(int x, int y) {return x>=y?x-y:x-y+n;}

int main()
{
    scanf("%d", &T);
    for(int Case=1; Case<=T; ++Case) {
        scanf("%d", &n);
        printf("Case #%d: %d\n", Case, n/2);
        for(int i=1; i<=n/2; ++i) {
            int pos=i-1;
            for(int j=1; j<n; ++j) {
                int nxt;
                if(j&1) nxt=add(pos, j);
                else nxt=sub(pos, j);
                printf("%d %d\n", pos+1, nxt+1);
                pos=nxt;
            }
        }
    }
    return 0;
}