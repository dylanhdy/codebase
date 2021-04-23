#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P 1000000007
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, ans, num;

vector<int> vec;

int gcd(int x, int y)
{
    if(y) return gcd(y, x%y);
    return x;
}

int main()
{
    scanf("%d", &n);
    num=1;
    for(int i=1; i<=n; ++i)
        if(gcd(i, n)==1) {
            num=1LL*num*i%n;
            vec.PB(i);
        }
    if(num!=1) vec.pop_back(); 
    printf("%d\n", vec.size());
    for(int i=0; i<vec.size(); ++i) printf("%d ", vec[i]);
}