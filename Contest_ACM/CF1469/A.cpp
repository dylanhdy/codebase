#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int t, n;
char s[105];

bool check()
{
    if(n&1) return 0;
    if(s[1]==')' || s[n]=='(') return false;
    return true;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s+1);
        n=strlen(s+1);
        if(check()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}