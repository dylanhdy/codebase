#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int t, n, a[MAXN], b[MAXN];

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int flag=1, val1=-1, val2=-1;
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        for(int i=2; i<=n; ++i)
            if(a[i]>=a[i-1]) {
                if(val1!=-1 && a[i]-a[i-1]!=val1) flag=0;
                else val1=a[i]-a[i-1];
            }
        for(int i=2; i<=n; ++i)
            if(a[i-1]>a[i]) {
                if(val2!=-1 && a[i-1]-a[i]!=val2) flag=0;
                else val2=a[i-1]-a[i];
            }
        if(!flag) {
            printf("-1\n");
            continue;
        }
        if(val2==-1 || val1==-1) {
            printf("0\n");
            continue;
        }
        b[1]=a[1]%(val1+val2);
        if(a[1]!=b[1]) flag=0;
        for(int i=2; i<=n; ++i) {
            b[i]=(b[i-1]+val1)%(val1+val2);
            if(b[i]!=a[i]) flag=0;
        }
        if(!flag) printf("-1\n");
        else printf("%d %d\n", val1+val2, val1);
    }
    return 0;
}