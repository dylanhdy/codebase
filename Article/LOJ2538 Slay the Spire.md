### 问题描述

九条可怜在玩一个很好玩的策略游戏：Slay the Spire，一开始九条可怜的卡组里有 $2n$ 张牌，每张牌上都写着一个数字 $w_i$,一共有两种类型的牌，每种类型各 $n$ 张：

攻击牌：打出后对对方造成等于牌上的数字的伤害。

强化牌：打出后，假设该强化牌上的数字为 $x$，则其他剩下的攻击牌的数字都会乘上 $x$。保证强化牌上的数字都大于 $1$。

现在九条可怜会等概率随机从卡组中抽出 $m$ 张牌，由于费用限制，九条可怜最多打出 $k$ 张牌，假设九条可怜永远都会采取能造成最多伤害的策略，求她期望造成多少伤害。

假设答案为 $ans$，你只需要输出 $ans * \frac{(2n)!}{m!(2n-m)!} \mod 998244353 $

### 输入
第一行一个正整数 $T$ 表示数据组数
接下来对于每组数据：
第一行三个正整数 $n,m,k$
第二行 $n$ 个正整数 $w_i$，表示每张强化牌上的数值
第三行 $n$ 个正整数 $w_i$，表示每张攻击牌上的数值

### 输出
输出 $T$ 行，每行一个非负整数表示每组数据的答案。

### 思路
首先题目要求的其实是所有 ${2n \choose m}$ 种情况造成的伤害之和，是一个计数问题。

有一个很巧妙的条件是「强化牌上的数字是大于 1 的整数 」我们可以据此得出最优策略是：如果强化牌数量大于 $i$，那么就先用最大的 $k-1$ 张强化牌，再用最大的 $1$ 张攻击牌；否则就是先用掉所有强化牌，再用最大的 $k-i$ 张攻击牌。

先将两种牌从大到小排序，设计状态 $f_{i,j}$ 为用了$i$ 张牌最小的牌为 $w_j$ 所有这种情况的强化倍数之和；$g_{i,j}$ 为用了$i$ 张牌最小的牌为 $w[j]$ 所有这种情况的总伤害之和。它们的转移方程分别为

$$f_{i,j}=w_j * \sum_{k=1}^{j-1} f_{i-1,k}$$

$$g_{i,j}=w_j*{i-1 \choose j-1}+ \sum_{k=1}^{j-1} g_{i-1,k}$$

但是这样还不够，我们还要考虑每一个状态所对应的情况数。设 $F_{i,j}$ 为抽到了 $i$ 张强化牌，并使用了其中 $j$ 张的情况的总强化倍数乘对应情况数；$G_{i,j}$ 为抽到了 $i$ 张攻击牌，并使用了其中 $j$ 张的情况的总伤害乘对应情况数。$F_{i,j},G_{i,j}$ 满足式子

$$F_{i,j}=\sum_{k=1}^{n} f_{j,k}*{n-k \choose i-j}$$

$$G_{i,j}=\sum_{k=1}^{n} g_{j,k}*{n-k \choose i-j}$$

这时候我们最初提到的最优策略就要用到了，我们先枚举 $m$ 张牌的类型，然后根据最优策略算出对应的贡献。因此答案就是 $$ans=\sum_{i=0}^{m-1} F_{i,min(i,k-1)}* G_{m-i,max(k-i)} $$

最后是实现的细节，我们先预处理 $f_{i,j}$ 和 $g_{i,j}$，利用前缀和可以做到 $O(n^2)$。然后我们可以在计算答案时对于每一个 $F_{i,j},G_{i,j}$ 用 $O(n)$ 计算出来，这样总复杂度就是 $O(n^2)$ 的。


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
#define MAXN 3005
#define INF 0x3f3f3f3f
#define p 998244353
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int T, n, m, k, ans, w[MAXN], v[MAXN], f[MAXN][MAXN], g[MAXN][MAXN];
int inv[MAXN], fac[MAXN];

bool CMP(int x, int y)
{
	return x>y;
}

void init()
{
	inv[0]=inv[1]=fac[0]=fac[1]=1;
	for(rint i=2; i<=3000; ++i) inv[i]=1LL*inv[p%i]*(p-p/i)%p;
	for(rint i=2; i<=3000; ++i)
	{
		inv[i]=1LL*inv[i-1]*inv[i]%p;
		fac[i]=1LL*fac[i-1]*i%p;
	}
}

int comb(LL x, LL y)
{
	if(y>x) return 0;
	return 1LL*fac[x]*inv[y]%p*inv[x-y]%p;
}

int calf(int x, int y)
{
	int sum=0;
	if(y==0) return comb(n, x);
	for(rint i=1; i<=n; ++i)
		sum=(sum+1LL*f[y][i]*comb(n-i, x-y))%p;
	return sum;
}

int calg(int x, int y)
{
	int sum=0;
	for(rint i=1; i<=n; ++i)
		sum=(sum+1LL*g[y][i]*comb(n-i, x-y))%p;
	return sum;
}

int main()
{
	init();
	scanf("%d", &T);
	while(T--)
	{
		ans=0;
		scanf("%d%d%d", &n, &m, &k);
		for(rint i=1; i<=n; ++i) scanf("%d", &w[i]);
		for(rint i=1; i<=n; ++i) scanf("%d", &v[i]);

		sort(w+1, w+n+1, CMP);
		sort(v+1, v+n+1, CMP);
		for(rint i=1; i<=n; ++i)
			g[1][i]=v[i], f[1][i]=w[i];
		for(rint i=2; i<=n; ++i)
		{
			int sum1=0, sum2=0;
			for(rint j=1; j<=n; ++j)
			{
				f[i][j]=1LL*w[j]*sum1%p;
				g[i][j]=(1LL*comb(j-1, i-1)*v[j]+sum2)%p;
				//printf("%d %d %d %d %d!!!\n", i, j, sum2, w[j]);
				sum1=(sum1+f[i-1][j])%p;
				sum2=(sum2+g[i-1][j])%p;
			}
		}
		//for(rint i=1; i<=n; ++i)
		//	for(rint j=1; j<=n; ++j) printf("%d %d %d %d!!!\n", i, j, f[i][j], g[i][j]);
		for(rint i=0; i<m; ++i)
		{
			int a=calf(i, min(i, k-1));
			int b=calg(m-i, max(1, k-i));
			ans=(ans+1LL*a*b)%p;
			//printf("%d %d %d!!\n", ans, a, b);
		}
		printf("%d\n", ans);
	}
	return 0;
}
```