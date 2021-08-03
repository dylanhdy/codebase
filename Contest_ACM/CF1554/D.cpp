#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
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

int T, n;
char s[100005];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=0; i<=n+1; ++i) s[i]=0;
        s[1]='a', s[n/2+1]='b';
        for(int i=2; i<=n/2; ++i) s[i]=s[i+n/2]='a';
        if(n&1) s[n]='c';
        printf("%s\n", s+1);
    }
    return 0;
}