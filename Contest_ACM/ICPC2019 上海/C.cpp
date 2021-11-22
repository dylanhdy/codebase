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
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

int ifac[MAXN], fac[MAXN];

void init(int lim)
{
    ifac[0]=ifac[1]=fac[0]=fac[1]=1;
    for(int i=2; i<=lim; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
    for(int i=2; i<=lim; ++i) {
        ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
        fac[i]=1LL*fac[i-1]*i%P;
    }
}

inline int add(int x, int y) {return x+y<P?x+y:x+y-P;}
inline int sub(int x, int y) {return x>=y?x-y:x-y+P;}

inline int cmb(int x, int y)
{
    return 1LL*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

int cal(int n, int m, int x, int y)
{
    if(n<=0 || m<=0) return 0;
    int tmp=cmb(n+m-2, n-1);
    for(int i=1, a=y-1, b=x-1; a>=0 || b>=0; ++i) {
        if(a>=0) tmp=i&1?sub(tmp, cmb(n+m-2, a)):add(tmp, cmb(n+m-2, a));
        if(b>=0) tmp=i&1?sub(tmp, cmb(n+m-2, b)):add(tmp, cmb(n+m-2, b));
        swap(a, b);
        a+=y-m, b+=x-n;
    }
    //printf("%d\n", tmp);
    return tmp;
}

int T, f[50], g[50];

int main()
{
    init(2e5);
    scanf("%d", &T);
    for(int Case=1; Case<=T; ++Case) {
        int n, m, s, k, x, y;
        vector<pii> yes, no;
        scanf("%d%d%d%d", &n, &m, &s, &k);
        yes.PB({1, 1});
        yes.PB({n, m});
        for(int i=1; i<=s; ++i) {
            scanf("%d%d", &x, &y);
            yes.PB({x, y});
        }
        for(int i=1; i<=k; ++i) {
            scanf("%d%d", &x, &y);
            no.PB({x, y});
        }
        if(n==1 && m==1) {printf("Case #%d: %d\n", Case, k==0); continue;}
        if(n==m) {printf("Case #%d: 0\n", Case); continue;}
        sort(yes.begin(), yes.end());
        sort(no.begin(), no.end());
        f[0]=1;
        for(int i=1; i<yes.size(); ++i) {
            int lx=yes[i-1].fi, ly=yes[i-1].se;
            int nx=yes[i].fi, ny=yes[i].se;
            vector<pii> tmp;
            for(auto e: no)
                if(e.fi>=lx && e.fi<=nx && e.se>=ly && e.se<=ny) tmp.PB(e);
            sort(tmp.begin(), tmp.end());
            for(int j=0; j<tmp.size(); ++j) {
                int nx=tmp[j].fi, ny=tmp[j].se;
                g[j]=cal(nx-lx+1, ny-ly+1, nx-ly, n-m+ny-lx);
                for(int k=0; k<j; ++k) {
                    int tx=tmp[k].fi, ty=tmp[k].se;
                    g[j]=sub(g[j], 1LL*g[k]*cal(nx-tx+1, ny-ty+1, nx-ty, n-m+ny-tx)%P);
                }
            }
            f[i]=cal(nx-lx+1, ny-ly+1, nx-ly, n-m+ny-lx);
            for(int j=0; j<tmp.size(); ++j) {
                int tx=tmp[j].fi, ty=tmp[j].se;
                f[i]=sub(f[i], 1LL*g[j]*cal(nx-tx+1, ny-ty+1, nx-ty, n-m+ny-tx)%P);
            }
            f[i]=1LL*f[i-1]*f[i]%P;
        }
        printf("Case #%d: %d\n", Case, f[yes.size()-1]);
    }
    return 0;
}
/*
3 6 0 0
*/