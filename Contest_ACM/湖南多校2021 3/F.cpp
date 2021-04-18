#include <bits/stdc++.h>
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

int n, ans, root, f[MAXN], b[MAXN], a[MAXN];

int find(int x)
{
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) f[i]=i;
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        if(a[i]==i) {
            if(!root) root=i, b[i]=root;
            else ans++, b[i]=root;
        }
    }
    for(int i=1; i<=n; ++i) {
        if(a[i]==i) continue;
        int fx=find(a[i]), fy=find(i);
        if(fx==fy) {
            ans++;
            if(root) b[i]=root;
            else root=i, b[i]=i;
        } else f[fx]=fy, b[i]=a[i];
    }
    printf("%d\n", ans);
    for(int i=1; i<=n; ++i) printf("%d ", b[i]);
    return 0;
}