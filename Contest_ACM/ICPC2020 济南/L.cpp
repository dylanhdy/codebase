#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 505
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, a[MAXN], b[MAXN], c[MAXN], num[10], g[MAXN][2];
LL ans, m, l, f[MAXN][2];

int solve(int m)
{
    int num=0;
    for(int i=0; i<m; ++i) {
        int flag=1;
        for(int j=0; j<n; ++j)
            if(i+j>=m || a[j]!=c[i+j]) {
                flag=0;
                break;
            }
        num+=flag;   
    }
    return num;  
}

inline int id(int x, int y)
{
    return 2+x*2+y;
}

void dfs(int x, int y)
{
    if(f[x][y]!=-1) return;
    if(x==0) {
        f[x][y]=num[y];
        g[x][y]=y;
        return;
    }
    dfs(x-1, y);
    dfs(x-1, y^1);
    f[x][y]=f[x-1][y]+f[x-1][y^1]+num[id(g[x-1][y], y^1)];
    g[x][y]=g[x-1][y^1];
}

int main()
{
    for(int i=0; i<128; ++i)
        for(int j=0; j<=10; ++j)
            if((i>>j)&1) b[i]^=1;
    scanf("%d", &T);
    while(T--) {
        ans=0;
        memset(f, -1, sizeof(f));
        memset(g, -1, sizeof(g));
        scanf("%d%lld", &n, &l);
        for(int i=0; i<n; ++i) scanf("%d", &a[i]);
        m=(l+n)/128;
        l=(l+n)%128;
        for(int i=0; i<2; ++i) {
            for(int j=0; j<128; ++j) c[j]=(b[j]^i);
            num[i]=solve(128);
        }
        for(int i=0; i<2; ++i)
            for(int j=0; j<2; ++j) {
                for(int k=0; k<128; ++k) c[k]=(b[k]^i);
                for(int k=0; k<128; ++k) c[k+128]=(b[k]^j);
                num[id(i, j)]=solve(256)-num[i]-num[j];
            }
        if(m==0) {
            for(int i=0; i<l; ++i) c[i]=b[i];
            printf("%d\n", solve(l));
            continue;
        } 
        int last=-1, tag=0;
        for(int i=59; i>=0; --i)
            if((m>>i)&1) {
                if(last!=-1) ans+=num[id(last, tag)];
                dfs(i, tag);
                ans+=f[i][tag];
                last=g[i][tag];
                tag^=1;
            }
        for(int i=0; i<128; ++i) c[i]=(b[i]^last);
        for(int i=0; i<l; ++i) c[i+128]=(b[i]^tag);
        ans+=solve(128+l)-num[last];
        printf("%lld\n", ans);
    }
    return 0;
}
/*
0110100110010110100101100110100110010110011010010110100110010110100101100110100101101001100101100110
*/