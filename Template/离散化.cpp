#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, cnt, a[MAXN], b[MAXN], temp[MAXN*2], suba[MAXN], subb[MAXN];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d", &a[i], &b[i]);
        temp[i*2-1]=a[i], temp[2*i]=b[i];
    }
    sort(temp+1, temp+2*n+1);
    cnt=unique(temp+1, temp+2*n+1)-temp-1;
    for(int i=1; i<=n; ++i)
    {
        suba[i]=lower_bound(temp+1, temp+cnt+1, a[i])-temp;
        subb[i]=lower_bound(temp+1, temp+cnt+1, b[i])-temp;
    }
    // suba subb 离散化后数组
    return 0;
}