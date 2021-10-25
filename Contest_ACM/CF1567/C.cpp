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
char s[100];
LL f[100][2];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        n=strlen(s);
        f[n][0]=f[n+1][0]=1;
        f[n][1]=f[n+1][1]=0;
        for(int i=n-1; i>=0; --i) {
            f[i][1]=f[i+2][0]*('9'-s[i])+f[i+2][1]*('9'-s[i]+1);
            f[i][0]=f[i+2][0]*(s[i]-'0'+1)+f[i+2][1]*(s[i]-'0');
        }
        printf("%lld\n", f[0][0]*f[1][0]-2);
    }
    return 0;
}