#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 1000005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, tot, siz, a[MAXN], b[MAXN], dep[MAXN], cir[MAXN], id[MAXN];
LL lcm, k, val1, val2;

vector<LL> vec;

void dfs(int x, int deep, int root)
{
    dep[x]=deep; cir[x]=cir[root];
    if((x+n)%m!=root) dfs((x+n)%m, deep+1, root);
}

int main()
{
    memset(id, -1, sizeof(id));
    scanf("%d%d%lld", &n, &m, &k);
    k--;
    for(int i=0; i<n; ++i) scanf("%d", &a[i]);
    for(int i=0; i<m; ++i) {
        scanf("%d", &b[i]);
        id[b[i]]=i;
    }
    for(int i=0; i<m; ++i)
        if(!cir[i]) {
            cir[i]=(++tot);
            dfs(i, 0, i);
        }
    siz=m/tot;
    for(int i=0; i<n; ++i) {
        if(id[a[i]]==-1 || cir[i%m]!=cir[id[a[i]]]) continue;
        vec.PB(1LL*(dep[id[a[i]]]-dep[i%m]+siz)%siz*n+i);
    }
    lcm=1LL*n*m/tot;
    val1=lcm-vec.size();
    val2=k%val1;
    sort(vec.begin(), vec.end());
    for(int i=0; i<vec.size(); ++i)
        if(vec[i]<=val2) val2++;
    printf("%lld\n", k/val1*lcm+val2+1);
    return 0;
}