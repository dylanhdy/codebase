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
#define MAXM 100005
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, tot, tag[MAXN], fail[MAXN], t[MAXN][26], num[205];
char s2[205][MAXM], s1[MAXN];  //s1 文本串，s2 模式串

queue<int> q;

void insert(char s[], int id)
{
    int len=strlen(s), p=0;
    for(int i=0; i<len; i++)
    {
        int ch=s[i]-'a';
        if(!t[p][ch]) t[p][ch]=++tot;
        p=t[p][ch];
    }
    tag[p]=id;
}

void getfail()
{
    for(int i=0; i<26; i++)
        if(t[0][i]) fail[t[0][i]]=0, q.push(t[0][i]);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0; i<26; i++)
        {
            if(t[x][i])
            {
                fail[t[x][i]]=t[fail[x]][i];
                q.push(t[x][i]);
            }
            else t[x][i]=t[fail[x]][i];
        }
    }
}

void solve(char *s)
{
    int len=strlen(s), p=0;
    for(int i=0; i<len; i++)
    {
        int ch=s[i]-'a';
        p=t[p][ch];
        for(int j=p; j; j=fail[j])
            num[tag[j]]++;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%s", s2[i]);
        insert(s2[i], i);
    }
    getfail();
    scanf("%s", s1);
    solve(s1);
    //num[i] 为模式串 i 在文本串中出现次数
    return 0;
}