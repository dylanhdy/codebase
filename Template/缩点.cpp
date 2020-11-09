#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#define LL long long
#define LD long double
#define MAXN 10005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, m, cnt, ans, tot, dfn[MAXN], low[MAXN], ins[MAXN], id[MAXN];

queue<int> q;
stack<int> sta;
vector<int> g1[MAXN], g2[MAXN];

void tarjan(int x)
{
    dfn[x]=low[x]=++cnt;
    sta.push(x);
    ins[x]=1;
    for(int i=0; i<g1[x].size(); ++i)
    {
        int to=g1[x][i];
        if(!dfn[to])
        {
            tarjan(to);
            low[x]=min(low[x], low[to]);
        }
        else if(ins[to])
            low[x]=min(low[x], dfn[to]);
    }
    if(low[x]==dfn[x])
    {
        tot++;
        while(!sta.empty() && dfn[sta.top()]>=dfn[x])
        {
            int top=sta.top(); sta.pop();
            ins[top]=0;
            id[top]=tot;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g1[x].push_back(y);
    }
    for(int i=1; i<=n; ++i)
        if(!dfn[i]) tarjan(i);
    //id[x] 为 x 所在强连通分量的编号
    return 0;
}