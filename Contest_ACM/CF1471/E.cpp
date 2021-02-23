#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 1005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, k, val, pos=1;

void solve(int x, int len) {
    //printf("%d %d\n", x, len);
    do {
        len=(len+1)/2;
        printf("? %d\n", (x+len-1)%n+1);
        fflush(stdout);
        scanf("%d", &val);
        if(val<=k) x=(x+len-1)%n+1;
    } while(len>1);
    printf("! %d\n", x);
    fflush(stdout);
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i=1; i<=500; ++i) {
        printf("? %d\n", pos);
        fflush(stdout);
        scanf("%d", &val);
        if(val<k) {
            solve(1, i);
            return 0;
        }
    }
    for(int i=501; i<=1000; ++i) {
        pos+=max(1, n/200);
        printf("? %d\n", pos);
        fflush(stdout);
        scanf("%d", &val);
        if(val<k) {
            solve(pos, min(i, (n+1)/2));
            return 0;
        }
    }
    return 0;
}