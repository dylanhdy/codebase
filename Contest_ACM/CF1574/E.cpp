#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <set>
#define LL long long
#define LD long double
#define MAXN 1000005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, k, pw[MAXN], tag[2], ctag, rtag, cnum, rnum;

map<int,int> mp[MAXN];
set<int> c[MAXN][2], r[MAXN][2];

void del(int x, int y)
{
    if(!mp[x].count(y)) return;
    int num=mp[x][y];
    if((x+y)&1) tag[num^1]--;
    else tag[num]--;
    mp[x].erase(y);
    if(y&1) {
        c[x][num].erase(y);
        if(!c[x][num].size()) {
            cnum--;
            if(c[x][num^1].size()) ctag--;
        }
    } else {
        c[x][num^1].erase(y);
        if(!c[x][num^1].size()) {
            cnum--;
            if(c[x][num].size()) ctag--;
        }
    }

    if(x&1) {
        r[y][num].erase(x);
        if(!r[y][num].size()) {
            rnum--;
            if(r[y][num^1].size()) rtag--;
        }
    } else {
        r[y][num^1].erase(x);
        if(!r[y][num^1].size()) {
            rnum--;
            if(r[y][num].size()) rtag--;
        }
    }
}

void add(int x, int y, int num)
{
    mp[x][y]=num;
    if((x+y)&1) tag[num^1]++;
    else tag[num]++;
    if(y&1) {
        if(!c[x][num].size()) {
            cnum++;
            if(c[x][num^1].size()) ctag++;
        }
        c[x][num].insert(y);
    } else {
        if(!c[x][num^1].size()) {
            cnum++;
            if(c[x][num].size()) ctag++;
        }
        c[x][num^1].insert(y);
    }

    if(x&1) {
        if(!r[y][num].size()) {
            rnum++;
            if(r[y][num^1].size()) rtag++;
        }
        r[y][num].insert(x);
    } else {
        if(!r[y][num^1].size()) {
            rnum++;
            if(r[y][num].size()) rtag++;
        }
        r[y][num^1].insert(x);
    }
}

int main()
{
    pw[0]=1;
    for(int i=1; i<=1e6; ++i) pw[i]=pw[i-1]*2%P;
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=k; ++i) {
        int x, y, op, ans=0;
        scanf("%d%d%d", &x, &y, &op);
        if(op==-1) {
            del(x, y);
        } else if(op==0) {
            del(x, y);
            add(x, y, 0);
        } else {
            del(x, y);
            add(x, y, 1);
        }
        if(!ctag) ans+=pw[n-cnum];
        if(!rtag) ans+=pw[m-rnum];
        ans-=(tag[0]==0)+(tag[1]==0);
        printf("%d\n", ans%P);
    }
    return 0;
}