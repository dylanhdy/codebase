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

int T, n, r[500005][10];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=5; ++j) {
                scanf("%d", &r[i][j]);
            }
        }
        int ans=1, cnt=0;
        for(int i=2; i<=n; ++i) {
            int num=0;
            for(int j=1; j<=5; ++j)
                if(r[i][j]<r[ans][j]) num++;
            if(num>=3) ans=i;
        }
        for(int i=1; i<=n; ++i) {
            if(ans==i) continue;
            int num=0;
            for(int j=1; j<=5; ++j)
                if(r[i][j]>r[ans][j]) num++;
            if(num>=3) cnt++;
        }
        if(cnt==n-1) printf("%d\n", ans);
        else printf("-1\n");
    }
    return 0;
}