#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 150005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
#define mid ((l+r)>>1)
#define ls (root<<1)
#define rs (root<<1|1)
using namespace std;

int n, m, nums, nume, v, q;
vector<int> s, e;
vector<int>::iterator it;

int main()
{
    scanf("%d%d%d%d%d", &n, &m, &nums, &nume, &v);
    for(int i=1; i<=nums; ++i) {
        int temp;
        scanf("%d", &temp);
        s.PB(temp);
    }
    for(int i=1; i<=nume; ++i) {
        int temp;
        scanf("%d", &temp);
        e.PB(temp);
    }
    scanf("%d", &q);
    while(q--) {
        int a1, a2, b1, b2, ans=INF;
        scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
        if(a1>a2) swap(a1, a2);
        if(b1>b2) swap(b1, b2);
        if(a1==a2) {
            printf("%d\n", b2-b1);
            continue;
        }
        it=lower_bound(s.begin(), s.end(), b1);
        if(it!=s.end() && *it<=b2) ans=min(ans, b2-b1+a2-a1);
        else {
            if(it!=s.end()) ans=min(ans, (*it)*2-b2-b1+a2-a1);
            if(it!=s.begin()) {
                it--;
                ans=min(ans, b2+b1-(*it)*2+a2-a1);
            }
        }
        it=lower_bound(e.begin(), e.end(), b1);
        if(it!=e.end() && *it<=b2) ans=min(ans, b2-b1+(a2-a1+v-1)/v);
        else {
            if(it!=e.end()) ans=min(ans, (*it)*2-b2-b1+(a2-a1+v-1)/v);
            if(it!=e.begin()) {
                it--;
                ans=min(ans, b2+b1-(*it)*2+(a2-a1+v-1)/v);
            }
        }
        printf("%d\n", ans);
    }
}