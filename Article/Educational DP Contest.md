1月6日 Educational DP Contest
题目链接：[https://atcoder.jp/contests/dp](https://atcoder.jp/contests/dp)

大部分水题就不讲了，记录几道有趣的题目。

### J - Sushi
**思路：**
期望要倒着推！！！

先设计状态设 $f_{i,j,k}​$ 为有 $i​$ 个 $3​$ 个的寿司碟子，有 $j​$ 个 $2​$ 个的寿司碟子，有 $k​$ 个 $1​$ 个的寿司碟子，那么就有 $n-i-j-k​$ 个空着的碟子。然后倒着推期望！！！！

$$ f_{i,j,k}=\frac{i}{n}f_{i-1,j+1,k}+\frac{j}{n}f_{i,j-1,k+1}+\frac{v}{n}f_{i,j,k-1}+\frac{n-i-j-k}{n}f_{i,j,k}+1 $$

$$f_{i,j,k}=\frac{i * f_{i-1,j+1,k}+j * f_{i,j-1,k+1}+v*f_{i,j,k-1}+n}{i+j+k} $$

这样我们就得到了递推的关系。因为转移的顺序问题，我们不能简单地按照 $i, j, k$ 的顺序 DP。但发现转移是从寿司总数少的状态到寿司总数多到状态，因此我们要按照寿司的总数进行 DP。总复杂度 $O(n^3)$。

**代码：**

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 305
#define INF 0x3f3f3f3f
#define p 1000000007
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n, sum, a[MAXN], num[4];
LD f[MAXN][MAXN][MAXN];
 
int main()
{
	scanf("%d", &n);
	for(rint i=1; i<=n; ++i)
	{
		scanf("%d", &a[i]);
		num[a[i]]++; sum+=a[i];
	}
	for(rint x=1; x<=sum; ++x)
	{
		for(rint i=0; i<=x/3; ++i)
		{
			for(rint j=0; j<=(x-i*3)/2; ++j)
			{
				int k=x-i*3-j*2;
				if(i+j+k>n) continue;
				//printf("%d %d %d!!!\n", i, j, k);
				f[i][j][k]=n;
				if(i>0) f[i][j][k]+=i*f[i-1][j+1][k];
				if(j>0) f[i][j][k]+=j*f[i][j-1][k+1];
				if(k>0) f[i][j][k]+=k*f[i][j][k-1];
				f[i][j][k]/=(i+j+k);
				//printf("%d %d %d %Lf!!!\n", i, j, k, f[i][j][k]);
			}
		}
	}
	printf("%.10Lf\n", f[num[3]][num[2]][num[1]]);
	return 0;
}
```