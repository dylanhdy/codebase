#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int len1, len2, nxt[MAXN], ans[MAXN];
char s1[MAXN], s2[MAXN]; //s1 文本串，s2 模式串

int main()
{
    scanf("%s%s", s1+1, s2+1);
    len1=strlen(s1+1), len2=strlen(s2+1);
    for(int i=2, p=0; i<=len2; i++)
    {
        while(p && s2[i]!=s2[p+1]) p=nxt[p];
        if(s2[i]==s2[p+1]) p++;
        nxt[i]=p;
    }	
    for(int i=1, p=0; i<=len1; i++)
    {
        while(p && s1[i]!=s2[p+1]) p=nxt[p];
        if(s1[i]==s2[p+1]) p++;
        // p==len2 时，存在一个匹配
    }	
}