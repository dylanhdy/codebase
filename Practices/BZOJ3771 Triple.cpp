#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN (1<<17)+10
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;
 
const double PI=acos(-1);
 
int n, bit, maxn, pos[MAXN];
 
struct Cp
{
    double x, y;
    Cp(double a=0, double b=0) {x=a, y=b;}
    Cp friend operator + (Cp a, Cp b)
    {
        return Cp(a.x+b.x, a.y+b.y);
    }
    Cp friend operator - (Cp a, Cp b)
    {
        return Cp(a.x-b.x, a.y-b.y);
    }
    Cp friend operator * (Cp a, Cp b)
    {
        return Cp(a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x);
    }
    Cp friend operator / (Cp a, double b)
    {
        return Cp(a.x/b, a.y/b);
    }
} a1[MAXN], a2[MAXN], a3[MAXN], ans[MAXN];
 
void fft(Cp a[], int n, int op)
{
    for(rint i=0; i<n; ++i)
        if(pos[i]<i) swap(a[pos[i]], a[i]);
    for(rint i=1; i<n; i<<=1)
    {
        Cp wn(cos(PI/i), op*sin(PI/i));
        for(rint j=0; j<n; j+=(i<<1))
        {
            Cp w(1, 0);
            for(rint k=0; k<i; ++k, w=w*wn)
            {
                Cp x=a[j+k], y=w*a[i+j+k];
                a[j+k]=x+y, a[i+j+k]=x-y;
            }
        }
    }
    if(op==-1)
        for(rint i=0; i<n; ++i) a[i].x/=n;
}
 
int main()
{
    scanf("%d", &n);
    for(rint i=1, x; i<=n; ++i)
    {
        scanf("%d", &x);
        a1[x].x++, a2[x*2].x++, a3[x*3].x++;
        maxn=max(maxn, x*3);
    }
    while((1<<bit)<maxn) bit++;
    for(rint i=0; i<(1<<bit); ++i) pos[i]=(pos[i>>1]>>1)|((i&1)<<(bit-1));
    fft(a1, 1<<bit, 1);
    fft(a2, 1<<bit, 1);
    fft(a3, 1<<bit, 1);
    for(rint i=0; i<(1<<bit); ++i)
    {
        ans[i]=a1[i]*a1[i]*a1[i]/6;
        ans[i]=ans[i]+(a1[i]*a1[i]-a2[i]*a1[i]-a2[i])/2;
        ans[i]=ans[i]+a1[i]+a3[i]/3;
    }
    fft(ans, 1<<bit, -1);
    for(rint i=0; i<(1<<bit); ++i)
        if(ans[i].x>0.5) printf("%d %d\n", i, int(ans[i].x+0.5));
    return 0;
}
