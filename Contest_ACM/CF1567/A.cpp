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

int T, n;
char s[1005];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%s", &n, s);
        for(int i=0; i<n; ++i) {
            if(s[i]=='U') printf("D");
            else if(s[i]=='D') printf("U");
            else printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}