#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, m, val[10][10];

int ksm(int x, int y)
{
    int num=1;
    while(y) {
        if(y&1) num=1LL*num*x%P;
        y>>=1, x=1LL*x*x%P;
    }
    return num;
}

int main()
{
    val[2][2]=66;
    val[2][3]=390;
    val[2][4]=1800;
    val[2][5]=6120;
    val[2][6]=13680;
    val[2][7]=15120;
    val[3][2]=390;
    val[3][3]=3198;
    val[3][4]=13176;
    val[3][5]=27000;
    val[3][6]=13680;
    val[3][7]=15120;
    val[4][2]=1800;
    val[4][3]=13176;
    val[4][4]=24336;
    val[4][5]=4320;
    val[4][6]=0;
    val[4][7]=0;
    val[5][2]=6120;
    val[5][3]=27000;
    val[5][4]=4320;
    val[5][5]=4320;
    val[5][6]=0;
    val[5][7]=0;
    val[6][2]=13680;
    val[6][3]=13680;
    val[6][4]=0;
    val[6][5]=0;
    val[6][6]=0;
    val[6][7]=0;
    val[7][2]=15120;
    val[7][3]=15120;
    val[7][4]=0;
    val[7][5]=0;
    val[7][6]=0;
    val[7][7]=0;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        if(n==1 || m==1) {
            printf("0\n");
        } else if(n<=7 && m<=7) {
            printf("%d\n", (ksm(3, n*m)-val[n][m]+P)%P);
        } else {
            printf("%d\n", ksm(3, n*m));
        }
    }
}


/*
int n, m, ans, col[10][10];

bool check(int x, int y)
{
    for(int i=1; i<x; ++i)
        if(col[i][y]==col[x][y])
            for(int j=1; j<y; ++j)
                if(col[i][j]==col[x][j]) return 0;
    for(int i=1; i<y; ++i)
        if(col[x][i]==col[x][y])
            for(int j=1; j<x; ++j)
                if(col[j][i]==col[j][y]) return 0;
    return 1;
}

void dfs(int x, int y)
{
    if(x==n+1) {
        ans++;
        return;
    }
    for(int i=1; i<=3; ++i) {
        col[x][y]=i;
        if(check(x, y)) {
            if(y==m) dfs(x+1, 1);
            else dfs(x, y+1);
        }
    }
}

int main()
{
    for(n=2; n<=7; ++n)
        for(m=2; m<=7; ++m) {
            ans=0;
            dfs(1, 1);
            printf("val[%d][%d]=%d;\n", n, m, ans);
        }
    
    return 0;
}
*/