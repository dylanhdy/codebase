#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int T, n, m, mp[MAXN][MAXN], vis[MAXN][MAXN][4];

const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, 1, 0, -1};
const int type[4][4]={
    {5, 1, -1, 0},
    {3, 4, 0, -1},
    {-1, 2, 5, 3},
    {2, -1, 1, 4}
};

struct Sta {int x, y, dir;} pre[MAXN][MAXN][4];

bool check(int x, int y, int dir)
{
    if(x==n+1 && y==m && dir==0) return true;
    if(x<1 || x>n || y<1 || y>m || vis[x][y][dir]) return false;
    return true;
}

void print(Sta sta, int step)
{
    int x=sta.x, y=sta.y, dir=sta.dir;
    if(x==1 && y==1 && dir==0) {
        printf("%d\n", step*2);
        return;
    }
    Sta psta=pre[x][y][dir];
    print(psta, step+1);
    int px=psta.x, py=psta.y, pdir=psta.dir;
    int tmp=type[pdir][dir];
    if(tmp<4)
        printf("1 %d %d %d\n", (tmp-mp[px][py]+4)%4*90, px, py);
    else
        printf("1 %d %d %d\n", (tmp-mp[px][py]+2)%2*90, px, py);
    mp[px][py]=tmp;
    printf("0 %d %d\n", px, py);
}

bool bfs()
{
    queue<Sta> q;
    q.push(Sta{1, 1, 0});
    vis[1][1][0]=1;
    while(!q.empty()) {
        int x=q.front().x, y=q.front().y, dir=q.front().dir;
        q.pop();
        if(mp[x][y]<4) {
            int ndir=(dir+1)%4;
            update(x, y, ndir);
            ndir=(dir+3)%4;
            if(nx==n+1 && ny==m && ndir==0) return true;
        } else {
            int ndir=dir;
            int nx=x+dx[ndir], ny=y+dy[ndir];
            if(check(nx, ny, ndir)) {
                q.push(Sta{nx, ny, ndir});
                vis[nx][ny][ndir]=1;
                pre[nx][ny][ndir]=Sta{x, y, dir};
            }
            if(nx==n+1 && ny==m && ndir==0) return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j) {
                scanf("%d", &mp[i][j]);
                memset(vis[i][j], 0, sizeof(vis[i][j]));
            }
        if(bfs()) {
            printf("YES\n");
            print(Sta{n+1, m, 0}, 0);
        } else {
            printf("NO\n");
        }
    }
    return 0;
}