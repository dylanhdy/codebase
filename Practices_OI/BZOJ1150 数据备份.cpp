#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define LL long long
#define INF 0x7fffffff
#define MAXN 100005
using namespace std;

struct Sec
{
    LL dis, pos;
    bool operator < (const Sec &x) const
    {
        return dis>x.dis;
    }
} sec[MAXN];

LL n, k, ans, x[MAXN], dis[MAXN], pre[MAXN], nxt[MAXN];

priority_queue<Sec> q;

int main()
{
    scanf("%lld%lld", &n, &k);
    for(int i=1; i<=n; i++) scanf("%lld", &x[i]);
    for(int i=2; i<=n; i++)
    {
        dis[i]=x[i]-x[i-1];
        q.push((Sec) {dis[i], i});
        pre[i]=i-1; nxt[i]=i+1;
    }
    pre[2]=0; nxt[n]=0;
    for(int i=1; i<=k; i++)
    {
        while(dis[q.top().pos]==INF) q.pop();
        LL pos=q.top().pos; q.pop();
        ans+=dis[pos];
        if(!nxt[pos])
        {
            dis[pre[pos]]=INF;
            nxt[pre[pos]]=0;
            continue;
        }
        if(!pre[pos])
        {
            dis[nxt[pos]]=INF;
            pre[nxt[pos]]=0;
            continue;
        }
        dis[pos]=dis[pre[pos]]+dis[nxt[pos]]-dis[pos];
        dis[pre[pos]]=dis[nxt[pos]]=INF;
        pre[pos]=pre[pre[pos]];
        nxt[pos]=nxt[nxt[pos]];
        pre[nxt[pos]]=nxt[pre[pos]]=pos;
        q.push((Sec){dis[pos], pos});
    }
    printf("%lld\n", ans);
}
