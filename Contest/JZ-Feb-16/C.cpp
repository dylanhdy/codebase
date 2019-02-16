#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int m, p, ans, len, f[40][40], a[40][40], temp[40][40];
char n[105];

void mul(int x[40][40], int y[40][40])
{
    memset(temp, 0, sizeof(temp));
    for(rint i=0; i<(1<<m); ++i)
        for(rint j=0; j<(1<<m); ++j)
            for(rint k=0; k<(1<<m); ++k)
                temp[i][j]=(temp[i][j]+x[i][k]*y[k][j]%p)%p;
    memcpy(x, temp, sizeof(temp));
}

void div(char *n)
{
    for(rint i=len-1; i>=0; --i)
    {
        if(n[i]%2 && i) n[i]--, n[i-1]+=10;
        n[i]/=2;
    }
    while(!n[len-1]) len--;
}

void sub(char *n)
{
    n[0]--;
    for(rint i=0; n[i]<0; ++i)
    {
        n[i]+=10, n[i+1]--;
    }
    while(!n[len-1]) len--;
}

void ksm()
{
    while(len>0)
    {
        if(n[0]&1) mul(a, f);
        mul(f, f), div(n);
    }
}

bool check(int x, int y)
{
    for(rint i=1; i<m; ++i)
    {
        int a=((x>>i)&1), b=((x>>(i-1))&1);
        int c=((y>>i)&1), d=((y>>(i-1))&1);
        if(a==b && b==c && c==d) return false;
    }
    return true;
}

int main()
{
    scanf("%s%d%d", n, &m, &p);
    len=strlen(n);
    reverse(n, n+len);
    for(rint i=0; i<len; ++i) n[i]=n[i]-'0';
    for(rint i=0; i<(1<<m); ++i)
        for(rint j=0; j<(1<<m); ++j) f[i][j]=check(i, j);
    for(rint i=0; i<(1<<m); ++i) a[0][i]=1;
    sub(n);
    ksm();
    for(rint i=0; i<(1<<m); ++i) ans=(ans+a[0][i])%p;
    printf("%d\n", ans);
    return 0;
}
