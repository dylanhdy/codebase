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
#define MAXN 200005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, a[MAXN], b[MAXN], f[MAXN], t[MAXN];
vector<int> vec[MAXN];

void add(int x, int y)
{
    for(; x<=n; x+=(x&-x)) t[x]=max(t[x], y);
}

int ask(int x)
{
    int num=0;
    for(; x; x-=(x&-x)) num=max(num, t[x]);
    return num;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        vec[b[i]].PB(a[i]);
    }
    for(int i=1; i<=n; ++i) sort(vec[i].begin(), vec[i].end(), greater<int>());
    for(int i=1; i<=n; ++i) {
        for(int e: vec[i]) {
            f[e]=ask(e-1)+1;
            add(e, f[e]);
        }
    }
    printf("%d\n", ask(n));
    return 0;
}