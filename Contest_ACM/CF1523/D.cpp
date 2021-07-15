#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <ctime>
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

int n, m, p, f[MAXN], cnt[MAXN];
LL ans1, ans2;
char s[MAXN][65];

void solve(int x)
{
    vector<int> vec;
    for(int i=1; i<=m; ++i)
        if(s[x][i]=='1') vec.PB(i);
    int p=vec.size();
    for(int sta=0; sta<(1<<p); ++sta) f[sta]=0;
    for(int i=1; i<=n; ++i) {
        int mask=0;
        for(int j=0; j<p; ++j)
            if(s[i][vec[j]]=='1') mask|=(1<<j);
        f[mask]++;
    }
    for(int i=0; i<p; ++i)
        for(int sta=0; sta<(1<<p); ++sta)
            if(!((sta>>i)&1)) f[sta]+=f[sta|(1<<i)];
    for(int sta=0; sta<(1<<p); ++sta)
        if(f[sta]>=(n+1)/2 && cnt[sta]>ans2) {
            LL tmp=0;
            for(int j=0; j<p; ++j)
                if((sta>>j)&1) tmp|=(1LL<<vec[j]);
            ans1=tmp, ans2=cnt[sta];
        }
}

int main()
{
    srand(time(0));
    scanf("%d%d%d", &n, &m, &p);
    for(int i=1; i<=n; ++i) scanf("%s", s[i]+1);
    for(int sta=1; sta<(1<<p); ++sta) cnt[sta]=cnt[sta>>1]+(sta&1);
    for(int i=1; i<=min(50, n); ++i) solve(1LL*rand()*rand()%n+1);
    for(int i=1; i<=m; ++i) printf("%d", (ans1>>i)&1);
    return 0;
}