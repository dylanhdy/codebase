#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 2005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, a[MAXN];

int gcd(int x, int y)
{
    return y?gcd(y, x%y):x;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        int ans=0;
        vector<int> vec1, vec2;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            if(a[i]%2==0) vec1.PB(a[i]);
            else vec2.PB(a[i]);
        }
        for(int i=0; i<vec1.size(); ++i) ans+=n-i-1;
        for(int i=0; i<vec2.size(); ++i)
            for(int j=i+1; j<vec2.size(); ++j)
                if(gcd(vec2[i], vec2[j])>1) ans++;
        printf("%d\n", ans);
    }
    return 0;
}