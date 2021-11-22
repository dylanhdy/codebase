#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#define LL long long
#define LD long double
#define MAXN 100005
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int T, n, a[MAXN], l[MAXN], r[MAXN], len[MAXN];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            l[i]=a[i], r[i]=a[i]; len[i]=1;
        }
        int add=0, ans=0;
        for(int i=2; i<=n; ++i) {
            for(int j=i-1; j>=1; --j) {
                if(r[j]>l[j+1]) {
                    int tmp=(a[j]+l[j+1]-1)/l[j+1];
                    add=(add+1LL*j*(tmp-len[j]))%P;
                    len[j]=tmp;
                    l[j]=(a[j]/tmp), r[j]=(a[j]+tmp-1)/tmp;
                    //printf("%d %d %d %d %d %d??\n", i, j, tmp, len[j], l[j], r[j]);
                } else break;
            }
            //printf("%d %d??\n", i, add);
            ans=(ans+add)%P;
        }
        printf("%d\n", ans);
    }
    return 0;
}