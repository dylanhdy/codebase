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

int T, n, m, ans[MAXN];

struct A {
    int x, id;
    char dir[2];
} a[300005];

stack<pair<int, int> > sta[2];

bool CMP(A x, A y)
{
    return x.x<y.x;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i].x);
            a[i].id=i;
            ans[i]=-1;
        }
        for(int i=1; i<=n; ++i) scanf("%s", a[i].dir);
        sort(a+1, a+n+1, CMP);
        for(int i=1; i<=n; ++i) {
            int ch=a[i].x%2;
            if(a[i].dir[0]=='L') {
                if(sta[ch].empty()) sta[ch].push(MP(-a[i].x, a[i].id));
                else {
                    int x=sta[ch].top().first, id=sta[ch].top().second;
                    sta[ch].pop();
                    ans[id]=(a[i].x-x)/2;
                    ans[a[i].id]=(a[i].x-x)/2;
                }
            } else {
                sta[ch].push(MP(a[i].x, a[i].id));
            }
        }
        for(int i=0; i<=1; ++i) {
            pair<int, int> last=MP(-1, -1);
            while(!sta[i].empty()) {
                int x=sta[i].top().first, id=sta[i].top().second;
                sta[i].pop();
                if(last.second==-1) {
                    last=MP(2*m-x, id);
                } else {
                    ans[id]=(last.first-x)/2;
                    ans[last.second]=(last.first-x)/2;
                    last=MP(-1, -1);
                }
            }
        }
        for(int i=1; i<=n; ++i) printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}