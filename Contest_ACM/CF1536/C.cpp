#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 500005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, a, b;
char s[MAXN];

int gcd(int x, int y)
{
    return y?gcd(y, x%y):x;
}

map<pair<int, int>, int> mp;

int main()
{
    scanf("%d", &T);
    while(T--) {
        a=b=0;
        mp.clear();
        scanf("%d%s", &n, s+1);
        for(int i=1; i<=n; ++i) {
            if(s[i]=='D') a++;
            else b++;
            int d=gcd(a, b);
            mp[MP(a/d, b/d)]++;
            printf("%d ", mp[MP(a/d, b/d)]);
        }
        printf("\n");
    }
    return 0;
}