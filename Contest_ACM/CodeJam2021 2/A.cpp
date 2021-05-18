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

int T, n, pos, sta;

int main()
{
    scanf("%d%d", &T, &n);
    while(T--) {
            for(int i=1; i<n; ++i) {
            printf("M %d %d\n", i, n);
            fflush(stdout);
            scanf("%d", &pos);
            if(pos!=i) {
                printf("S %d %d\n", i, pos);
                fflush(stdout);
                scanf("%d", &sta);
                
            }
        }
        printf("D\n");
        fflush(stdout);
        scanf("%d", &sta);
        if(sta==-1) break;
    }
    return 0;
}