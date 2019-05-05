#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 15
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;
 
int n, m, cnt1, cnt2, dgt1[MAXN], dgt2[MAXN], nxt[MAXN];
double val[MAXN][MAXN], f[MAXN][MAXN];
 
double dfs(int x, int num, int lim, int lead)
{
    if(x>cnt1) return lead;
    if(!lim && lead && f[x][num]) return f[x][num];
    double temp=0;
    for(rint i=0; i<=(lim?dgt1[x]:9); ++i)
    {
        int p=num;
        if(i==0 && !lead) p=0;
        else
        {
            while(p && dgt2[p+1]!=i) p=nxt[p];
            if(dgt2[p+1]==i) p++;
        }
        if(p!=cnt2) temp+=val[cnt1-x][i]*dfs(x+1, p, lim && (i==dgt1[x]), lead || (i>0));
    }
    if(!lim && lead) f[x][num]=temp;
    return temp;
}
 
int main()
{
    scanf("%d%d", &n, &m);
    for(LL i=0, Pow=1; i<=10; ++i, Pow*=10)
        for(rint j=0; j<10; ++j) val[i][j]=exp(1.0*Pow*j/n);
    if(!n) dgt1[++cnt1]=0;
    while(n) dgt1[++cnt1]=n%10, n/=10;
    reverse(dgt1+1, dgt1+cnt1+1);
    if(!m) dgt2[++cnt2]=0;
    while(m) dgt2[++cnt2]=m%10, m/=10;
    reverse(dgt2+1, dgt2+cnt2+1);
    for(rint i=2, p=0; i<=cnt2; ++i)
    {
        while(p && dgt2[i]!=dgt2[p+1]) p=nxt[p];
        if(dgt2[i]==dgt2[p+1]) p++;
        nxt[i]=p;
    }
    printf("%.3f\n", dfs(1, 0, 1, 0));
    return 0;
}