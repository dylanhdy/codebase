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
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, x, vis[100005];

int main()
{
    vis[0]=1;
    for(int i=1; i<=10000; ++i) {
        if(i>=11 && vis[i-11]) vis[i]=1;
        if(i>=111 && vis[i-111]) vis[i]=1;
        if(i>=1111 && vis[i-1111]) vis[i]=1;
    }
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &x);
        if(x>=10000 || vis[x]) printf("YES\n");
        else printf("NO\n");
    }
}