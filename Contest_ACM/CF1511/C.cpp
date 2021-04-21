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

int n, q, t, pos[100], a[300005];

int main()
{
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        if(!pos[a[i]]) pos[a[i]]=i;
    }
    while(q--) {
        scanf("%d", &t);
        printf("%d ", pos[t]);
        for(int i=1; i<=50; ++i)
            if(pos[i] && pos[i]<pos[t]) pos[i]++;
        pos[t]=1;
    }
    return 0;
}