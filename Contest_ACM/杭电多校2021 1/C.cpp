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
#define MAXN 405
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, m, tot, a[MAXN][MAXN], pw[MAXN], id[22][22];
char mp[22][22];

const int dx[]={0, 1, 0, -1};
const int dy[]={1, 0, -1, 0};

int solve()
{
    int c=1, r=1;
    for(; c<=tot; ++c) {
        int pos=0;
        for(int i=r; i<=tot; ++i)
            if(a[i][c]!=0) pos=i;
        if(pos==0) continue;
        for(int i=c; i<=tot+1; ++i) swap(a[r][i], a[pos][i]);
        for(int i=1; i<=tot; ++i) {
            if(r==i || !a[i][c]) continue;
            for(int j=tot+1; j>=c; --j) a[i][j]^=a[r][j];
        }
        r++;
    }
    for(int i=r; i<=tot; ++i)
        if(a[i][tot+1]) return -1;
    return tot-r+1;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        tot=0;
        memset(a, 0, sizeof(a));
        scanf("%d%d", &n, &m);
        for(int i=1; i<n; ++i)
            for(int j=1; j<m; ++j) id[i][j]=++tot;
        for(int i=1; i<n; ++i) {
            scanf("%s", mp[i]+1);
            for(int j=1; j<m; ++j) {
                if(mp[i][j]=='.') continue;
                for(int k=0; k<4; ++k) {
                    int x=i+dx[k], y=j+dy[k];
                    if(x>=1 && y>=1 && x<n && y<m)
                        a[id[i][j]][id[x][y]]=1;
                }
                a[id[i][j]][tot+1]=mp[i][j]-'0';
            }
        }
        int ans=solve();
        if(ans==-1) printf("0\n");
        else {
            pw[0]=1;
            for(int i=1; i<=ans; ++i) pw[i]=pw[i-1]*2%P;
            printf("%d\n", pw[ans]);
        }
        fflush(stdout);
    }
    return 0;
}