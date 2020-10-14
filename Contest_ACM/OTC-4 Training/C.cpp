#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#define LL long long
#define MAXN 1005
#define P 1000000007
using namespace std;

const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, 1, 0, -1};

int n, m, ans, map[MAXN][MAXN], in[MAXN][MAXN], out[MAXN][MAXN], val[MAXN][MAXN][5];

queue<pair<int, int> > q;

inline int add(int x, int y)
{
    if(x+y>=P) return x+y-P;
    else return x+y;
}

int main()
{
    memset(map, 0x3f, sizeof(map));
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) scanf("%d", &map[i][j]);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            for(int k=0; k<4; ++k)
                if(map[i+dx[k]][j+dy[k]]-map[i][j]==1)
                {
                    in[i+dx[k]][j+dy[k]]++;
                    out[i][j]++;
                }
        }
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(!in[i][j])
            {
                q.push(make_pair(i, j));
                val[i][j][1]=1;
            }
    while(!q.empty())
    {
        int x=q.front().first, y=q.front().second;
        q.pop();
        if(out[x][y]==0) ans=add(ans, val[x][y][4]);
        //printf("%d %d %d %d %d %d!!\n", x, y, val[x][y][1], val[x][y][2], val[x][y][3], val[x][y][4]);
        for(int k=0; k<4; ++k)
        {
            int tx=x+dx[k], ty=y+dy[k];
            if(map[tx][ty]-map[x][y]!=1) continue;
            //printf("%d %d %d %d?\n", x, y, tx, ty);
            for(int i=1; i<=3; ++i) val[tx][ty][i+1]=add(val[tx][ty][i+1], val[x][y][i]);
            val[tx][ty][4]=add(val[tx][ty][4], val[x][y][4]);
            in[tx][ty]--;
            if(!in[tx][ty]) q.push(make_pair(tx, ty));
        }
    }
    printf("%d\n", ans);
    return 0;
}