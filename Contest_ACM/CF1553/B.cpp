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

int T, n, m;
char s[1005], t[1005];

int main()
{
    scanf("%d", &T);
    while(T--) {
        int flag=0;
        scanf("%s%s", s+1, t+1);
        string st=(t+1);
        n=strlen(s+1), m=strlen(t+1);
        for(int l=1; l<=n; ++l) {
            for(int r=l; r<=n; ++r) {
                string str="";
                for(int i=l; i<=r; ++i) str+=s[i];
                for(int i=r-1; i>=1 && str.length()<m; --i) str+=s[i];
                if(str==st) flag=1;
                //printf("%d %d %s %s\n", l, r, str.c_str(), st.c_str());
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}