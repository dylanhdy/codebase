#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 1000005
#define Pi acos(-1)
#define INF 0x3f3f3f3f
#define mp make_pair
using namespace std;

struct  Edge {int next, to;} edge[MAXN*6];

int t, r, c, S, T, cnt, head[MAXN], dis[MAXN], vis[MAXN];
char s[6005];

void addedge(int from, int to)
{
    printf("from:%d to:%d\n", from, to);
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    head[from]=cnt;
}

void init()
{
    cnt=0;
    for(int i=1; i<=r*c; ++i)
    {
        vis[i]=head[i]=0;
        dis[i]=INF;
    }
    for(int i=1; i<=4*r+3; ++i)
        for(int j=1; ; ++j)
        {
            scanf("%c", &s[j]);
            if(s[j]=='\n') break;
            if(s[j]=='S') S=(i-3)/4*c+(j+1)/6;
            if(s[j]=='T') T=(i-3)/4*c+(j+1)/6;
            if((i-1)%4==0 && (j-5)%12==0 && s[j]==' ')
            {
                addedge((i-5)/4*c+(j+1)/6, (i-1)/4*c+(j+1)/6);
                addedge((i-1)/4*c+(j+1)/6, (i-5)/4*c+(j+1)/6);
            }
            if((i-3)%4==0 && (j-11)%12==0 && s[j]==' ')
            {
                addedge((i-7)/4*c+(j+1)/6, (i-3)/4*c+(j+1)/6);
                addedge((i-3)/4*c+(j+1)/6, (i-7)/4*c+(j+1)/6);
            }
            if(i%4==0 && (j-8)%12==0 && s[j]==' ')
            {
                addedge((i-4)/4*c+(j-2)/6, (i-4)/4*c+(j+4)/6);
                addedge((i-4)/4*c+(j+4)/6, (i-4)/4*c+(j-2)/6);
            }
            if((i-2)%4==0 && (j-2)%12==0 && s[j]==' ')
            {
                addedge((i-6)/4*c+(j-2)/6, (i-2)/4*c+(j+4)/6);
                addedge((i-2)/4*c+(j+4)/6, (i-6)/4*c+(j-2)/6);
            }
            if((i-2)%4==0 && (j-8)%12==0 && s[j]==' ')
            {
                addedge((i-2)/4*c+(j-2)/6, (i-6)/4*c+(j+4)/6);
                addedge((i-6)/4*c+(j+4)/6, (i-2)/4*c+(j-2)/6);
            }
            if(i%4==0 && (j-2)%12==0 && s[j]==' ')
            {
                addedge((i-4)/4*c+(j-2)/6, (i-4)/4*c+(j+4)/6);
                addedge((i-4)/4*c+(j+4)/6, (i-4)/4*c+(j-2)/6);
            }
        }
}

void bfs()
{
    queue<pair<int, int> > q;
    vis[S]=dis[S]=1; 
    q.push(mp(1, S));
    while(!q.empty())
    {
        int x=q.front().second;
        dis[x]=q.front().first;
        q.pop();
        if(x==T) return;
        for(int i=head[x]; i; i=edge[i].next)
        {
            int to=edge[i].to;
            //printf("now:%d to:%d\n", x, to);
            if(!vis[to])
            {
                q.push(mp(dis[x]+1, to));
                vis[to]=1;
            }
        }
    }
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &r, &c);
        getchar();
        init();
        bfs();
        if(dis[T]==INF) printf("-1\n");
        else printf("%d\n", dis[T]);
    }
    return 0;
}

/*
  +---+       +---+
 /     \     /     \
+       +---+       +---+
 \           \     /     \
  +   +   S   +---+   T   +
 /     \     /           /
+       +---+       +   +
 \           \     /     \
  +---+       +---+       +
 /                       /
+       +---+       +   +
 \                 /     \
  +---+       +---+       +
       \     /     \     /
        +---+       +---+
*/