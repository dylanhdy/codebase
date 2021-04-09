#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, f[MAXN], nxt[MAXN], a[MAXN];

vector<int> ans;

int find(int x)
{
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        ans.clear();
        for(int i=1; i<n; ++i) nxt[i]=i+1;
        nxt[n]=1;
        int flag=0;
        for(int i=1; i<=n; ++i) {
            if(__gcd(a[i], a[nxt[i]])>1) f[i]=nxt[i];
            else f[i]=i, flag=1;
        }
        if(!flag) {
            printf("0\n");
            continue;
        }
        int pos=find(1);
        while(true) {
            if(nxt[pos]==pos) {
                if(a[pos]==1) ans.PB(pos);
                break;
            }
            ans.PB(nxt[pos]);
            nxt[pos]=nxt[nxt[pos]];
            if(__gcd(a[pos], a[nxt[pos]])>1) {
                if(find(nxt[pos])==find(pos)) break;
                f[pos]=nxt[pos];
            }
            pos=find(nxt[pos]);
        }
        printf("%d ", ans.size());
        for(int i=0; i<ans.size(); ++i) printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}