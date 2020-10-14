#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 6005
#define Pi acos(-1)
#define INF 0x3f3f3f3f
#define mp make_pair
using namespace std;

const int dy[6]={0, 0, -3, -3, 3, 3};
const int dx[6]={-2, 2, -1, 1, -1, 1};

int t, r, c, sx, sy, dis[MAXN][MAXN];
char map[MAXN][MAXN];

queue<pair<int, int> > q;

int bfs()
{
    dis[sx][sy]=1;
    q.push(make_pair(sx, sy));
    while(!q.empty())
    {
        int x=q.front().first, y=q.front().second;
        q.pop();
        if(map[x][y]=='T') return dis[x][y];
        for(int i=0; i<6; ++i)
            if(map[x+dx[i]][y+dy[i]]==' ')
            {
                int tx=x+dx[i]*2, ty=y+dy[i]*2;
                if(!dis[tx][ty])
                {
                    dis[tx][ty]=dis[x][y]+1;
                    q.push(make_pair(tx, ty));
                }
            }
    
    }
    return -1;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &r, &c);
        getchar();
        for(int i=1; i<=4*r+3; ++i) gets(map[i]);
        for(int i=1; i<=4*r+3; ++i)
            for(int j=1; j<=6*c+3; ++j)
            {
                if(map[i][j]=='S') sx=i, sy=j;
                dis[i][j]=0;
            }
        while(!q.empty()) q.pop();
        printf("%d\n", bfs());
    }
    return 0;
}