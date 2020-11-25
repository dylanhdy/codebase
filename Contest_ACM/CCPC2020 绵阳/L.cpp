#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 100005
#define P 1000000007
#define LL long long
using namespace std;

int T, n, ans;

struct A {int a, x;} a[MAXN];

vector<int> vec;

bool CMP(A x, A y)
{
	return x.a<y.a;
}

int main()
{
	scanf("%d", &T);
	for(int qwq=1; qwq<=T; ++qwq)
	{
		ans=1;
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d%d", &a[i].a, &a[i].x);
		sort(a+1, a+n+1, CMP);
		for(int l=1, r=1; l<=n; l=r+1, r=l)
		{
			LL temp=a[l].x, val=0;
			while(temp>1)
			{
				vec.push_back(temp%2);
				temp/=2;
				if(r<n && a[r+1].a-a[l].a<=vec.size())
				{
					r++;
					temp+=a[r].x;
				}
			}
            vec.push_back(temp);
			for(int i=vec.size()-1; i>=0; --i)
				val=(1LL*val*2+vec[i])%P;
			vec.clear();
			ans=1LL*ans*(val+1)%P;
		}
		printf("Case #%d: %d\n", qwq, ans);
	}
}