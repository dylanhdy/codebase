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

int t, n, a[MAXN], pre[MAXN];
char s[MAXN];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s+1);
        n=strlen(s+1);
        int len=0, tot=0, resa=0, resb=0;
        if(s[1]=='B') a[++tot]=0;
        for(int i=1; i<=n; ++i)
        {
            len++;
            if(s[i]!=s[i+1]) a[++tot]=len, len=0;
        }
        for(int i=2; i<=tot; i+=2)
        {
            resa+=a[i-1];
            if(a[i]>=resa) a[i]-=resa, resa=0, resb=(resb+a[i])%2;
            else resa-=a[i];
        }
        if(tot%2) resa+=a[tot];
        printf("%d\n", resa+resb);
    }
    return 0;
}