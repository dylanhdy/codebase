#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 20
#define MAXM 1000005
#define P
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    // 预处理
    for(int sta=1; sta<(1<<n); ++sta)
        for(int sub=sta; sub; sub=(sub-1)&sta)
        {
            // sub 为 sta 的子集
        }
    return 0;
}