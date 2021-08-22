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

int T, n, a[100];

int dfs(int x, int y, int num, int z)
{
    if(x==n+1) return num==z;
    if(x==y) return dfs(x+1, y, num, z);
    int flag=0;
    if(dfs(x+1, y, num, z)) flag=1;
    if(dfs(x+1, y, num+a[x], z)) flag=1;
    if(dfs(x+1, y, num-a[x], z)) flag=1;
    return flag;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        int flag=0;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        for(int i=1; i<=n; ++i)
            if(dfs(1, i, 0, a[i])) flag=1;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}