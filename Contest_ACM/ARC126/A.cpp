#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        LL a, b, c, ans=0;
        scanf("%lld%lld%lld", &a, &b, &c);
        LL tmp=min(b/2, c);
        b-=tmp*2, c-=tmp, ans+=tmp;
        
        tmp=min(b/2, a/2);
        a-=tmp*2, b-=tmp*2, ans+=tmp;
        
        tmp=min(c/2, a);
        c-=tmp*2, a-=tmp, ans+=tmp;

        tmp=min(a/3, c);
        c-=tmp, a-=tmp*3, ans+=tmp;

        ans+=a/5;
        
        printf("%lld\n", ans);
    }
    return 0;
}