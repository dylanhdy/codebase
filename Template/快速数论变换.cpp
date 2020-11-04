#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

void ntt(int a[], int n, int op)
{
    for(int i=0; i<n; ++i)
        if(pos[i]>i) swap(a[pos[i]], a[i]);
    for(rint i=1; i<n; i<<=1)
    {
        int wn=ksm(G, op>0?(P-1)/(i<<1):P-1-(P-1)/(i<<1));
        for(rint j=0; j<n; j+=(i<<1))
            for(rint k=0, w=1; k<i; ++k, w=1LL*w*wn%P)
            {
                int x=a[j+k], y=1LL*a[i+j+k]*w%P;
                a[j+k]=add(x, y), a[i+j+k]=sub(x, y);
            }
    }
    if(op>0) return;
    int inv=ksm(n, P-2);
    for(int i=0; i<n; ++i) a[i]=1LL*a[i]*inv%P;
}

int main()
{
    
    return 0;
}