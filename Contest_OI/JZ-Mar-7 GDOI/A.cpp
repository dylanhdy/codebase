#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 150005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int read()
{
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x;
}

int n, K, m, tot, root, x[MAXN], y[MAXN], f[MAXN], ls[MAXN], rs[MAXN];

struct Line
{
    int k, b;
    Line(int x = 0, int y = 0) { k = x, b = y; }
    int cal(int x) { return k * x + b; }
} t[MAXN];

int cross(Line x, Line y)
{
    return (y.b - x.b) / (x.k - y.k);
}

void update(int &root, int l, int r, Line x)
{
    if (!root)
    {
        t[root = ++tot] = x;
        return;
    }
    if (t[root].k == x.k)
    {
        if (t[root].b > x.b)
            t[root] = x;
        return;
    }
    int mid = (l + r) >> 1, p = cross(x, t[root]);
    if (l == r || p < l || p >= r)
    {
        if (x.cal(l) < t[root].cal(l))
            t[root] = x;
        return;
    }
    if (p < mid)
    {
        if (x.k < t[root].k)
            update(ls[root], l, mid, t[root]), t[root] = x;
        else
            update(ls[root], l, mid, x);
    }
    else
    {
        if (x.k < t[root].k)
            update(rs[root], mid + 1, r, x);
        else
            update(rs[root], mid + 1, r, t[root]), t[root] = x;
    }
}

int query(int root, int l, int r, int x)
{
    if (!root)
        return INF;
    if (l == r)
        return t[root].cal(x);
    int mid = (l + r) >> 1, temp = t[root].cal(x);
    if (x <= mid)
        temp = min(temp, query(ls[root], l, mid, x));
    else
        temp = min(temp, query(rs[root], mid + 1, r, x));
    return temp;
}

void solve2()
{
    for (rint i = 1; i <= n; ++i)
        x[i] = read(), m = max(m, x[i]);
    update(root, 1, m, Line(0, 0));
    for (rint i = 1; i <= n; ++i)
    {
        f[i] = query(root, 1, m, x[i]) + x[i] * x[i];
        update(root, 1, m, Line(-2 * x[i], x[i] * x[i] + f[i]));
        printf("%.4lf\n", sqrt(f[i]));
    }
}

void solve1()
{
    for (rint i = 1; i <= n; ++i)
        x[i] = read(), y[i] = read();
    for (rint i = 1; i <= n; ++i)
    {
        int temp = 2e9;
        for (rint j = 0; j < i; ++j)
            temp = min(temp, f[j] + (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        f[i] = temp;
        printf("%.4lf\n", sqrt(temp));
    }
}

int main()
{
    scanf("%d%d", &n, &K);
    if (K == 2)
        solve1();
    else
        solve2();
    return 0;
}