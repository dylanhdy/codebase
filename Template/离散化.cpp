#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, a[MAXN];
vector<int> sub;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        sub.push_back(a[i]);
    }
    sort(sub.begin(), sub.end());
    sub.erase(unique(sub.begin(), sub.end()), sub.end());
    for(int i=1; i<=n; ++i)
        a[i]=lower_bound(sub.begin(), sub.end(), a[i])-sub.begin()+1;
}