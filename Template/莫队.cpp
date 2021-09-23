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
#define MAXN 200005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, q, ans[MAXN], bol[MAXN];

struct Q {int l, r, id;} a[MAXN]; 

bool CMP(Q x, Q y)
{
    if(bol[x.l]==bol[y.l]) {
        if(bol[x.l]&1) return x.r<y.r;
        else return x.r>y.r;
    }
    return x.l<y.l;
}

int main()
{   
    scanf("%d", &n);
    int l=1, r=0, siz=sqrt(n);
    for(int i=1; i<=n; ++i) bol[i]=(i-1)/siz+1;
    scanf("%d",  &q);
    for(int i=1; i<=q; ++i) {
        scanf("%d%d", &a[i].l, &a[i].r);
        a[i].id=i;
    }
    sort(a+1, a+q+1, CMP);
    for(int i=1; i<=q; ++i) {
        while(r<a[i].r) {
            r++;
            //update(r, 1);
        }
        while(r>a[i].r) {
            //update(r, -1);
            r--;
        }
        while(l<a[i].l) {
            //update(l, -1);
            l++;
        }
        while(l>a[i].l) {
            l--;
            //update(l, 1);
        }
        //ans[a[i].id]=query();
    }
    for(int i=1; i<=q; ++i) printf("%d\n", ans[i]);
    return 0;
}