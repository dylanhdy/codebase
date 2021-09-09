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
#define MAXN 1005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
#define pii pair<int,int>
using namespace std;

int n, c[MAXN], f[MAXN];
LL ans;

stack<pii> sta;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &c[i]);
    for(int i=2; i<=n; i+=2) {
        LL tmp=c[i];
        for(int j=i-1; j>=1; j--) {
            if(!(j&1)) {
                tmp+=c[j];
                continue;
            }
            if(tmp>c[j]) tmp-=c[j];
            else if(tmp==c[j]) {
                f[i]=f[j-1]+1;
                break;
            } else {
                f[i]=1;
                break;
            }
        }
    }
    for(int i=1; i<=n; ++i) {
        if(i&1) sta.push(MP(c[i], i));
        else {
            while(!sta.empty()) {
                pii tmp=sta.top();
                if(tmp.first>c[i]) {
                    sta.top().first-=c[i];
                    ans+=c[i];
                    break;
                }
                ans+=tmp.first+f[tmp.second-1];
                //printf("%d %d %d %lld\n", i, tmp.first, tmp.second, ans);
                c[i]-=tmp.first;
                sta.pop();
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}