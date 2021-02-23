### 问题描述

给你 $n$ 个盒子，第 $i$ 个盒子中有 $a_i$ 枝花，同一盒子内花颜色相同，不同盒子内花颜色不同，你需要从中选出 $s$ 枝花，问你有多少中不同的方案。

### 输入

第一行两个数$n$，$s$ ($n \leq 20, s \leq 10^{14}$)
第二行 $n$ 个数，第 $i$ 个数表示 $a_i$ ($a_i \leq 10^{12}$)

### 输出

输出方案数对 $1000000007$ 取模的值

### 思路

这个就是多重集的组合数，当 $\forall a_i​$ 都 $a_i>s​$ 时根据「插板法」可以知道答案是 ${s+n-1} \choose {n-1}​$。但当 $s​$ 较大时，会有 $s>a_i​$ 的情况出现，这时可以比较自然地想到利用容斥原理计算合法的方案数。我们可以枚举出现这种情况的集合 $S​$，然后套上容斥，最终的答案就是：

$$\sum_S (-1)^{|S|} { s+n-1-\sum_{i \in S} (a_i+1) \choose n-1}$$

需要注意的是计算组合数时，要用 Lucas 定理对组合数取模，防止爆 longlong。

对于这种组合问题，也可以从生成函数的角度去看，可以推出和上面一样的式子。我们将它的生成函数写出来：
$$g(x)=\prod_{i=1}^n(1+x+x^2+...+x^{a_i})​$$

然后利用等比数列求和公式化简为：

$$g(x)=\prod_{i=1}^{n}(1-x^{a_i+1})*(1-x)^{-n}​$$

将原式后半部分泰勒展开：

$$g(x)=\prod_{i=1}^n (1-x^{a_i+1}) * (\prod_{i=0}^{\infin} x^i)^n​$$

这个式子的第 $x^s$ 项的系数就是我们要的答案。对于后半部分，它又是一个生成函数，根据它的组合意义我们同样根据「插板法」可以知道 $x^s$ 的系数是 ${s+n-1} \choose {n-1}$。而前半部分，我们可以将这 $n$ 项暴力拆分，并分别计算它对 $x^s$ 项系数的贡献。将这些加起来，就刚好与用容斥原理推出的式子一样。


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
#define MAXN 25
#define P 1000000007
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, ans, inv[MAXN];
LL s, a[MAXN];

int comb(int x, int y)
{
    if(x<y) return 0;
    int ans=1;
    for(rint i=0; i<y; ++i)
    {
        ans=1LL*ans*(x-i)%P;
        ans=1LL*ans*inv[i+1]%P;
    }
    return ans;
}

int main()
{
    scanf("%d%lld", &n, &s);
    for(rint i=0; i<n; ++i) scanf("%lld", &a[i]);
    inv[0]=inv[1]=1;
    for(rint i=2; i<=n; ++i) inv[i]=1LL*inv[P%i]*(P-P/i)%P;
    for(rint sta=0; sta<(1<<n); ++sta)
    {
        LL num=s, cnt=0;;
        for(rint i=0; i<n; ++i)
            if((sta>>i)&1)
            {
                cnt++;
                num-=(a[i]+1);
            }
        if(cnt&1) ans=(ans-comb((num+n-1)%P, n-1)+P)%P;
        else ans=(ans+comb((num+n-1)%P, n-1))%P;
    }
    printf("%d\n", ans);
    return 0;
}
```