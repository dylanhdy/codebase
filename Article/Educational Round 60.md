### F - Crisp String
**思路：**

首先我们考虑删去那些字符集是合法的。有一种很直观的做法就是枚举字符集，然后再用 $O(n)$ 判断是否合法，但这复杂度显然是不符合要求的。考虑统计非法的情况，可以对于每一个字母枚举与它产生矛盾的字符对，那么让这两个字母相邻的所有字符集都是非法的。这个的话，可以 $O(nq^2)$ 预处理，$(2^qq^2)$ 统计得到。

知道了那些字符集合法后，我们就需要计算出经过题目所给操作，能得到的答案最小的字符集。这个对合法字符集进行简单的 DP 即可得到。

**[代码链接](https://github.com/CrazyDaveHDY/OI-Code/blob/master/Contest/Educational%20Codeforces%20Round%2060/F.cpp "代码链接")**

### G -  Recursive Queries
**思路：**

每一个询问其实要求的就是 $\sum_{i=l}^r(max(l_i, l)+min(r_i, r))$，$l,r$ 就是该询问的左右端点，$l_i,r_i$ 表示一个过点 $i$ 的一个极长区间，该区间的所有元素都小于等于 $p_i$。

发现这个东西不好维护，但我们可以换一个角度，考虑每个点对询问的贡献。那么对于询问 $l,r$，答案应该就是 $l \sim r$ 中每一个点对 $r$ 的贡献减去对 $l$ 的贡献之和。我们考虑点 $i$ 对于位置 $pos$ 的贡献，如果$pos < l_i$ 贡献为 $l_i$；如果$l_i < pos < r_i$ 贡献为 $pos$；如果$r_i < pos$ 贡献为 $r_i$。于是我们用线段树维护这个的和就可以在 $O(n \log n)$ 内得出答案。

**[代码链接](https://github.com/CrazyDaveHDY/OI-Code/blob/master/Contest/Educational%20Codeforces%20Round%2060/G.cpp "代码链接")**