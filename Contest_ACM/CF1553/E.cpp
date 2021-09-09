#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#define LL long long
#define LD long double
#define MAXN 300005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, m, a[MAXN], b[MAXN], p[MAXN], num[MAXN];

vector<int> ans;

bool check(int x)
{
    int num=0;
    for(int i=1; i<=n; ++i) {
        a[i]=(i+x>n?i+x-n:i+x);
        b[i]=p[i];
    }
    for(int i=1; i<=n; ++i) {
        while(a[b[i]]!=i) {
            num++;
            swap(b[i], b[a[b[i]]]);
        }
    }
    return num<=m;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        ans.clear();
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; ++i) num[i]=0;
        for(int i=1; i<=n; ++i) {
            scanf("%d", &p[i]);
            num[(i-p[i]+n)%n]++;
        }
        for(int i=0; i<n; ++i)
            if(num[i]>=n-2*m && check(i)) ans.PB(i);
        printf("%d ", ans.size());
        for(int e: ans) printf("%d ", e);
        printf("\n");
    }
    return 0;
}