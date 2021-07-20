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
#define MAXN 500005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, a[MAXN], vis[MAXN], tag[MAXN];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        vis[a[i]]=1;
        m=max(a[i], m);
    }
    sort(a+1, a+n+1);
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n && a[j]+i<=m; ++j)
            if(vis[a[j]+i]) {
                tag[i]=1;
                break;
            }
        //printf("%d %d??\n", i, tag[i]);
    for(int i=1; i<=m+1; ++i) {
        int flag=1;
        for(int j=1; j<=m/i; ++j)
            if(tag[i*j]) {
                flag=0;
                break;
            }
        if(flag) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}