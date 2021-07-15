#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 1e18
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, pos[5], ansp[5], t[MAXN];
LL ans;
char s[MAXN];

vector<int> vec[5];

void add(int x)
{
    for(; x<=n; x+=(x&-x)) t[x]++;
}

int ask(int x)
{
    int num=0;
    for(; x; x-=(x&-x)) num+=t[x];
    return num;
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        ans=-1;
        for(int i=1; i<=4; ++i) vec[i].clear();
        scanf("%s", s+1);
        n=strlen(s+1);
        for(int i=1; i<=n; ++i) {
            if(s[i]=='A') vec[1].PB(i);
            if(s[i]=='N') vec[2].PB(i);
            if(s[i]=='T') vec[3].PB(i);
            if(s[i]=='O') vec[4].PB(i);
        }
        for(int i=1; i<=4; ++i) pos[i]=i;
        do {
            LL cnt=0;
            for(int i=1; i<=n; ++i) t[i]=0;
            for(int i=1; i<=4; ++i) {
                int p=pos[i];
                for(int j=0; j<vec[p].size(); ++j) {
                    cnt+=vec[p][j]-ask(vec[p][j])-1;
                    add(vec[p][j]);
                }
            }
            if(cnt>ans) {
                ans=cnt;
                for(int i=1; i<=4; ++i) ansp[i]=pos[i];
            }
        } while(next_permutation(pos+1, pos+5));
        //printf("%lld??\n", ans);
        for(int i=1; i<=4; ++i)
            for(int j=0; j<vec[ansp[i]].size(); ++j) {
                if(ansp[i]==1) printf("A");
                if(ansp[i]==2) printf("N");
                if(ansp[i]==3) printf("T");
                if(ansp[i]==4) printf("O");
            }
        printf("\n");
    }
    return 0;
} 