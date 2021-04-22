#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P 200003
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

const double PI=acos(-1);

int n, bit, b[MAXN], val[MAXN], pow2[MAXN], pos[MAXN<<2];
LL ans;

struct CP {
    double x, y;
    friend CP operator * (CP a, CP b) {
        return CP{a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x};
    }
    friend CP operator + (CP a, CP b) {
        return CP{a.x+b.x, a.y+b.y};
    }
    friend CP operator - (CP a, CP b) {
        return CP{a.x-b.x, a.y-b.y};
    }
} a[MAXN<<2];

void fft(CP a[], int n, int op)
{
    for(int i=0; i<n; ++i)
        if(i<pos[i]) swap(a[i], a[pos[i]]);
    for(int i=1; i<n; i<<=1) {
        CP wn{cos(PI/i), op*sin(PI/i)};
        for(int j=0; j<n; j+=(i<<1)) {
            CP w{1, 0};
            for(int k=0; k<i; ++k, w=w*wn) {
                CP x=a[j+k], y=w*a[j+k+i];
                a[j+k]=x+y; a[j+k+i]=x-y;
            }
        }
    }
    if(op>0) return;
    for(int i=0; i<n; ++i) a[i].x/=n;
}
int main()
{
    scanf("%d", &n);
    val[1]=0; pow2[0]=1;
    for(int i=1; i<P; ++i) {
        pow2[i]=pow2[i-1]*2%P;
        val[pow2[i]]=i;
    }
    for(int i=1; i<=n; ++i) {
        scanf("%d", &b[i]);
        if(b[i]) a[val[b[i]]].x++;
    }
    while((1<<bit)<2*P) bit++;
    for(int i=0; i<(1<<bit); ++i)
        pos[i]=(pos[i>>1]>>1)|((i&1)<<(bit-1));
    fft(a, 1<<bit, 1);
    for(int i=0; i<(1<<bit); ++i) a[i]=a[i]*a[i];
    fft(a, 1<<bit, -1); 
    for(int i=0; i<(1<<bit); ++i)
        ans+=(LL)(a[i].x+0.5)*pow2[i%(P-1)];
    for(int i=1; i<=n; ++i) ans-=1LL*b[i]*b[i]%P;
    printf("%lld\n", ans/2);
    return 0;
}