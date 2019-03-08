 #include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 300005
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
#define pii pair<int, int>
using namespace std;
 
int n, tot=1, last=1, num[MAXN*2];
 
struct Node
{
    int len, fa;
    map<int, int> nxt;
} a[MAXN*4];
 
void insert(int ch)
{
    int nx=++tot, x=last;
    a[nx].len+=a[x].len+1;
    for(; x && !a[x].nxt[ch]; x=a[x].fa) a[x].nxt[ch]=nx;
    if(!x) a[nx].fa=1;
    else
    {
        int y=a[x].nxt[ch];
        if(a[x].len+1==a[y].len) a[nx].fa=y;
        else
        {
            int ny=++tot;
            a[ny].len=a[x].len+1;
            a[ny].nxt=a[y].nxt;
            a[ny].fa=a[y].fa;
            for(; x && a[x].nxt[ch]==y; x=a[x].fa) a[x].nxt[ch]=ny;
            a[nx].fa=a[y].fa=ny;
        }
    }
    last=nx;
}
 
int main()
{
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i)
    {
        scanf("%d", &num[i]);
        insert(num[i]);
    }
    for(rint i=1; i<=n; ++i) insert(num[i]);
    for(rint i=1, p=1; i<=n; ++i)
    {
        pii nxt=*a[p].nxt.begin();
        printf("%d ", nxt.first);
        p=nxt.second;
    }
    return 0;
}
﻿