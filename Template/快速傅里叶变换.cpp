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
#define rint register int
#define LL long long
#define LD long double
using namespace std;

const double PI=acos(-1);

int bit, len, len1, len2, pos[MAXN*4], ans[MAXN*4];
char s1[MAXN], s2[MAXN];

struct CP
{
    double x, y;
    CP(double a=0, double b=0)
    {
        x=a; y=b;
    }
    friend CP operator * (CP a, CP b)
    {
        return CP(a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x);
    }
    friend CP operator + (CP a, CP b)
    {
        return CP(a.x+b.x, a.y+b.y);
    }
    friend CP operator - (CP a, CP b)
    {
        return CP(a.x-b.x, a.y-b.y);
    }
} a[MAXN*4], b[MAXN*4];

void fft(CP a[], int n, int op)
{
    for(int i=0; i<n; ++i)
        if(i<pos[i]) swap(a[i], a[pos[i]]);
    for(int i=1; i<n; i<<=1)
    {
        CP wn(cos(PI/i), op*sin(PI/i));
        for(int j=0; j<n; j+=(i<<1))
        {
            CP w(1, 0);
            for(int k=0; k<i; ++k, w=w*wn)
            {
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
    scanf("%s%s", s1, s2);
    len1=strlen(s1);
    len2=strlen(s2);
    for(int i=0; i<len1; ++i) a[i].x=s1[len1-1-i]-'0';
    for(int i=0; i<len2; ++i) b[i].x=s2[len2-1-i]-'0';
    while((1<<bit)<len1+len2) bit++;
    for(int i=0; i<(1<<bit); ++i) pos[i]=(pos[i>>1]>>1)|((i&1)<<(bit-1));
    fft(a, 1<<bit, 1), fft(b, 1<<bit, 1);
    for(int i=0; i<(1<<bit); ++i) a[i]=a[i]*b[i];
    fft(a, 1<<bit, -1);
    for(int i=0; i<(1<<bit); ++i)
    {
        ans[i]+=(int)(a[i].x+0.5);
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    for(len=len1+len2; !ans[len] && len>=1; len--) ;
    for(int i=len; i>=0; i--) printf("%d", ans[i]);
    return 0;
}