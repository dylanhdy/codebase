#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <array>
#define LL long long
#define LD long double
#define MAXN 250005
#define MAXM 4500005
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, tot=1, a[MAXN], b[MAXN], t[MAXM][2], g[MAXM][2];
vector<array<int,2>> fx[MAXM][2], fy[MAXM][2];
LL ans;

LL query(int x, int y)
{
    int p=1; LL num=0;
    for(int i=17; i>=0; --i) {
        int cx=((x>>i)&1), cy=((y>>i)&1);
        int tp=t[p][cx^cy^1];
        if(tp) {
            for(int j=i; j>=0; --j) {
                num+=(LL)fx[tp][cx][j][1^((x>>j)&1)]<<j;
                num+=(LL)fy[tp][cy][j][1^((y>>j)&1)]<<j;
            }
        }
        if(!t[p][cx^cy]) break;
        p=t[p][cx^cy];
        num+=(LL)g[p][cx^1]<<i;
    }
    return num;
}

void insert(int x, int y)
{
    int p=1;
    for(int i=17; i>=0; --i) {
        int cx=((x>>i)&1), cy=((y>>i)&1);
        if(!t[p][cx^cy]) {
            t[p][cx^cy]=++tot;
            fx[tot][0].resize(i+1), fx[tot][1].resize(i+1);
            fy[tot][0].resize(i+1), fy[tot][1].resize(i+1);
        }
        p=t[p][cx^cy];
        //printf("%d %d %d??\n", i, p, cx^cy);
        g[p][cx]++;
        for(int j=i; j>=0; --j) {
            fx[p][cx][j][(x>>j)&1]++;
            fy[p][cy][j][(y>>j)&1]++;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1; i<=n; ++i) scanf("%d", &b[i]);
    for(int i=1; i<=n; ++i) {
        ans+=query(a[i], b[i]);
        //printf("%lld??\n", query(a[i], b[i]));
        insert(a[i], b[i]);
    }
    printf("%lld\n", ans);
    return 0;
}