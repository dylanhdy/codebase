#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 105
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, m, w, h, r[MAXN], p[MAXN];

vector<pair<int, int> > vec;

bool dfs(int x)
{
    int pos=1;
    for(int i=2; i<=h; ++i)
        if(r[i]<r[pos]) pos=i;
    if(r[pos]==w) return true;
    if(x==n) return false;
    if(dfs(x+1)) return true;
    int wx=vec[p[x]].first, hx=vec[p[x]].second;
    int flag=(pos+hx-1<=h && r[pos]+wx<=w);
    for(int i=pos; i<=pos+hx-1; ++i)
        if(r[i]!=r[pos]) flag=0;
    if(flag) {
        for(int i=pos; i<=pos+hx-1; ++i) r[i]+=wx;
        if(dfs(x+1)) return true;
        for(int i=pos; i<=pos+hx-1; ++i) r[i]-=wx;
    }
    swap(wx, hx);
    flag=(pos+hx-1<=h && r[pos]+wx<=w);
    for(int i=pos; i<=pos+hx-1; ++i)
        if(r[i]!=r[pos]) flag=0;
    if(flag) {
        for(int i=pos; i<=pos+hx-1; ++i) r[i]+=wx;
        if(dfs(x+1)) return true;
        for(int i=pos; i<=pos+hx-1; ++i) r[i]-=wx;
    }
    return false;
}

int main()
{
    scanf("%d%d%d", &w, &h, &m);
    for(int i=1; i<=m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        for(int j=1; j<=a; ++j) vec.PB(MP(b, c));
    }
    n=vec.size();
    for(int i=0; i<n; ++i) p[i]=i;
    do {
        if(dfs(0)) {
            printf("yes\n");
            return 0;
        }
    } while(next_permutation(p, p+n));
    printf("no\n");
    return 0;
}
/*
5 5
4
2 3 1
1 2 3
2 4 1
1 5 1
*/