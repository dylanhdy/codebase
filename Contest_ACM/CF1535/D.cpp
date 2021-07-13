#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 500005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
#define ls (rt<<1|1)
#define rs (rt<<1)
using namespace std;

int n, k, q, t[MAXN*4];
char s[MAXN];

void build(int rt)
{
    if(rt>=n) {
        t[rt]=1;
        return;
    }
    build(ls);
    build(rs);
    if(s[n-rt]=='0') t[rt]=t[ls];
    if(s[n-rt]=='1') t[rt]=t[rs];
    if(s[n-rt]=='?') t[rt]=t[ls]+t[rs];
}

void update(int rt)
{
    if(s[n-rt]=='0') t[rt]=t[ls];
    if(s[n-rt]=='1') t[rt]=t[rs];
    if(s[n-rt]=='?') t[rt]=t[ls]+t[rs];
    if(rt>1) update(rt>>1);
}

int main()
{
    scanf("%d", &k);
    n=(1<<k);
    scanf("%s", s+1);
    build(1);
    scanf("%d", &q);
    while(q--) {
        int x;
        char ch[2];
        scanf("%d%s", &x, ch);
        s[x]=ch[0];
        update(n-x);
        printf("%d\n", t[1]);
    }
    return 0;
}