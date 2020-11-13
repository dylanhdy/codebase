#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 1005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int T, n, m, a, b, mp[MAXN][MAXN], num[MAXN][MAXN], add[MAXN][MAXN];

bool solve()
{
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            add[i][j]+=add[i-1][j];
            num[i][j]=num[i][j-1]+add[i][j];
            if(num[i][j]>mp[i][j]) return false;
            if(i+a-1>n || j+b-1>m)
            {
                if(num[i][j]!=mp[i][j]) return false;
            }
            else
            {
                int temp=mp[i][j]-num[i][j];
                add[i][j]+=temp;
                add[i+a][j]-=temp;
                add[i][j+b]-=temp;
                add[i+a][j+b]+=temp;
                num[i][j]+=temp;
            }
        }
    return true;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d%d", &n, &m, &a, &b);
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
            {
                scanf("%d", &mp[i][j]);
                add[i][j]=num[i][j]=0;
            }
        if(solve()) printf("^_^\n");
        else printf("QAQ\n");
    }   
    return 0;
}