#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int t, n, a[MAXN], b[MAXN];
char s[MAXN];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        int pos=n, dif=0, flag=1;
        for(int i=2; i<=n; ++i)
            if(a[i]>a[i-1])
            {
                dif=a[i-1];
                pos=i;
                break;
            }
        for(int i=pos; i<n; ++i)
            if(a[i]>a[i+1])
            {
                int res=a[i]-a[i+1];
                if(res<=dif) dif-=res;
                else
                {
                    flag=0;
                    break;
                }
            }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}