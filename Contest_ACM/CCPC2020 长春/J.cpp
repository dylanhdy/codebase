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
#define P 1000000007
#define BASE 1023
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, m, lim1, lim2, ans, val1[35], val2[35], f[MAXN][MAXN];
vector<int> vec[MAXN];

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i) {
        int c, r;
        scanf("%d%d", &c, &r);
        vec[r+c].PB(r*2);
    }
    for(int sta=0; sta<=31; ++sta) {
        int maxr=-1;
        for(int i=0; i<5; ++i)
            if((sta>>i)&1) {
                val1[sta]|=(1<<(i*2+1));
                maxr=max(maxr, i);
            }
        for(int i=0; i<(maxr*2+1); ++i) val2[sta]|=(1<<i);
    }
    f[0][BASE]=1;
    for(int i=1; i<=n; ++i) {
        sort(vec[i].begin(), vec[i].end());
        lim1=0;
        int temp=INF;
        for(int j=i+1; j<=i+10; ++j)
            for(int k=0; k<vec[j].size(); ++k)
                if(j-vec[j][k]<i) temp=min(temp, i-j+vec[j][k]);
        for(int j=temp; j<10; ++j) lim1|=(1<<j);
        for(int j=0; j<vec[i].size(); ++j) lim1|=(1<<(vec[i][j]-1));
        //printf("%d %d\n", i, lim1);
        for(int sta1=0; sta1<=BASE; ++sta1) {
            int temp1=lim1|lim2|((sta1<<1)&BASE);
            for(int sta2=0; sta2<=31; ++sta2) {
                if(!(val1[sta2]&temp1)) {
                    int temp2=((sta1<<1)&BASE)|val2[sta2];
                    //if(f[i-1][sta1]) printf("%d %d %d %d\n", i, sta1, sta2, f[i-1][sta1]);
                    f[i][temp2]=(f[i][temp2]+f[i-1][sta1])%P;
                }
            }
        }
        if(vec[i].size())
            for(int j=0; j<vec[i].back()-1; ++j) lim2|=(1<<j);
        lim2=(lim2<<1)&BASE;
    }
    for(int i=0; i<=BASE; ++i) ans=(ans+f[n][i])%P;
    printf("%d\n", ans);
    return 0;
}
/*
10 1
3 1
*/