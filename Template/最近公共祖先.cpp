#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 500005
using namespace std;
int n,m,s,x,y,a,b,k,cnt,temp,num,fa[MAXN],deep[MAXN],l[MAXN],head[MAXN],lca[20][MAXN];
bool vis[MAXN];
struct Edge{
    int next,to;
}edge[MAXN*2];

void addedge(int from,int to)
{
    edge[++num].next=head[from];
    edge[num].to=to;
    head[from]=num;
}

void dfs(int node){ 
    deep[node]=deep[fa[node]]+1;
    for(int i=head[node]; i; i=edge[i].next)
    	if (edge[i].to!=fa[node])
		{
			fa[edge[i].to]=node;
        	dfs(edge[i].to);
        }
    return;
}

int query(int x, int y)
{
    if (deep[x] > deep[y]) swap(x,y);
	for (int i=20; i>=0; i--)
	 	if (deep[lca[i][y]]>=deep[x])
	   		y=lca[i][y];
	if (x==y) return x;
	for (int i=20; i>=0; i--)
		if (lca[i][x]!=lca[i][y])
	   		x=lca[i][x],y=lca[i][y];
	return fa[x];
} 

int main(){
    scanf("%d%d%d",&n,&m,&s);
    for (int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    dfs(s);
    for(int i=1; i<=n; i++) lca[0][i]=fa[i];
    for(int i=1; i<=20; i++)
        for(int j=1; j<=n; j++)
        	lca[i][j]=lca[i-1][lca[i-1][j]];        
    for (int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",query(a, b));
    }
    return 0;
}