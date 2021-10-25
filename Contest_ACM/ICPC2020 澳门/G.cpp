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
#define MAXN 400005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, a[MAXN], pos[256], vis[256];

bool dfs(int x)
{
    if(vis[x]!=-1) return vis[x];
    int flag=0;
    for(int i=0; i<8; ++i) {
        int to=(x^(1<<i));
        if(pos[to]>pos[x] && !dfs(to)) flag=1;
    }
    vis[x]=flag;
    return flag;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        pos[a[i]]=i;
    }
    while(m--) {
        int op, k;
        scanf("%d%d", &op, &k);
        if(op==1) {
            n++;
            a[n]=k;
            pos[k]=n;
        } else {
            if(pos[a[k]]>k) {
                printf("Grammy\n");
                continue;
            }
            memset(vis, -1, sizeof(vis));
            if(dfs(a[k])) printf("Grammy\n");
            else printf("Alice\n");
        }
    }
    return 0;
}