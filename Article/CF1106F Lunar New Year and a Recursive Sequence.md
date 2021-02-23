### 问题描述

有关系式 $f_i = \left(\prod_{j = 1}^{k} f_{i - j}^{b_j}\right) \bmod p​$，​$p​$ 为 ​$99844353​$，并且设 ​$f_1 = f_2 = \ldots = f_{k - 1} = 1​$。题目告诉 ​$b_1, b_2, \ldots, b_k​$ 及 ​$f_n​$，你需要求出 ​$f_k​$。

### 输入

第一行一个正整数 $k​$

第二行 $k​$ 个整数表示 $b_1, b_2, \ldots, b_k​$

第三行两个整数 $n, m$ 表示 $f_n=m​$

### 输出

输出一个满足 $1 \leq f_k < p$ 的 $f_k$，如果有多个输出任意一个，如果不存在输出 $-1$

### 思路

思路不难，比较的套路，综合了很多知识点。

首先想到将系数递推关系写成矩阵的形式，然后利用矩阵快速幂将 $f_n​$ 写成 $f_n= \left(\prod_{i = 1}^{k} f_{k-i+1}^{a_i}\right) \bmod p​$ 的形式，因为题目设 $f_1 = f_2 = \ldots = f_{k - 1} = 1​$，所以我们实际上要解一个形如 $x^a \equiv b \mod p​$  的方程。

解这个方程比较的套路。先将上面的方程写成离散对数的形式 $k^{a\log_kx} \equiv k^{\log_kb} \mod p​$，再根据欧拉定理得到 $a\log_kx \equiv \log_kb \mod \varphi (p)​$。其中 $k​$ 应该要为 $p​$ 的原根，因为这样 $k^1,k^2,...,k^{\varphi(p)}​$ 是模 $\varphi(p)​$ 的一个完全剩余系，这样就可以避免出现多个 $\log_kx​$ 在模 $p​$ 意义下的值相同。后面就很简单了，先用 BSGS 求出 $\log_kb​$ 然后用 EXGCD 得到 $\log_kx​$，最后用快速幂得出最终答案 $x​$ 就好了。

### 代码

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 105
#define INF 0x3f3f3f3f
#define p 998244353
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, m, x, y, a[MAXN][MAXN], c[MAXN][MAXN], ans[MAXN][MAXN];

map<int, int> mp;

void mul(int a[MAXN][MAXN], int b[MAXN][MAXN])
{
    for(rint i=1; i<=n; ++i)
        for(rint j=1; j<=n; ++j)
        {
            c[i][j]=0;
            for(rint k=1; k<=n; ++k) c[i][j]=(c[i][j]+1LL*a[i][k]*b[k][j])%(p-1);
        }
    memcpy(a, c, sizeof(c));
}

void ksm1(int a[MAXN][MAXN], int y)
{
    for(rint i=1; i<=n; ++i) ans[i][i]=1;
    while(y)
    {
        if(y&1) mul(ans, a);
        mul(a, a); y>>=1;
    }
}

int ksm(int x, int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=1LL*ans*x%p;
        y>>=1; x=1LL*x*x%p;
    }
    return ans;
}

int bsgs(int a, int b)
{
    int siz=sqrt(p)+0.5, base=1;
    int t=b;
    mp[t]=0;
    for(rint i=1; i<=siz; ++i)
    {
        t=1LL*t*a%p;
        mp[t]=i;
        base=1LL*base*a%p;
    }
    t=1;
    for(rint i=1; i<=siz; ++i)
    {
        t=1LL*t*base%p;
        if(mp.count(t))
        {
            int x=i*siz-mp[t];
            return x;
        }
    }
    return -1;
}

int exgcd(int a, int b, LL& x, LL& y)
{
    if(!b)
    {
        x=1, y=0;
        return a;
    }
    int d=exgcd(b, a%b, x, y);
    int temp=x; x=y, y=temp-a/b*y;
    return d;
}

int solve(int a, int b, int c)
{
    LL x, y;
    int d=exgcd(a, b, x, y);
    //printf("%d %d %d %d!!!\n", a, b, c, d);
    if(c%d) return -1;
    x*=c/d;
    return (x%(b/d)+(b/d))%(b/d);
}

int main()
{
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i) scanf("%d", &a[1][i]);
    for(rint i=2; i<=n; ++i) a[i][i-1]=1;
    scanf("%d%d", &m, &y);
    ksm1(a, m-n);
    x=solve(ans[1][1], p-1, bsgs(3, y));
    if(x==-1) printf("-1\n");
    else printf("%d\n", ksm(3, x));
    return 0;
}
```

