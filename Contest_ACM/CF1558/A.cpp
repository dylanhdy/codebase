#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, a, b, n;

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &a, &b);
        n=a+b;
        vector<int> vec;
        if(a>b) swap(a, b);
        if(n&1) {
            for(int i=(n+1)/2-a; i<=(n+1)/2+a; i+=2) vec.PB(i);
        }
        for(int i=n/2-a; i<=n/2+a; i+=2) vec.PB(i);
        sort(vec.begin(), vec.end());
        printf("%d\n", vec.size());
        for(int e: vec) printf("%d ", e);
        printf("\n");
    }
    return 0;
}