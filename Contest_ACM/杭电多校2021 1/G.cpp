#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, x, ans1, ans2;

unordered_map<int, int> mp;

int ksm(int x, int y)
{
    int num=1;
    while(y) {
        if(y&1) num=1LL*num*x%P;
        x=1LL*x*x%P; y>>=1;
    }
    return num;
}

int bsgs(int a, int b)
{
    if(a%P==0) return (b==0)?1:-1;
    mp.clear();
    int siz=(int)(sqrt(P)+0.5), tmp=1LL*a*b%P;
    for(int i=1; i<=siz; ++i) {
        mp[tmp]=i;
        tmp=1LL*tmp*a%P;
    }
    int base=ksm(a, siz);
    tmp=1;
    for(int i=1; i<=siz; ++i) {
        tmp=1LL*tmp*base%P;
        if(mp[tmp]) return i*siz-mp[tmp];
    }
    return -1;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &x);
        if(x<=1) {
            printf("%d\n", x^1);
            continue;
        }
        LL tmp=1LL*x*n%P*ksm(n-1, P-2)%P;
        ans1=bsgs(n-1, (tmp+P-1)%P);
        ans2=bsgs(n-1, (tmp+1)%P);
        if(ans1==-1 || ans1%2==0) ans1=INF;
        if(ans2==-1 || ans2%2==1) ans2=INF;
        if(min(ans1, ans2)==INF) printf("-1\n");
        else printf("%d\n", min(ans1, ans2)+1);
    }
    return 0;
}