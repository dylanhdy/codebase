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
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, k, a[MAXN], pos[MAXN], pre[MAXN], ans[105][2], l[MAXN], vis[105];

int main()
{
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n*k; ++i) {
        scanf("%d", &a[i]);
        l[i]=pos[a[i]];
        pos[a[i]]=i;
    }
    int lim=(n+k-2)/(k-1);
    for(int i=1; i<=n*k; ++i) {
        pre[i]=pre[i-1];
        if(!l[i] || vis[a[i]]) continue; 
        if(pre[i]-pre[l[i]]<lim) {
            vis[a[i]]=1;
            pre[i]++;
        }
        ans[a[i]][0]=l[i], ans[a[i]][1]=i;
    }
    for(int i=1; i<=n; ++i)
        printf("%d %d\n", ans[i][0], ans[i][1]);
    return 0;
}