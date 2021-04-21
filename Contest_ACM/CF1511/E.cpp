#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#define LL long long
#define LD long double
#define MAXN 300005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, ans, cnt, pow2[MAXN], f[MAXN][2], suf[MAXN];
string mp[MAXN], temp;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    pow2[0]=1;
    for(int i=1; i<=n; ++i) {
        mp[i]="*";
        cin>>temp;
        mp[i]+=temp;
        for(int j=1; j<=m; ++j) cnt+=(mp[i][j]=='o');
    }
    for(int i=1; i<=cnt; ++i) pow2[i]=1LL*pow2[i-1]*2%P;
    for(int i=1; i<=n; ++i) {
        f[0][0]=1; f[0][1]=0;
        for(int j=m; j>=1; --j) {
            suf[j]=suf[j+1]+(mp[i][j]=='o');
            f[j][0]=f[j][1]=0;
        }
        for(int j=1; j<=m; ++j) {
            if(mp[i][j]=='*') f[j][0]=(f[j-1][0]+f[j-1][1])%P;
            else {
                f[j][0]=(1LL*f[j-1][1]*2%P+f[j-1][0])%P;
                f[j][1]=f[j-1][0];
            }
            if(mp[i][j]=='o' && mp[i][j-1]=='o') ans=(ans+1LL*f[j-2][0]*pow2[cnt-suf[1]+suf[j+1]]%P)%P;
        }
    }
    memset(suf, 0, sizeof(suf));
    for(int i=1; i<=m; ++i) {
        f[0][0]=1; f[0][1]=0;
        for(int j=n; j>=1; --j) {
            suf[j]=suf[j+1]+(mp[j][i]=='o');
            f[j][0]=f[j][1]=0;
        }
        for(int j=1; j<=n; ++j) {
            if(mp[j][i]=='*') f[j][0]=(f[j-1][0]+f[j-1][1])%P;
            else {
                f[j][0]=(1LL*f[j-1][1]*2%P+f[j-1][0])%P;
                f[j][1]=f[j-1][0];
            }
            if(mp[j][i]=='o' && mp[j-1][i]=='o') {
                //printf("%d %d %d %d\n", i, j, f[j-2][0], pow2[cnt-suf[1]+suf[j+1]]);
                ans=(ans+1LL*f[j-2][0]*pow2[cnt-suf[1]+suf[j+1]]%P)%P;
            }
                
        }
    }
    printf("%d\n", ans);
    return 0;
}