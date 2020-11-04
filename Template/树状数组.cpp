#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, t[MAXN];

void add(int x, int y) {for(; x<=n; x+=(x&-x)) t[x]+=y;}
int sum(int x) {int y=0; for(; x; x-=(x&-x)) y+=t[x]; return y;}

int main()
{
    //add(x, y) 位置 x 加 y
    //sum(x) 区间 1~x 和
    return 0;
}