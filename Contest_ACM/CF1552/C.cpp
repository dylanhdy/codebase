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

int T, n, k, x[1005], y[1005], vis[10005], val[10005];

int main()
{
    scanf("%d", &T);
    while(T--) {
        int ans=0;
        vector<int> vec;
        scanf("%d%d", &n, &k);
        for(int i=1; i<=2*n; ++i) vis[i]=val[i]=0;
        for(int i=1; i<=k; ++i) {
            scanf("%d%d", &x[i], &y[i]);
            if(x[i]>y[i]) swap(x[i], y[i]);
            vis[x[i]]=vis[y[i]]=1;
            val[x[i]]=y[i], val[y[i]]=x[i];
        }
        for(int i=1; i<=2*n; ++i)
            if(!vis[i]) vec.PB(i);
        int tmp=vec.size()/2;
        for(int i=k+1, j=0; i<=n; ++i, ++j) {
            x[i]=vec[j], y[i]=vec[j+tmp];
            val[x[i]]=y[i], val[y[i]]=x[i];
        }
        for(int i=1; i<=n; ++i) {
            for(int j=x[i]+1; j<y[i]; ++j)
                if(val[j]<x[i] || val[j]>y[i]) ans++;
        }
        printf("%d\n", ans/2);
    }
    return 0;
}