#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
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
char s[100005], t[10005];

int main()
{
    scanf("%d", &T);
    while(T--) {
        int ans=0;
        scanf("%d", &n);
        scanf("%s", s+1);
        for(int i=1; i<=n; ++i) t[i]=s[i];
        sort(t+1, t+n+1);
        for(int i=1; i<=n; ++i)
            if(s[i]!=t[i]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}