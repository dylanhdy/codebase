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
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, m, a[MAXN], b[MAXN], t[MAXN];

void add(int x, int k)
{
    for(; x<=m; x+=(x&-x)) t[x]+=k;
}

int ask(int x)
{
    int num=0;
    for(; x; x-=(x&-x)) num+=t[x];
    return num;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        int flag=1;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            b[i]=a[i];
        }
        sort(b+1, b+n+1);
        m=unique(b+1, b+n+1)-b-1;
        for(int i=1; i<=m; ++i) t[i]=0;
        for(int i=1; i<=n; ++i) a[i]=lower_bound(b+1, b+m+1, a[i])-b;
        add(a[1], 1);
        for(int i=2; i<=n; ++i) {
            int r=max(a[i], a[i-1])-1;
            int l=min(a[i], a[i-1]);
            if(ask(r)-ask(l)>0) {
                flag=0;
                break;
            }
            add(a[i], 1);
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}