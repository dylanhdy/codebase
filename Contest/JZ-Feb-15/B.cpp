#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 100005
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, k, q, rpos, cpos[MAXN], b[MAXN];

struct A {int op, x;} a[MAXN];

int main()
{
    scanf("%d%d%d", &n, &k, &q);
    for(rint i=0; i<q; ++i)
    {
        scanf("%d%d", &a[i].op, &a[i].x);
        if(a[i].op==1)
        {
            rpos=((rpos+a[i].x)%k+k)%k;
        }
        else
        {
            a[i].x=(a[i].x%n+n)%n;
            int c=a[i].x/k, r=a[i].x%k;
            cpos[0]+=c;
            cpos[k-rpos]--;
            if(k-rpos-r>=0) cpos[k-rpos-r]++;
            else cpos[2*k-rpos-r]++, cpos[0]++;
            rpos=(rpos+r)%k;
        }
    }
    for(rint i=0; i<n; ++i) scanf("%d", &b[i]);
    for(rint i=0; i<n; ++i)
    {
        cpos[i]=(cpos[i]%(n/k)+(n/k))%(n/k);
        if(i) cpos[i]=(cpos[i]+cpos[i-1])%(n/k); 
    }
    for(rint i=0; i<n/k; ++i)
        for(rint j=0; j<k; ++j)
        {
            int c=(cpos[j]+i)%(n/k);
            int r=(j+rpos)%k;
            printf("%d ", b[c*k+r]);
        }
    return 0;
}
