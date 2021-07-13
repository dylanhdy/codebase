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

int T, n, m, k;

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &m, &k);
        if(m<=k || (n-m+1)<=k) {
            printf("Alice\n");
            continue;
        }
        int val1=(m%(k+1)>0), val2=((n-m+1)%(k+1)>0);
        if(val1 && val2) {
            if(m%(k+1)==(n-m+1)%(k+1)) printf("Bob\n");
            else printf("Alice\n");
        }
        if(val1^val2) printf("Alice\n");
        if(!val1 && !val2) printf("Bob\n");
    }
    return 0;
}