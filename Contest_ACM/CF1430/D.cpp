#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, t;
char s[MAXN];

struct A {int len, pos;} a[MAXN];
bool CMP(A x, A y)
{
    if(x.len==y.len) return x.pos<y.pos;
    else return x.len<y.len;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        scanf("%s", s+1);
        int len=1, cnt=0;
        for(int i=2; i<=n+1; ++i)
        {
            if(s[i]!=s[i-1])
            {
                a[++cnt].len=len;
                a[cnt].pos=cnt;
                len=0;
            }
            len++;
        }
        int res=0;
        for(int i=1; i<=cnt; ++i)
        {
            res++;
            res-=min(res, a[i].len-1);
            a[i].len-=res;
        }
        printf("%d\n", cnt-res/2);
    }
    return 0;
}