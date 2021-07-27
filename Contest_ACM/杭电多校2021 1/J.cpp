#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#define MAXN 100010
#define mid ((l+r)>>1)
#define LL long long
using namespace std;

int T, n, m, l, r, siz, bol[MAXN], ans[MAXN], a[MAXN], num[MAXN], sum[MAXN];

struct Q {int l, r, x, y, id;} q[MAXN]; 

bool CMP(Q x, Q y)
{
	if(bol[x.l]==bol[y.l]) {
		if(bol[x.l]&1) return x.r<y.r;
		else return x.r>y.r;
	}
	return x.l<y.l;
}

int ask(int x, int y)
{
    int ans=0;
    if(x/siz==y/siz) {
        for(int i=x; i<=y; ++i) ans+=(num[i]>0);
        return ans;
    }
    for(int i=x; i<(x/siz+1)*siz; ++i) ans+=(num[i]>0);
    for(int i=y/siz*siz; i<=y; ++i) ans+=(num[i]>0);
    for(int i=x/siz+1; i<y/siz; ++i) ans+=sum[i];
    return ans;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        l=1, r=0, siz=300; 
        for(int i=0; i<=1e5; ++i) num[i]=0;
        for(int i=0; i<=500; ++i) sum[i]=0;
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            bol[i]=(i-1)/siz+1;
        }
        for(int i=1; i<=m; ++i) {
            scanf("%d%d%d%d", &q[i].l, &q[i].x, &q[i].r, &q[i].y);
            q[i].id=i;
        }
        sort(q+1, q+m+1, CMP);
        for(int i=1; i<=m; ++i) {
            while(r<q[i].r) {
                r++;
                if(!num[a[r]]) sum[a[r]/siz]++;
                num[a[r]]++;
            }
            while(r>q[i].r) {
                num[a[r]]--;
                if(!num[a[r]]) sum[a[r]/siz]--;
                r--;
            }
            while(l<q[i].l) {
                num[a[l]]--;
                if(!num[a[l]]) sum[a[l]/siz]--;
                l++;
            }
            while(l>q[i].l) {
                l--;
                if(!num[a[l]]) sum[a[l]/siz]++;
                num[a[l]]++;
            }
            ans[q[i].id]=ask(q[i].x, q[i].y);
        }
        for(int i=1; i<=m; ++i) printf("%d\n", ans[i]);
    }
}