#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P 998244353
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int t, n, k, ans, a[MAXN], b[MAXN], pre[MAXN], nxt[MAXN], pos[MAXN];
char s[MAXN];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ans=1;
        scanf("%d%d", &n, &k);
        pos[0]=INF;
        for(int i=1; i<=n; ++i) pre[i]=nxt[i]=pos[i]=0;
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        for(int i=2; i<=n; ++i) pre[a[i]]=a[i-1];
        for(int i=1; i<n; ++i) nxt[a[i]]=a[i+1];
        for(int i=1; i<=k; ++i)
        {
            scanf("%d", &b[i]);
            pos[b[i]]=i;
        }
        for(int i=1; i<=k; ++i)
        {
            int temp=0;
            if(pos[pre[b[i]]]<pos[b[i]]) temp++;
            if(pos[nxt[b[i]]]<pos[b[i]]) temp++;
            ans=ans*temp%P;
            //printf("%d %d\n", i, temp);
        }
        printf("%d\n", ans);
    }
    return 0;
}