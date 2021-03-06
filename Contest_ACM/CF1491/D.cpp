#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int q, u, v, l[40], r[40];
vector<int> p1, p2;

bool check() {
    for(int i=0; i<p1.size(); ++i) {
        if(i==0) r[i]=l[i]=0;
        else r[i]=l[i]=l[i-1]+1;
        while(l[i]<p2.size() && p2[l[i]]>p1[i]) l[i]++;
        if(l[i]==p2.size()) return false;
        if(i>0 && l[i]>r[i-1]+1) return false;
        if(p2[l[i]]<p1[i]) r[i]=p2.size()-1;
        else if(i>0 && r[i-1]>=r[i]) r[i]=p2.size()-1;
        //printf("%d %d\n", l[i], r[i]);
    }
    return true;
}

int main() {
    scanf("%d", &q);
    while(q--) {
        p1.clear(); p2.clear();
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        scanf("%d%d", &u, &v);
        if(u>v) {
            printf("NO\n");
            continue;
        }
        for(int i=29; i>=0; --i)
            if((v>>i)&1) p1.PB(i);
        for(int i=29; i>=0; --i)
            if((u>>i)&1) p2.PB(i);
        if(check()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}