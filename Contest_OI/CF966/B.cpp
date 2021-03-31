#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 300005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, x1, x2, pos[MAXN];

struct Server {int c, id;} a[MAXN];

bool CMP(Server x, Server y) {
    return x.c>y.c;
}

int find(int pos, int l, int r)
{
    while(l<r) {
        int mid1=l+(r-l)/3, mid2=r-(r-l)/3;
        LL val1=1LL*a[mid1].c*(mid1-pos);
        LL val2=1LL*a[mid2].c*(mid2-pos);
        if(val1<=val2) l=mid1+1;
        else r=mid2-1;

    }
    return l;
}

int main()
{
    scanf("%d%d%d", &n, &x1, &x2);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i].c);
        a[i].id=i;
    }
    sort(a+1, a+n+1, CMP);
    for(int i=1; i<n; ++i) pos[i]=find(i, i+1, n);
    //for(int i=1; i<n; ++i) dbg("%d %d %lld\n", i, pos[i], 1LL*a[pos[i]].c*(pos[i]-i));
    for(int i=1; i<n; ++i) {
        int temp=pos[i];
        if(1LL*i*a[i].c>=x1 && 1LL*(temp-i)*a[temp].c>=x2) {
            printf("Yes\n%d %d\n", i, temp-i);
            for(int j=1; j<=i; ++j) printf("%d ", a[j].id);
            printf("\n");
            for(int j=i+1; j<=temp; ++j) printf("%d ", a[j].id);
            printf("\n");
            return 0;
        }
    }
    for(int i=1; i<=n; ++i) {
        int temp=pos[i+1];
        if(1LL*i*a[i].c>=x2 && 1LL*(temp-i)*a[temp].c>=x1) {
            printf("Yes\n%d %d\n", temp-i, i);
            for(int j=i+1; j<=temp; ++j) printf("%d ", a[j].id);
            printf("\n");
            for(int j=1; j<=i; ++j) printf("%d ", a[j].id);
            printf("\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}