#include <bits/stdc++.h>
using namespace std;

int a, b, x, p;

unordered_map<int, int> mp;

int ksm(int x, int y)
{
    int num=1;
    while(y) {
        if(y&1) num=1LL*num*x%p;
        x=1LL*x*x%p; y>>=1;
    }
    return num;
}

int bsgs(int a, int b)
{
    if(a%p==0) return (b==0)?1:-1;
    mp.clear();
    int siz=sqrt(p)+0.5, tmp=1LL*a*b%p;
    for(int i=1; i<=siz; ++i) {
        mp[tmp]=i;
        tmp=1LL*tmp*a%p;
    }
    int base=ksm(a, siz);
    tmp=1;
    for(int i=1; i<=siz; ++i) {
        tmp=1LL*tmp*base%p;
        if(mp[tmp]) return i*siz-mp[tmp];
    }
    return -1;
}

int main()
{
    scanf("%d%d%d", &a, &b, &p);
    x=bsgs(a, b);
    if(x==-1) printf("No solution\n");
    else printf("%d\n", x);
}