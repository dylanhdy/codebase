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
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, s, n, pw[10], ans[105];

int main()
{
    pw[0]=1;
    for(int i=1; i<10; ++i) pw[i]=pw[i-1]*10;
    scanf("%d", &T);
    while(T--) {
        memset(ans, 0, sizeof(ans));
        scanf("%d%d", &s, &n);
        int res=n, tmp=s;
        vector<int> d;
        while(tmp) d.PB(tmp%10), tmp/=10;
        for(int i=d.size()-1; i>=0; --i) {
            while(d[i] && res>=1) {
                if(s-pw[i]>=res-1) {
                    ans[res]+=pw[i], s-=pw[i];
                    d[i]--, res--;
                } else {
                    d[i-1]+=d[i]*10;
                    d[i]=0;
                } 
            }
        }
        ans[1]+=s;
        for(int i=1; i<=n; ++i) printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}