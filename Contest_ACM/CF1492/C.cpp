#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, m, ans, l[MAXN], r[MAXN];
char s[MAXN], t[MAXN];

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s%s", s+1, t+1);
    for(int i=1; i<=m; ++i) {
        l[i]=l[i-1]+1;
        while(s[l[i]]!=t[i]) l[i]++;
    }
    r[m+1]=n+1;
    for(int i=m; i>=1; --i) {
        r[i]=r[i+1]-1;
        while(s[r[i]]!=t[i]) r[i]--;
    }
    for(int i=1; i<m; ++i) ans=max(ans, r[i+1]-l[i]); 
    printf("%d\n", ans);
    return 0;
}