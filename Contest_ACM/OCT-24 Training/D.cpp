#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int T, n, p, ans, cnt, t[MAXN*2], temp[MAXN*2];

struct A {int x, y, nx, ny;} a[MAXN];

void add(int x,int y) {for(;x<=cnt;x+=x&-x) t[x]+=y;}
int sum(int x) {int y=0; for(;x;x-=x&-x) y+=t[x]; return y;}

bool CMP1(A x, A y) {return x.x<y.x;}
bool CMP2(A x, A y) {return x.y<y.y;}

int main()
{
    scanf("%d", &T);
    for(int qwq=1; qwq<=T; ++qwq)
    {
        ans=0;
        scanf("%d%d", &n, &p);
        for(int i=1; i<=n; ++i)
        {
            scanf("%d%d", &a[i].y, &a[i].x);
            temp[i*2-1]=a[i].x, temp[i*2]=a[i].y;
        }
        sort(a+1, a+n+1, CMP1);
        sort(temp+1, temp+n*2+1);
        cnt=unique(temp+1, temp+n*2+1)-temp-1;
        for(int i=1; i<=cnt; ++i) t[i]=0;
        for(int i=1; i<=n; ++i)
        {
            a[i].nx=lower_bound(temp+1, temp+cnt+1, a[i].x)-temp;
            a[i].ny=lower_bound(temp+1, temp+cnt+1, a[i].y)-temp;
            add(a[i].nx, 1);
        }
        int maxn=a[n].x;
        int pos1=lower_bound(temp+1, temp+cnt+1, maxn)-temp;
        int pos2=lower_bound(temp+1, temp+cnt+1, 1.0*maxn*p/100)-temp;
        ans=max(ans, sum(pos1)-sum(pos2-1));
        sort(a+1, a+n+1, CMP2);
        for(int i=1; i<=n; ++i)
        {
            add(a[i].nx, -1);
            add(a[i].ny, 1);
            maxn=max(maxn, a[i].y);
            pos1=lower_bound(temp+1, temp+cnt+1, maxn)-temp;
            pos2=lower_bound(temp+1, temp+cnt+1, 1.0*maxn*p/100)-temp;
            ans=max(ans, sum(pos1)-sum(pos2-1));
        }
        printf("Case #%d: %d\n", qwq, ans);
    }
    return 0;
}