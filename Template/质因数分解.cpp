#include <bits/stdc++.h>
#define LL long long
#define I128 __int128
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

const LL base[]={2, 325, 9375, 28178, 450775, 9780504, 1795265022};

LL n;
map<LL, int> mp;

LL ksm(LL x, LL y, LL p)
{
    LL num=1;
    while(y) {
        if(y&1) num=(I128)num*x%p;
        y>>=1, x=(I128)x*x%p;
    }
    return num;
}

bool MR(LL x)
{
    if(x<=2) return x==2;
    if(x%2==0) return false;
    LL d=x-1, r=0;
    while(d%2==0) d/=2, r++;
    for(auto e: base) {
        LL v=ksm(e, d, x);
        if(v<=1 || v==x-1) continue;
        for(int i=0; i<r-1; ++i) {
            v=(I128)v*v%x;
            if(v==x-1) break;
        }
        if(v!=x-1) return false;
    }
    return true;
}

LL PR(LL x)
{
    if(x==4) return 2;
    LL l=0, r=0, c=rand()%(x-1)+1, val;
    while(true) {
        val=1;
        for(int i=0; i<128; ++i) {
            l=((I128)l*l+c)%x;
            r=((I128)r*r+c)%x, r=((I128)r*r+c)%x;
            if(l==r || val*abs(l-r)%x==0) break;
            val=(I128)val*abs(l-r)%x;
        }
        LL d=__gcd(val, x);
        if(d>1) return d;
        if(l==r) return x;
    }
}

void find(LL x, int num)
{
    if(x<=1) return;
    if(MR(x)) {
        mp[x]+=num;
        return;
    }
    LL y=x, cnt=0;
    while(y==x) y=PR(x);
    while(x%y==0) x/=y, cnt++;
    find(x, num), find(y, cnt*num);
}

int main()
{
    srand(time(0));
    scanf("%lld", &n);
    find(n, 1);
    for(auto e: mp) printf("%lld %dn", e.first, e.second);
    return 0;
}