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
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

const int cost[]={1, 6, 28, 88, 198, 328, 648};
const int val[]={8, 18, 28, 58, 128, 198, 388};

int n, ans;

int main()
{
    scanf("%d", &n);
    for(int sta=0; sta<(1<<7); ++sta)
    {
        int t1=0, t2=0;
        for(int i=0; i<7; ++i)
            if((sta>>i)&1) t1+=val[i], t2+=cost[i];
        if(t2<=n) ans=max(t1, ans);
    }
    printf("%d\n", n*10+ans);
    return 0;
}