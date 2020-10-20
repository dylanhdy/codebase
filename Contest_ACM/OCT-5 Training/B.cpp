#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int t, hpa, hpb, atka, atkb;

int divide1(LL lim)
{
    int l=0, r=100000, ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(1LL*mid*(mid+1)/2>=lim) ans=mid, r=mid-1;
        else l=mid+1;
    }
    return ans;
}

int divide2(LL lim)
{
    int l=0, r=100000, ans=100000;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(1LL*mid*(mid+1)/2<=lim) ans=mid, l=mid+1;
        else r=mid-1;
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        string stra, strb;
        scanf("%d%d%d%d", &hpa, &hpb, &atka, &atkb);
        LL n=divide1(hpa+hpb), numa=divide1(hpa), numb=divide1(hpb);
        LL ansa=numa*atka+n*atkb, ansb=numb*atkb+n*atka;
        if(ansa<=ansb)
        {
            int resb=hpb-(n+numa+1)*(n-numa)/2, resa=(numa+1)*numa/2-hpa;
            if(resb<=0)
            {
                for(int i=1; i<=numa; ++i) stra+='A';
                for(int i=numa+1; i<=n; ++i) stra+='B';
            }
            else
            {
                for(int i=1; i<=numa; ++i) stra+=(i==resa?'B':'A');
                for(int i=numa+1; i<=n; ++i) stra+='B';
            }
        }
        if(ansb<=ansa)
        {
            int resb=(numb+1)*numb/2-hpb, resa=hpa-(n+numb+1)*(n-numb)/2;
            int m=divide2(resb);
            resb-=m*(m+1)/2, resa-=m*(m+1)/2;
            //printf("%d %d %d\n", m, resa, resb);
            if(resa>0)
            {
                for(int i=1; i<m; ++i) strb+='A';
                for(int i=m; i<=numb; ++i) strb+=(i==resa+m?'A':'B');
            }
            else
            {
                for(int i=1; i<=m; ++i) strb+='A';
                for(int i=m+1; i<=numb; ++i) strb+='B';
            }
            for(int i=numb+1; i<=n; ++i) strb+='A';
        }
        if(ansa<ansb) printf("%lld %s\n", ansa, stra.c_str());
        if(ansb<ansa) printf("%lld %s\n", ansb, strb.c_str());
        if(ansa==ansb) printf("%lld %s\n", ansa, stra<strb?stra.c_str():strb.c_str());
    }
    return 0;
}