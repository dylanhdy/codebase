#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 1000005
#define INF 0x3f3f3f3f
#define LL long long
#define LD long double
#define P 998244353
#define G 3
#define IG 332748118
using namespace std;

int n, m, bit, a[MAXN*4], b[MAXN*4], pos[MAXN*4];

int ksm(int x, int y)
{
    int num=1;
    while(y) {
        if(y&1) num=1LL*num*x%P;
        x=1LL*x*x%P, y>>=1;
    }
    return num;
}

void ntt(int a[], int n, int op)
{
    for(int i=0; i<n; ++i)
        if(pos[i]>i) swap(a[pos[i]], a[i]);
    for(int i=1; i<n; i<<=1) {
        int wn=ksm(op>0?G:IG, (P-1)/(i<<1));
        for(int j=0; j<n; j+=(i<<1))
            for(int k=0, w=1; k<i; ++k, w=1LL*w*wn%P) {
                int x=a[j+k], y=1LL*a[i+j+k]*w%P;
                a[j+k]=(x+y)%P, a[i+j+k]=(x-y+P)%P;
            }
    }
    if(op>0) return;
    int inv=ksm(n, P-2);
    for(int i=0; i<n; ++i) a[i]=1LL*a[i]*inv%P;
}


int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=0; i<=m; ++i) scanf("%d", &b[i]);
    while((1<<bit)<=n+m) bit++;
    for(int i=0; i<(1<<bit); ++i)
        pos[i]=(pos[i>>1]>>1)|((i&1)<<(bit-1));
    ntt(a, 1<<bit, 1);
    ntt(b, 1<<bit, 1);
    for(int i=0; i<(1<<bit); ++i) a[i]=1LL*a[i]*b[i]%P;
    ntt(a, 1<<bit, -1);
    for(int i=0; i<=n+m; ++i) printf("%d ", a[i]);
    return 0;
}