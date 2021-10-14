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
#define MAXN 200005
#define MAXM
#define P 100000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, m, L[MAXN], R[MAXN], pos[MAXN];

int solve(int l, int r, int x, int y)
{
    if(x==y) return 1LL*(r-l+1)*(l+r)/2%P;
    int mid=(l+r)/2;
    if(pos[mid]) return 1LL*solve(l, mid, x, pos[mid])*solve(mid+1, r, pos[mid]+1, y)%P;
    if(L[y]<=mid) return solve(l, mid, x, y);
    else if(R[x]>mid) return solve(mid+1, r, x, y);
    else return 0;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &m, &n);
        for(int i=0; i<1<<m; ++i) pos[i]=0;
        for(int i=1; i<=n; ++i) {
            scanf("%d%d", &L[i], &R[i]);
            pos[R[i]]=i;
        }
        printf("%d\n", solve(0, (1<<m)-1, 1, n));
    }
    return 0;
}