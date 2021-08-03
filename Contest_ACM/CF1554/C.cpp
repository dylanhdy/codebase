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

int T, k, n, m;
LL ans;

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);

        vector<pair<int, int> > vec;
        int l=0;
        for(int i=30; i>=0; --i) {
            int ch=((n>>i)&1);
            if((m>>i)&1) {
                int tmp=l+(1<<i)*ch;
                //printf("%d %d\n", tmp, tmp+(1<<i));
                vec.PB(MP(tmp, tmp+(1<<i)-1));
                l|=(1<<i)*(1-ch);
            } else {
                l|=(1<<i)*ch;
            }
        }
        vec.PB(MP(l, l));
        sort(vec.begin(), vec.end());
        if(vec[0].first!=0) {
            printf("0\n");
            continue;
        }
        int ans;
        for(ans=0; ans+1<vec.size(); ++ans)
            if(vec[ans].second+1!=vec[ans+1].first) break;
        printf("%d\n", vec[ans].second+1);
    }
    return 0;
}