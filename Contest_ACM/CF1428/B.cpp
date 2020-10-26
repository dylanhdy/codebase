#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 300005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int t, n, deg[MAXN];
char s[MAXN];
vector<int> vec[MAXN];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        int ans=0, tag1=0, tag2=0;
        scanf("%d%s", &n, s);
        for(int i=0; i<n; ++i)
        {
            if(s[i]=='-') ans++;
            if(s[i]=='-' && s[i+1]!='-') ans++;
            if(s[i]=='>') tag1=1;
            if(s[i]=='<') tag2=1;
        }
        if(s[0]=='-' && s[n-1]=='-') ans--;
        if(!tag1 || !tag2) ans=n;
        printf("%d\n", ans);
    }
    return 0;
}