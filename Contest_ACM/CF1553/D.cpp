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
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int q, n, m, f[MAXN][4];
char s[100005], t[100005];

int main()
{
    scanf("%d", &q);
    while(q--) {
        int flag=0, pos1=0, pos2=0;
        scanf("%s%s", s+1, t+1);
        n=strlen(s+1), m=strlen(t+1);
        for(int i=1; i<=n; ++i) {
            if(!pos1 && i%2==1 && s[i]==t[1]) pos1=i; 
            if(!pos2 && i%2==0 && s[i]==t[1]) pos2=i;
        }
        if(m==1) {
            if(pos1 && (n-pos1)%2==0) printf("YES\n");
            else if(pos2 && (n-pos2)%2==0) printf("YES\n");
            else printf("NO\n");
            continue;
        }
        if(pos1) {
            for(int i=pos1+1, j=2; i<=n && j<=m; i+=2) {
                if(s[i]==t[j]) i--, j++;
                if(j==m+1 && (n-i)%2==1) flag=1;
            }
        }
        if(pos2) {
            for(int i=pos2+1, j=2; i<=n && j<=m; i+=2) {
                if(s[i]==t[j]) i--, j++;
                if(j==m+1 && (n-i)%2==1) flag=1;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n"); 
    }
    return 0;
}