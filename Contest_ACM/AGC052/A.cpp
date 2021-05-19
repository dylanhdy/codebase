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
using namespace std;

int T, n;
char s[3][MAXN];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        scanf("%s%s%s", s[0], s[1], s[2]);
        for(int i=1; i<=n; ++i) printf("0");
        for(int i=1; i<=n; ++i) printf("1");
        printf("0\n");
    }
    return 0;
}