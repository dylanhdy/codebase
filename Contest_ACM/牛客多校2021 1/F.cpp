#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
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
 
LL T, l, r, ans;
 
int a[]={1, 2, 4, 5, 7, 8, 11, 14, 17, 41, 44, 47, 71, 74, 77, 22, 25, 28, 52, 55, 58, 82, 85, 88};
 
int main()
{
    scanf("%lld", &T);
    while(T--) {
        scanf("%lld%lld", &l, &r);
        ans=r-l+1;
        for(int i=0; i<24; ++i)
            if(a[i]>=l && a[i]<=r) ans--;
        printf("%lld\n", ans);
    }
    return 0;
}