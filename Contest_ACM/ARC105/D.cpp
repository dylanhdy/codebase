#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int t, n, a[MAXN];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        if(n%2) printf("Second\n");
        else
        {
            int tag=0;
            sort(a+1, a+n+1);
            for(int i=1, cnt=0; i<=n; ++i)
            {
                if(a[i]!=a[i-1] && cnt%2) tag=1;
                cnt++;
            }
            if(tag) printf("First\n");
            else printf("Second\n");
        }
    }   
    return 0;
}