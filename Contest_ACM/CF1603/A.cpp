#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#define LL long long
#define LD long double
#define MAXN
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int T, n, a[100005];

int main()
{
    scanf("%d", &T);
    while(T--) {
        int ans=1;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            int flag=0;
            scanf("%d", &a[i]);
            for(int j=1; j<=min(i, 100); ++j)
                if(a[i]%(j+1)) flag=1;
            if(!flag) ans=0;
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}