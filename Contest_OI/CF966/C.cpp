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

int n, nxt[MAXN];
LL a[MAXN];

vector<int> vec[65];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%lld", &a[i]);
        for(int j=60; j>=0; --j)
            if((a[i]>>j)&1) {
                vec[j].PB(i);
                break;
            }
    }
    nxt[0]=-1;
    for(int i=60; i>=0; --i) {
        int pos=0;
        for(int j=0; j<vec[i].size(); ++j) {
            if(pos==-1) {
                printf("No\n");
                return 0;
            }
            nxt[vec[i][j]]=nxt[pos];
            nxt[pos]=vec[i][j];
            pos=nxt[vec[i][j]];
            while(pos!=-1 && ((a[pos]>>i)&1)==0) pos=nxt[pos];
        }
    }
    printf("Yes\n");
    for(int pos=nxt[0]; pos!=-1; pos=nxt[pos]) printf("%lld ", a[pos]);
    return 0;
}