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

int T, n, a[10005];

int main()
{
    scanf("%d", &T);
    while(T--) {
        vector<int> vec;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            if(a[i]==1) {
                vec.PB(1);
            } else {
                while(vec.back()!=a[i]-1) vec.pop_back();
                vec.pop_back(); vec.PB(a[i]);
            }
            printf("%d", vec[0]);
            for(int j=1; j<vec.size(); ++j)
                printf(".%d", vec[j]);
            printf("\n");
        }
    }
    return 0;
}