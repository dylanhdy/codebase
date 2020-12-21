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
#define MAXN 200005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, x[MAXN], ans[MAXN];
char op[MAXN][2];

stack<int> sta;
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n*2; ++i)
    {
        scanf("%s", op[i]);
        if(op[i][0]=='+') sta.push(i);
        else
        {
            scanf("%d", &x[i]);
            if(sta.empty())
            {
                printf("NO\n");
                return 0;
            }
            ans[sta.top()]=x[i];
            sta.pop();
        }
    }
    for(int i=1; i<=n*2; ++i)
    {
        if(op[i][0]=='+') q.push(ans[i]);
        else
        {
            if(x[i]!=q.top())
            {
                printf("NO\n");
                return 0;
            }
            q.pop();
        }
    }
    printf("YES\n");
    for(int i=1; i<=n*2; ++i)
        if(ans[i]) printf("%d ", ans[i]);
    return 0;
}