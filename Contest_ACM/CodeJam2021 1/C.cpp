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
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, q, ans1, cnt, sco[5];
char ans[1000], s[5][1000];

int main()
{
    scanf("%d", &T);
    for(int qwq=1; qwq<=T; ++qwq) {
        ans1=0, cnt=0;
        scanf("%d%d", &n, &q);
        for(int i=1; i<=n; ++i) scanf("%s%d", s[i]+1, &sco[i]);
        if(n==1) {
            for(int i=1; i<=q; ++i) s[2][i]=s[1][i];
            sco[2]=sco[1];
        }
        for(int i=1; i<=q; ++i)
            if(s[1][i]!=s[2][i]) cnt++;
        int val1=(sco[1]+sco[2]-cnt)/2, val2=(q-cnt);
        if(val1*2>=val2) {
            ans1+=val1;
            for(int i=1; i<=q; ++i)
                if(s[1][i]==s[2][i]) ans[i]=s[1][i];
        } else {
            ans1+=val2-val1;
            for(int i=1; i<=q; ++i)
                if(s[1][i]==s[2][i]) ans[i]=(s[1][i]=='T'?'F':'T');
        }
        if(sco[1]>sco[2]) {
            ans1+=sco[1]-val1;
            for(int i=1; i<=q; ++i)
                if(s[1][i]!=s[2][i]) ans[i]=s[1][i];
        } else {
            ans1+=sco[2]-val1;
            for(int i=1; i<=q; ++i)
                if(s[1][i]!=s[2][i]) ans[i]=s[2][i];
        }
        printf("Case #%d: ", qwq);
        for(int i=1; i<=q; ++i) printf("%c", ans[i]);
        printf(" %d/1\n", ans1);
    }
    return 0;
}