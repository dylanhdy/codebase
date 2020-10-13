//
//  main.cpp
//  BZOJ1093 最大半联通子图
//
//  Created by 黄道煜 on 2018/10/6.
//  Copyright © 2018年 黄道煜. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <map>
#define MAXN 100005
using namespace std;

int n, m, p, ans1, ans2, cnt, cnt1, head[MAXN], deg[MAXN], f[MAXN], dis[MAXN], x[MAXN*10], y[MAXN*10];
int id, tot, top, dfn[MAXN], low[MAXN], vis[MAXN], sta[MAXN], col[MAXN], siz[MAXN];

struct Edge {int next, to;} edge[MAXN*20];
struct E {int x, y;} e[MAXN*20];
queue<int> q;

bool CMP(E a, E b)
{
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}

void addedge(int from, int to)
{
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    head[from]=cnt;
}

void tarjan(int x)
{
    low[x]=dfn[x]=++id;
    sta[++top]=x; vis[x]=1;
    for(int i=head[x]; i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(!dfn[to]) tarjan(to), low[x]=min(low[x], low[to]);
        else if(vis[to]) low[x]=min(low[x], dfn[to]);
    }
    if(low[x]==dfn[x])
    {
        int y; tot++;
        do{
            y=sta[top--]; vis[y]=0;
            col[y]=tot; siz[tot]++;
        } while(y!=x);
    }
}

void topsort()
{
    for(int i=1; i<=tot; i++)
        if(deg[i]==0) q.push(i), f[i]=1;
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        dis[x]+=siz[x];
        for(int i=head[x]; i; i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis[to]==dis[x]) f[to]=(f[x]+f[to])%p;
            if(dis[to]<dis[x])
            {
                f[to]=f[x];
                dis[to]=dis[x];
            }
            deg[to]--;
            if(deg[to]==0) q.push(to);
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        addedge(x[i], y[i]);
    }
    for(int i=1; i<=n; i++)
        if(!dfn[i]) tarjan(i);
    
    cnt=0;
    memset(head, 0, sizeof(head));
    for(int i=1; i<=m; i++)
        if(col[x[i]]!=col[y[i]])
        {
            e[++cnt1].x=col[x[i]];
            e[cnt1].y=col[y[i]];
        }
    sort(e+1, e+cnt1+1, CMP);
    for(int i=1; i<=cnt1; i++)
        if(e[i].x!=e[i-1].x || e[i].y!=e[i-1].y)
        {
            addedge(e[i].x, e[i].y);
            deg[e[i].y]++;
        }
    topsort();
    for(int i=1; i<=tot; i++)
    {
        if(dis[i]==ans1) ans2=(ans2+f[i])%p;
        if(dis[i]>ans1)
        {
            ans2=f[i];
            ans1=dis[i];
        }
    }
    printf("%d\n%d\n", ans1, ans2);
}
