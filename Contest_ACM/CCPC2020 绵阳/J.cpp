#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int T, n, m, tot, ans[MAXN], val[MAXN];

struct A
{
    int r, val;
    bool friend operator < (A x, A y)
    {
        return x.val<y.val;
    }
};

vector<A> vec[MAXN];
priority_queue<A> q;

int main()
{
    scanf("%d", &T);
    for(int qwq=1; qwq<=T; ++qwq)
    {
        while(!q.empty()) q.pop();
        for(int i=1; i<=m; ++i) val[i]=0;
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; ++i)
        {
            int t, x;
            scanf("%d%d", &t, &x);
            t=min(t, m);
            val[t]=max(val[t], x);
        }
        for(int i=1; i<=m; ++i)
      		if(val[i])
		  		for(int j=1; j<=m; j+=i*2)
				{
					A temp={j+i-1, val[i]};
					vec[j].push_back(temp);
				}	
        for(int i=1; i<=m; ++i)
        {
            for(int j=0; j<vec[i].size(); ++j) q.push(vec[i][j]);
            vec[i].clear();
            while(!q.empty() && q.top().r<i) q.pop();
            if(q.empty()) ans[i]=0;
            else ans[i]=q.top().val;
        }
        printf("Case #%d:", qwq);
        for(int i=1; i<=m; ++i) printf(" %d", ans[i]);
        printf("\n");
    }   
    return 0;
}