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

int n, minn, sum, pos, f[200005], a[105];

bool check(int x)
{
    f[0]=1;
    for(int i=1; i<=n; ++i)
        for(int j=x; j>=a[i]; --j)
            if(f[j-a[i]]) f[j]=1;
    return f[x];
}

int main()
{
    scanf("%d", &n);
    minn=20;
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        sum+=a[i];
        int tmp=0;
        for(int j=0; j<20; ++j)
            if(a[i]%(1<<j)==0) tmp=j;
        if(tmp<minn) minn=tmp, pos=i;
    }
    if(sum%2==0 && check(sum/2)) printf("1\n%d\n", pos);
    else printf("0\n");
    return 0;
}