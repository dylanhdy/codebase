#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 500005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int T, n, cnt, head[MAXN], deg[MAXN];
char s[MAXN];

struct Edge {int next, to;} edge[MAXN*2];

void addedge(int from, int to)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    deg[to]++;
    head[from]=cnt;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        int tag=0, tot=0;
        cnt=0;
        scanf("%d", &n);
        for(rint i=1; i<=n; ++i) head[i]=deg[i]=0;
        for(rint i=1, x, y; i<n; ++i)
        {
            scanf("%d%d", &x, &y);
            addedge(x, y);
            addedge(y, x);
        }
        scanf("%s", s+1);
        if(n<=2)
        {
            printf("Draw\n");
            continue;
        }
        if(n==3)
        {
            int num=0;
            for(rint i=1; i<=n; ++i) num+=s[i]=='W';
            printf("%s\n", num>=2?"White":"Draw");
            continue;
        }
        for(rint i=1; i<=n; ++i)
            if(s[i]=='W')
            {
                head[++n]=0;
                addedge(n, i);
                addedge(i, n);
                deg[n]=3;
            }
        for(rint i=1; i<=n; ++i)
        {
            if(deg[i]>=4)  {tag=1; break;}
            else if(deg[i]==3)
            {
                int num=0;
                for(rint j=head[i]; j; j=edge[j].next)
                    num+=deg[edge[j].to]>=2;
                if(num>=2) {tag=1; break;}
                tot++;
            }
        }
        if(n%2 && tot==2) tag=1;
        printf("%s\n", tag?"White":"Draw");
    }
    return 0;
}