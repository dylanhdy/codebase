4 月 20 日 Tenka1 Programmer Contest 2019
比赛链接：[https://atcoder.jp/contests/tenka1-2019](https://atcoder.jp/contests/tenka1-2019)

### D - Three

**思路：**

直接计算答案比较困难，考虑计算不能构成三角形的情况数。枚举一种颜色，设 $f_{i,j}$ 为前 $i$ 个数中当前颜色之和为 $j$ 的情况数，这个可以简单 DP 得出。设所有数之和为 $sum$，那么 $f_{i, \lfloor sum/2 \rfloor} \sim f_{i,sum}$ 这些就是不能构成三角形的情况。需要注意的是当 $sum$ 是偶数时且有两种颜色的和都为 $\frac{sum}{2}$ 时这种情况被多减了，将这些情况再加回来即可。

**[代码链接](https://github.com/CrazyDaveHDY/OI-Code/blob/master/Contest/Tenka1%20Programmer%20Contest%202019/D.cpp "代码链接")**

### E - Polynomial Divisors
**思路：**

当 $f(i) \equiv 0 \pmod p$ 时，意味着 $f(i)$ 在模 $p$ 意义下存在因式 $x-i$。那么 $f(i)$ 在模 $p$ 意义下恒为零，意味着 $f(i)$ 在模 $p$ 意义下存在因式 $\prod_{i=0}^{p-1} (x-i) \equiv x^p-x \pmod p$，或者 $f(i)$ 在模 $p$ 意义下就为零。对于第一种情况发现 $p$ 不会超过 $n$，于是我们可以枚举 $p$ 再用 $O(n)$ 时间去判断，对于第二种情况 $p$ 就是所有 $a_i$ 的公因数。用一个 $set$ 存两种情况答案即可。

**[代码链接](https://github.com/CrazyDaveHDY/OI-Code/blob/master/Contest/Tenka1%20Programmer%20Contest%202019/E.cpp "代码链接")**

### F - Banned X
**思路：**

枚举 $0$ 的个数，我们设 $f_i$ 为只由 $1,2$ 构成长度为 $i$ 的合法序列方案数，那么答案就是 $\sum_{i=0}^{n} {n\choose i} f_i$。考虑如何计算 $f$ 数组，我们枚举这 $i$ 个数的和 $sum$，可以发现合法情况就以下两种：

1. $sum<x$，此时所有 ${sum-i \choose i}$ 种情况都合法
2. $sum-x$ 为奇数，且对于所有 $1$ 两侧数的和小于 $x-1$ 。对于这种情况，我们发现这个序列离两端的距离小于 $\frac{sum-x-1}{2}$ 的数只能填 $2$，而中间其余的数没有其他的限制，这个也同样可以用组合数算出。当然，如果不存在 $1$ 的情况也是合法的。

**[代码链接](https://github.com/CrazyDaveHDY/OI-Code/blob/master/Contest/Tenka1%20Programmer%20Contest%202019/F.cpp "代码链接")**