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
#define MAXN 200005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, f[MAXN], ans[MAXN];
char s[MAXN], t[MAXN];

struct A {int l, r, id;} a[MAXN];

bool CMP(A x, A y)
{
    return x.r<y.r;
}

void solve()
{
    for(int i=1, j=1; i<=n; ++i) {
        if(s[i]!=t[i]) f[i]=f[i-1]+1;
        else f[i]=f[i-1];
        
        while(j<=m && a[j].r==i) {
            //printf("%d %d %d??\n", a[j].r, a[j].l, f[a[j].r]-f[a[j].l-1]);
            ans[a[j].id]=min(ans[a[j].id], f[a[j].r]-f[a[j].l-1]);
            j++;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", s+1);
    for(int i=1; i<=m; ++i) {
        scanf("%d%d", &a[i].l, &a[i].r);
        a[i].id=i;
        ans[i]=INF;
    }
    sort(a+1, a+m+1, CMP);
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j)
            for(int k=0; k<3; ++k) {
                if(i==j || j==k || k==i) continue;
                t[1]='a'+i;
                t[2]='a'+j;
                t[3]='a'+k;
                for(int i=4; i<=n; ++i) t[i]=t[i-3];
                solve();
            }
    for(int i=1; i<=m; ++i) printf("%d\n", ans[i]);
    return 0;
}