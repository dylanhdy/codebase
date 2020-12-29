#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 1004
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int t, n, num, len;
char s[MAXN];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%s", &n, s+1);
        len=0;
        for(int i=n; i>=1 && s[i]==')'; --i) len++;
        if((n-len)<len) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}