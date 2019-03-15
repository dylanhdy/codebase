#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 400005
#define P 998244353
#define G 3
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int k, n, m, bit, num, sum[MAXN], pos[MAXN<<2], f[MAXN<<2], g[MAXN<<2], ans[MAXN<<2];
char a[MAXN], b[MAXN];

inline int add(int x, int y) {return x+y>=P?x+y-P:x+y;}
inline int sub(int x, int y) {return x>=y?x-y:x-y+P;}

inline int ksm(int x, int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=1LL*x*ans%P;
        x=1LL*x*x%P, y>>=1;
    }
    return ans;
}

void ntt(int a[], int n, int op)
{
    for(rint i=0; i<n; ++i)
        if(pos[i]<i) swap(a[pos[i]], a[i]);
    for(rint i=1; i<n; i<<=1)
    {
        int Wn=ksm(G, op==1?(P-1)/(i<<1):(P-1)-(P-1)/(i<<1));
        for(rint j=0; j<n; j+=(i<<1))
        {
            int W=1;
            for(rint k=0; k<i; ++k, W=1LL*W*Wn%P)
            {
                int x=a[j+k], y=1LL*W*a[i+j+k]%P;
                a[j+k]=add(x, y), a[i+j+k]=sub(x, y);
            }
        }
    }
    if(op==-1)
    {
        int inv=ksm(n, P-2);
        for(rint i=0; i<n; ++i) a[i]=1LL*a[i]*inv%P;
    }
}

void solve(char ch)
{
    for(rint i=0; i<(1<<bit); ++i) sum[i]=f[i]=g[i]=0;
    for(rint i=0; i<n; ++i)
    {
        if(a[i]==ch) sum[i]++;
        if(i) sum[i]+=sum[i-1];
    }
    for(rint i=0; i<=k; ++i) f[i]=sum[min(n-1, i+k)]>0;
    for(rint i=k+1; i<n; ++i)
        if(sum[min(n-1, i+k)]-sum[i-k-1]>0) f[i]=1;
    for(rint i=0; i<m; ++i)
        if(b[i]==ch) g[i]=1;
    /*
    printf("%c\n", ch);
    for(rint i=0; i<n; ++i) printf("%d ", sum[i]);
    printf("\n");
    for(rint i=0; i<(1<<bit); ++i) printf("%d ", f[i]);
    printf("\n");
    for(rint i=0; i<(1<<bit); ++i) printf("%d ", g[i]);
    printf("\n");*/
    ntt(f, 1<<bit, 1);
    ntt(g, 1<<bit, 1);
    for(rint i=0; i<(1<<bit); ++i) ans[i]=add(ans[i], 1LL*g[i]*f[i]%P);
}

int main()
{
    freopen("base.in", "r", stdin);
    freopen("base.out", "w", stdout);
    scanf("%d", &k);
    scanf("%s%s", a, b);
    n=strlen(a), m=strlen(b);
    reverse(a, a+n);
    while((1<<bit)<=n) bit++;
    for(rint i=0; i<(1<<bit); ++i) pos[i]=(pos[i>>1]>>1)|((i&1)<<(bit-1));
    solve('Z'), solve('P'), solve('S'), solve('B');
    ntt(ans, 1<<bit, -1);
    for(rint i=m-1; i<n; ++i)
        if(ans[i]==m) num++;
    printf("%d\n", num);
    return 0;
}