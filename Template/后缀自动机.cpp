#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 1000005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int len, tot=1, last=1, b[MAXN], id[MAXN*2];
char s[MAXN];

struct State {int len, fa, val, nxt[26];} a[MAXN*2];

void insert(int ch)
{
    /* 广义后缀自动机
    if(a[last].nxt[ch]) {
		int p=last, x=a[p].nxt[ch];
		if(a[p].len+1==a[x].len) last=x;
		else {
			int y=++tot;
			memcpy(a[y].nxt, a[x].nxt, sizeof(a[y].nxt));
			a[y].len=a[p].len+1; a[y].fa=a[x].fa;
			for(; p && a[p].nxt[ch]==x; p=a[p].fa) a[p].nxt[ch]=y;
			a[x].fa=y; last=y;
		}
		return;
	}
    */
    int cur=++tot, p=last;
    a[cur].len=a[last].len+1;
    a[cur].val=1;
    for(; p && !a[p].nxt[ch]; p=a[p].fa) a[p].nxt[ch]=cur;
    if(!p) a[cur].fa=1;
    else {
        int x=a[p].nxt[ch];
        if(a[p].len+1==a[x].len) a[cur].fa=x;
        else {
            int y=++tot;
            memcpy(a[y].nxt, a[x].nxt, sizeof(a[y].nxt));
            a[y].len=a[p].len+1; a[y].fa=a[x].fa;
            for(; p && a[p].nxt[ch]==x; p=a[p].fa) a[p].nxt[ch]=y;
            a[x].fa=a[cur].fa=y;
        }
    }
    last=cur;
}

void topsort()
{
    for(int i=1; i<=tot; ++i) b[a[i].len]++;
    for(int i=1; i<=len; ++i) b[i]+=b[i-1];
    for(int i=1; i<=tot; ++i) id[b[a[i].len]--]=i;
    for(int i=tot; i>=2; --i) {
        int x=id[i];
        a[a[x].fa].val+=a[x].val;
    }
}

int main()
{
    scanf("%s", s+1);
    len=strlen(s+1);
    for(int i=1; i<=len; ++i) insert(s[i]-'a');
    //a[i].val 代表节点 i 对应字符串出现次数
    return 0;
}