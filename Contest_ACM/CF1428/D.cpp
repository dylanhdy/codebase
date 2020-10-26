#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, a[MAXN], tot;
pair<int, int> ans[MAXN*2];
queue<int> q2, q3;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    int up=1;
    for(int i=1; i<=n; ++i)
    {
        if(a[i]==0) continue;
        if(a[i]==1)
        {
            if(!q2.empty()) ans[++tot]=make_pair(i, q2.front()), q2.pop();
            else if(!q3.empty())
            {
                ans[++tot]=make_pair(i, q3.front()), q3.pop();
                ans[++tot]=make_pair(i, up), up++;
            }
            else ans[++tot]=make_pair(i, up), up++;
        }
        if(a[i]==2)
        {
            if(!q3.empty())
            {
                ans[++tot]=make_pair(i, q3.front()), q3.pop();
                ans[++tot]=make_pair(i, up); q2.push(up);
                up++;
            }
            else
            {
                ans[++tot]=make_pair(i, up); q2.push(up);
                up++;
            }
        }
        if(a[i]==3)
        {
            if(!q3.empty())
            {
                ans[++tot]=make_pair(i, q3.front()), q3.pop();
                ans[++tot]=make_pair(i, up); q3.push(up);
                up++;
            }
            else
            {
                ans[++tot]=make_pair(i, up); q3.push(up);
                up++;
            }
        }
    }
    if(!q2.empty() || !q3.empty()) printf("-1\n");
    else
    {
        printf("%d\n", tot);
        for(int i=1; i<=tot; ++i) printf("%d %d\n", ans[i].second, ans[i].first);   
    }
    return 0;
}